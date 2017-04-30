/*
 * This program displays the names of all files in the current directory.
 */

#include <dirent.h> 
#include <stdio.h> 
#include <sys/stat.h> 
#include <fcntl.h>

int main(void)
{
  DIR           *d;
  struct dirent *dir;
  int i, fd;
  char fn[100];
  for(i=0;i<100000;i++) {
    // we are taking advantage of atomic block write that is provided by storage subsys already
    sprintf(fn, "/tmp/db/%d.json", i);
    fd = open(fn, O_WRONLY|O_CREAT);
    write(fd, "{ \"test\": 1 }\n", 14);
    close(fd);
  }
  
  return(0);
}
