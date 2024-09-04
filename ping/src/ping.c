/*
 * @OLD VERISON
 * NOT IMPLEMENTED PROPERLY YET 
 */

#include "../includes/ping.h"
#include <bits/types/struct_iovec.h>
#include <sys/socket.h>

struct icmp_echo {
  uint8_t type;
  uint8_t code;
  uint16_t checksum;
  pid_t id;
  uint16_t data;
  // data 
};

void ping() {
  errno = 1;
  char ip[INET_ADDRSTRLEN];
  struct addrinfo hints;
  struct addrinfo *result, *rp;
  int fd;

  memset(&hints, 0, sizeof(hints));
  hints.ai_family = AF_INET;    /* Allow IPv4 or IPv6 */
  hints.ai_socktype = SOCK_STREAM; /* Datagram socket */
  
  int status = getaddrinfo(url, "http", &hints, &result);
  printf("Status: %d\n", status);
  if(status != 0 ) {
    
    // perror("Adress info retieving error");
    fprintf(stderr, "getaddrinfo: %s\n", gai_strerror(status));
    exit(-1);
  }

  for(rp = result; rp != NULL; rp = rp->ai_next) {
    void* addr;
    if(rp->ai_family == AF_INET) {
      struct sockaddr_in* ipv4 = (struct sockaddr_in*)rp->ai_addr;
      addr = &(ipv4->sin_addr); 
      
      fd = socket(rp->ai_family, rp->ai_socktype, rp->ai_protocol);
      if(fd == -1) {
        perror("failed to create socket");
      }
      
      if(connect(fd, rp->ai_addr, rp->ai_addrlen) == -1) {
        perror("Failed to connect");
        close(fd);
      } 
      else {
        inet_ntop(rp->ai_family, addr, ip, sizeof(ip));
        printf("Connected to %s\n", ip);
        break;
      }
      // check if entry is valid 

      // printf("Name: %s\n,", ip);
    } 
  }
  
  if(rp == NULL) {
    printf("Failed to connect");
    exit(-1);
  }

  freeaddrinfo(result);
 
  char request[] = "GET / HTTP/1.1\r\nHost: www.google.com\r\n\r\n";
  int bytes_send = send(fd, request, sizeof(request), MSG_CONFIRM);
  if(bytes_send == -1) {
    perror("No bytes send");
    exit(-1);
  }
 
  printf("%d bytes send\n", bytes_send);

  char buff[2048];
  int bytes_recv = recv(fd, buff, sizeof(buff), 0);
  if(bytes_recv == -1) {
    perror("No bytes received");
    exit(-1);
  }

  buff[bytes_recv] = '\0';

  close(fd);

  printf("Received %d bytes => %s\n", bytes_recv, buff);

}

int icmp_send(struct sockaddr_in serv_addr, int sockfd, uint16_t _data)
{
  char buff[512];
  struct icmp_echo* data = malloc(sizeof *data);
  data->type = 8;
  data->code = 0;
  data->id = getpid();
  data->checksum = 0;
  data->data = _data;

  struct iovec iov;

  iov.iov_base = data;
  iov.iov_len = sizeof(*data);

  struct msghdr msg;
  bzero(&msg, sizeof(msg));
  msg.msg_name = (void*)&serv_addr;
  msg.msg_namelen = sizeof(serv_addr);
  msg.msg_iov = &iov;
  msg.msg_iovlen = 1;
  msg.msg_flags = 0;
  msg.msg_control = buff;
  msg.msg_controllen = sizeof(buff);

  printf("Created icmp packet with type - %d | code - %d | size - %lu \n", data->type, data->code, sizeof(*data));
  // int ch_sent = sendto(sockfd, data, sizeof(*data), 0, (const struct sockaddr*)&serv_addr, sizeof(serv_addr));
  int ch_sent = sendmsg(sockfd, &msg, 0);
  printf("Number of bytes sent: %d\n",ch_sent);

  /*
    If successful, 
    sendto() returns the number of characters sent. 
    A value of 0 or greater indicates the number of bytes sent
  
    then maybe do a check like: 
      if ch_sent == sizeof(*data) ??
  */
  if(ch_sent < 0) {
    errno = ch_sent;
    perror("Sending error");
    return errno;
  }

  return ch_sent;
}

