#include <dirent.h>
#include <string.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <strings.h>
void compare_directories(char * archiveA, char * archiveB)
{
  DIR * dirA = opendir(archiveA);
  DIR * dirB = opendir(archiveB);
  struct dirent * entryA = readdir(dirA);
  struct dirent * entryB = readdir(dirB);
  while (entryA != NULL && entryB != NULL)
  {
    if (strcmp(entryA->d_name, entryB->d_name) == 0)
    {
      if (entryA->d_type ==   )
      {
        char * newArchiveA = malloc(sizeof(char) * (strlen(archiveA) + strlen(entryA->d_name) + 2));
        char * newArchiveB = malloc(sizeof(char) * (strlen(archiveB) + strlen(entryB->d_name) + 2));
        strcpy(newArchiveA, archiveA);
        strcat(newArchiveA, "/");
        strcat(newArchiveA, entryA->d_name);
        strcpy(newArchiveB, archiveB);
        strcat(newArchiveB, "/");
        strcat(newArchiveB, entryB->d_name);
        compare_directories(newArchiveA, newArchiveB);
      }
      else
      {
        int fdA = open(archiveA, O_RDONLY);
        int fdB = open(archiveB, O_RDONLY);
        char * bufferA = malloc(sizeof(char) * 1024);
        char * bufferB = malloc(sizeof(char) * 1024);
        int readA = read(fdA, bufferA, 1024);
        int readB = read(fdB, bufferB, 1024);
        while (readA > 0 && readB > 0)
        {
          if (strcmp(bufferA, bufferB) != 0)
          {
            printf("%s %s\n", archiveA, archiveB);
            break;
          }
          readA = read(fdA, bufferA, 1024);
          readB = read(fdB, bufferB, 1024);
        }
        free(bufferA);
        free(bufferB);
        close(fdA);
        close(fdB);
      }
    }
    entryA = readdir(dirA);
    entryB = readdir(dirB);
  }
  closedir(dirA);
  closedir(dirB);
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
// Language: c
/*
void comp_dir(char * archivoA, char * archivoB){
  DIR*d = opendir();
  
  struct stat buf;
  stat(archivoA, &buf);
  
  
  return;
}
int main(int argc, char *argv[]) {
  if (argc!=3) {
    fprintf(stderr, "uso: %s <arch|dir> <arch|dir>\n", argv[0]);
    exit(2);
  }
  return 0;
}
*/