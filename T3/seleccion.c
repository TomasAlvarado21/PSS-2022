#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#include "seleccion.h"

int selprim(Nodo **pa, int k) {
  Nodo *a = *pa;
  if(a == NULL) return 0;
  
  int cnt_left = selprim(&a->izq, k);
  
  if(cnt_left == k){
    *pa = a->izq;
    selprim(&a->der,0);
    free(a);
    return k;
  }
  
  int cnt_right = selprim(&a->der, k-cnt_left-1);
  
  return cnt_left+1+cnt_right;

}

Nodo *ultimos(Nodo *a, int *pk) {
  int contador_der = *pk; 
  
  if(a == NULL){
    *pk = 0;
    return 0;
  }
  
  Nodo *right = ultimos(a->der, &contador_der);
  if(contador_der == *pk){
    return right;
  }
  int contador_izq = *pk-contador_der-1;

  Nodo *left = ultimos(a->izq, &contador_izq);
  
  Nodo *b = malloc(sizeof(Nodo));

  b->x = a->x;
  b->der = right;
  b->izq = left;

  *pk = contador_der+1+contador_izq;
  return b;
}