int icmp_receive(int sockfd, struct sockaddr_in serv_addr)
{
  char buff[256];
  struct sockaddr_in addr;
  struct msghdr msg;
  struct iovec iov;
  unsigned char* packet;
  struct icmp_echo* icp = (struct icmp_echo*)packet;
  int packetlen = 256;

  iov.iov_base = icp;
  iov.iov_len = sizeof(*icp);

  bzero(&msg, sizeof(msg));
  msg.msg_name = (void*)&addr;
  msg.msg_namelen = sizeof(addr);
  msg.msg_iov = &iov;
  msg.msg_iovlen = 1;
  msg.msg_flags = 0;
  msg.msg_control = buff;
  msg.msg_controllen = sizeof(buff);

  unsigned int addr_len = sizeof(addr);
  printf("Waiting for reply on socket %d | addr len %d\n",sockfd ,addr_len);
  int status = recvmsg(sockfd, &msg, MSG_WAITFORONE);
  if(status < 0) {
    perror("Receive msg error");
    exit(EXIT_FAILURE);
  }
  printf("Receive status %d\n", status);
  // uint8_t* buf = msg.msg_iov->iov_base;
  // struct icmp_echo* icp_repl = (struct icmp_echo*) buf;

  // struct sockaddr_in* rec_addr = msg.msg_name;
  // printf("Received %d bytes | %d |\n", status, icp_repl ->data);

  // --------------------------------
  // int status = recvfrom(sockfd, buff, sizeof(buff), 0, (struct sockaddr *)&addr, &addr_len);
  // printf("recvfrom() status %d", status);
  // if(status == -1) {
  //   return -1;
  // }

  // struct icmp_echo *icmp = (struct icmp_echo*)(buff + 20);
  // if(icmp->type != 0 || icmp->code != 0) {
  //   printf("ICMP type or code is not zero: %d %d", icmp->type, icmp->code);
  //   return -1;
  // }

  // printf("%s seq=%d id=%d", inet_ntoa(serv_addr.sin_addr), ntohs(icmp->data), ntohs(icmp->id));

  return 0;
}

int main(int argc, char* argv[]) { 
  int sockfd, portno;
  ssize_t rc;
  struct sockaddr_in serv_addr;
  struct hostent *server;
  char buffer[256];
  errno = 0;

  sockfd = socket(AF_INET, SOCK_RAW, IPPROTO_ICMP);
  if(sockfd == -1) {
    perror("Socket error");
    close(sockfd);
    return 1;
  }

  serv_addr.sin_family = AF_INET;
  serv_addr.sin_port = 0;

  int addr_valid_status = inet_aton("64.233.162.138", &serv_addr.sin_addr);
  if(addr_valid_status == 0) {
    printf("Invalid address");
    exit(EXIT_FAILURE);
  }

  // char str[INET_ADDRSTRLEN];
  // unsigned char buf[sizeof(struct in_addr)];
  // inet_ntop(AF_INET, buf, str, INET_ADDRSTRLEN);

  printf("Trying to connect to %s\n", inet_ntoa(serv_addr.sin_addr));

  int data = 1;
  int req_status = icmp_send(serv_addr, sockfd, data);
  // if(errno != 0) {
  //   perror("Send error");
  // } 

  // data++;
  // sleep(1);
  int res_status = icmp_receive(sockfd, serv_addr);
  if(res_status == -1) {
    perror("Receive error");
  }

  return 0;

  // struct timeval tv;
  // tv.tv_sec = 0;
  // tv.tv_usec = 100000;
  // int ret = setsockopt(sockfd, SOL_SOCKET, SO_RCVTIMEO, &tv, sizeof(tv));
  // if(ret == -1) {
  //   close(sockfd);
  //   perror("Spcket option error");
  //   return 1;
  // }

  // send req 
  // ret = send()

  // receive
  // ret = receive()

}
