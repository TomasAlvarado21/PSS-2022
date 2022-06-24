#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>


int compare_directory(char * argv1, char * argv2){
  
  char *fn1= argv1;
  char *fn2= argv2;
  struct stat stat1, stat2;
  int rc1= stat(fn1, &stat1);
  if (rc1<0) {
    perror(fn1);
    exit(2);
  }
  int rc2= stat(fn2, &stat2);
  if (rc2<0) {
    perror(fn2);
    exit(3);
  }
  if (stat1.st_dev==stat2.st_dev && stat1.st_ino==stat2.st_ino)
  printf("Es subconjunto \n");
  else
  printf("son archivos distintos\n");
  return 0;
}

int main(int argc, char * argv[])
{
  if (argc != 3)
  {
    printf("Usage: %s <archiveA> <archiveB>\n", argv[0]);
    return 1;
  }
  compare_directories(argv[1], argv[2]);
  return 0;
}
