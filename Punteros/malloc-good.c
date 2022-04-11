#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char *copia(char *str) {
  char *res = malloc(strlen(str)+1);
  strcpy(res, str);
  return res;
}

int main() {
  char *r= copia("hola");
  r[0]= 'H';
  printf("%s\n", r);
  printf("%s\n", r);
  free(r);
  printf("%p\n", r);
  return 0;
}
