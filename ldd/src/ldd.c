#define __GNU_SOURCE  
#include "../includes/ldd.h"
#include <elf.h>
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>
#include <unistd.h>
#include <limits.h>
#include <dlfcn.h>

int main(int argc, char* argv[]) { 
  Elf64_Ehdr ehdr;
  Elf64_Phdr *phdr;
  const char* file_name = argv[1];
  char buff[PATH_MAX]; 

  /*
   * A file descriptor 
   *
   * The return value of open() is a file descriptor, a small,
   * nonnegative integer that is an index to an entry in the process's 
   * table of open file descriptggors.
   */
  int fd = open(file_name, O_RDONLY);
  if(fd < 0) {
    close(fd);
    perror("File descriptor error");
  }  

  // read from a file descriptor 
  ssize_t rfd = read(fd, &ehdr, sizeof(ehdr));
  if(rfd != sizeof(ehdr)) {
    close(fd);
    perror("Incorrect size of file descriptor");
  }

  /*
   * This member holds the number of entries in the program header table. 
   * If a file has no program header, e_phnum holds the value zero
   */
  if(ehdr.e_phnum == 0 || ehdr.e_phentsize == 0) {
    close(fd);
    perror("Incomplete file header");
  }

  pread(fd, phdr, ehdr.e_phnum * sizeof(Elf64_Phdr), ehdr.e_phoff);

  realpath(file_name, buff);

  printf("path: %s\n", buff);

  /*
   * When LD_TRACE_LOADED_OBJECTS is set to 1 or true, 
   * running executable file will show shared objects needed instead of running it, 
   * so you even not needldd to check executable file.
   */
  setenv("LD_TRACE_LOADED_OBJECTS", "true", 1);

  // void* dlhandle = dlopen(buff, RTLD_TRACE);
  
  execl(buff, file_name, (char*)NULL);

  free(phdr);

}
