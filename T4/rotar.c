#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define SIZELIN 10

int main(int argc, char *argv[]) {
  if (argc<3) {
    fprintf(stderr, "Uso: %s <archivo> <l1> <l2> <l3> ...\n", argv[0]);
    exit(1);
  }

  char *nom= argv[1];  // El nombre del archivo
  // l1 es atoi(argv[2]), l2 es atoi(argv[3]), ..., ln es atoi(argv[argc-1])
  if (argc == 3){
    return 0;
  }
  FILE *f = fopen(nom,"r+");
  //char *buff_inicio = malloc(10);
  char buff_actual[10];
  char buff_sgte[10];
  //fread(buff_inicio, 10, 1, f);
  //int inicio = argv[0];
  int i = 2;
  while (i < argc){
    if (i == (argc-1)){
      fseek(f, atoi(argv[1])*10, SEEK_SET);
      fwrite(buff_sgte, 10, 1, f);
      printf("buff_sgte= %s \n",buff_sgte);

    }
    else{
      fseek(f, atoi(argv[i])*10, SEEK_SET);
      fread(buff_actual, 10, 1, f);
      printf("buff_actual(else)= %s \n",buff_actual);
      fseek(f, atoi(argv[i+1])*10, SEEK_SET);
      fread(buff_sgte, 10, 1, f);
      printf("buff_sgte(else)= %s \n",buff_sgte);
      fseek(f, atoi(argv[i+1])*10, SEEK_SET);
      fwrite(buff_actual, 10, 1, f);
      printf("buff_actual(else2)= %s \n",buff_actual);
      strcpy(buff_actual, buff_sgte);
      buff_actual[10] = '\0';
    }
    i++;
  }
  fclose(f);
  return 0;
}
