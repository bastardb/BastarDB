/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <fcntl.h>
#include <string.h>

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  int i, fd;
  char fn[100];
  char data[4096];
  for(i=0;i<100000;i++) {
    // we are taking advantage of atomic block write that is provided by storage subsys already
    memset(data, ' ', sizeof(data));
    sprintf(data, "{ \"test\": 1 }\n");
    fd = open("/tmp/seqential", O_APPEND|O_RDWR|O_CREAT);
    write(fd, data, 4096);
    close(fd);
  }
  
  return(0);
}
