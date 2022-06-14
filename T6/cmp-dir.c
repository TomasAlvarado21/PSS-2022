#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>

void comp_dir(char * archivoA, char * archivoB){
  return;
}
int main(int argc, char *argv[]) {
  if (argc!=3) {
    fprintf(stderr, "uso: %s <arch|dir> <arch|dir>\n", argv[0]);
    exit(2);
  }
  ... complete aca la funcion main ...
  return 0;
}
