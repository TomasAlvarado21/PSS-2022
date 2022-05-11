#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIZELIN 10

int main(int argc, char *argv[]) {
  FILE *f = fopen("noms.txt","r+");
  //char *buff_inicio = malloc(10);
  char *buff_actual = malloc(10);
  char *buff_sgte = malloc(10);
  //fread(buff_inicio, 10, 1, f);
  //int inicio = argv[0];
  int i = 0;
  while (i <= argc){
    if (i == argc){
      fseek(f, argv[0]*10, SEEK_SET);
      fwrite(buff_sgte, 10, 1, f);
    }
    fseek(f, argv[i]*10, SEEK_SET);
    fread(buff_actual, 10, 1, f);
    fseek(f, argv[i+1]*10, SEEK_SET);
    fread(buff_sgte, 10, 1, f);
    fwrite(buff_actual, 10, 1, f);
    strcpy(buff_actual, buff_sgte);
    i++;
  }
}
