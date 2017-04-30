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
  char fn_part[100];
  char fn[100];
  for(i=0;i<100000;i++) {
    sprintf(fn_part, "/tmp/db/%d.json.part", i);
    sprintf(fn, "/tmp/db/%d.json", i);
    // printf("%s\n", fn_part);
    fd = open(fn_part, O_WRONLY|O_CREAT);
    write(fd, "{ \"test\": 1 }\n", 14);
    close(fd);
    rename(fn_part, fn);
  }
  
  return(0);
}
