#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

typedef struct nodo {
 int dato;
 struct nodo *izquierda, *derecha;
} Nodo;



Nodo *nuevoNodo(int dato) {
    // Solicitar memoria
    size_t tamanioNodo = sizeof(Nodo);
    Nodo *nodo = (Nodo *) malloc(tamanioNodo);
    // Asignar el dato e iniciar hojas
    nodo->dato = dato;
    nodo->izquierda = nodo->derecha = NULL;
    return nodo;
}

//Nodo **rama(Nodo *a, int v, int *p);
void insertar(Nodo *nodo, int dato) {
    // ¿Izquierda o derecha?
    // Si es mayor va a la derecha
    if (dato > nodo->dato) {
        // Tienes espacio a la derecha?
        if (nodo->derecha == NULL) {
            nodo->derecha = nuevoNodo(dato);
        } else {
            // Si la derecha ya está ocupada, recursividad ;)
            insertar(nodo->derecha, dato);
        }
    } else {
        // Si no, a la izquierda
        if (nodo->izquierda == NULL) {
            nodo->izquierda = nuevoNodo(dato);
        } else {
            // Si la izquierda ya está ocupada, recursividad ;)
            insertar(nodo->izquierda, dato);
        }
    }
}


//int n;
//Nodo **r= rama(a, 5, &n);
const Nodo **r = malloc(sizeof(Nodo)*100000);
Nodo **busqueda(Nodo *a, int x, int *p){
    if (a == NULL){
        return 0;
    }
    *r = a;
    r++;
    if (a->dato == x){
        return 1;
    }
    else if (a->dato >x){
        busqueda(a->izquierda, x, p);
    }
    else{
        busqueda(a->derecha, x, p);
    }
    
}

int main(){
    Nodo *a = nuevoNodo(3);
    insertar(a,2);
    insertar(a,1);
    insertar(a,6);
    insertar(a,5);
    insertar(a,4);
    insertar(a,7);
    int ab = busqueda(a,8);
    printf("%d \n", ab);
    return 0;
}