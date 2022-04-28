#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>


typedef struct nodo {
 int x;
 struct nodo *izq, *der;
} Nodo;

void podarHojas(Nodo **pa){
    if (*pa == NULL){
        return;
    }
   if ((*pa->izq)->izq == NULL && (*pa->izq)->der == NULL){
       *pa->izq = NULL;
        return;
   }
   else{
        podarHojas(&(*pa->izq));
   }
   if ((*pa->der)->izq == NULL && (*pa->der)->der == NULL){
       *pa->der = NULL;
       return;
   }
   else{
        podarHojas(&(*pa->der));
   }
   return;
}