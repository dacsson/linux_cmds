#include "../includes/wget.h"

// json serializer
/*
char* to_json(char* header, size_t size) {
  char json[size] = "{\n\"";
  // after the keyword is read close it with syntax { "\n:" } => now the state is reading value 
  char* key_cls = (char*)malloc(sizeof(char) * 4);
  *key_cls = "\"\":";
  // after the value is read close it w { ",\n" }
  char* value_cls = (char*)malloc(sizeof(char) * 4);
  *value_cls = "\",\n\"";

  for(int i = 0; i < size; i++) {
    char ch = header[i];
    strncat(json, &ch, 1);
    if(ch == ':') {
      strncat(json, &key_cls, sizeof(key_cls));
    }
    if(ch == '\n') {
      strncat(json, &value_cls, sizeof(value_cls));
    }
  }
  
  return json;
}
*/

void wget(const char* url) {
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
  
  char responce_header[4096];
  int bytes_recv = recv(fd, responce_header, sizeof(responce_header), 0);
  if(bytes_recv == -1) {
    perror("No bytes received");
    exit(-1);
  }

  responce_header[bytes_recv] = '\0';

  close(fd);

  // printf("Received %d bytes => %s\n", bytes_recv, responce_header);

  printf("json: %s\n", to_json(responce_header, sizeof(responce_header)));
}

int main(int argc, char* argv[]) { 
  // char* responce = wget(argv[1]);
  wget(argv[1]);
  // printf("%s\n", responce);
}
