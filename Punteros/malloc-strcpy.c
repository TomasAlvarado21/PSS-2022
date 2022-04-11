#include <stdio.h>
#include <string.h>

int main() {
  char *hola= "hola";
  char r[strlen(hola)+1];
  strcpy(r, hola);
  r[0]= 'H';
  printf("%s\n", r);
  printf("%s\n", r);
  return 0;
}
