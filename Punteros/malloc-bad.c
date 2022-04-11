#include <stdio.h>
#include <string.h>

char *copia(char *str) {
  char res[strlen(str)+1];
  return strcpy(res, str);
}

int main() {
  char *r= copia("hola");
  r[0]= 'H';
  printf("%s\n", r);
  printf("%s\n", r);
  return 0;
}
