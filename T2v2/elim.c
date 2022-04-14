#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "elim.h"

void eliminar_espacios(char *s) {
  int contador = 0;
  char *r = s;
  char *p = s;
  int i;
  int a = strlen(s)+1;

  for (i = 0; i < a; i++){
    if(*p == '\0'){
      *r = *p;
      break;
    }
    else if(*p == ' ' && contador > 0){
      p++;
      contador++;
    }
    else if (*p == ' '){
      *r = *p;
      contador++;
      p++;
      r++;
    }
    else{
      *r = *p;
      p++;
      r++;
      contador=0;
    }
  }
}
char *eliminacion_espacios(const char *s) {
  char f[strlen(s)+1];
  strcpy(f,s);
  eliminar_espacios(f);
  char *a;
  a = malloc(strlen(f)+1);
  strcpy(a,f);
  return a;
}