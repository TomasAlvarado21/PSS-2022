#include <stdio.h>

int main() {
  int x;               // declaracion
  x = 5;               // asignacion
  printf("%d\n", x);   // lectura
  printf("%p\n", &x);  // direccion
  printf("%ld\n", sizeof(x)); // Tamano
  int y = x + 10;      // declaracion con
                       // inicializacion
  x = x+1;             // asignacion
  double pi = 3.14159; // variable real
  pi = pi + x;
  printf("%ld\n", sizeof(pi));

  int *ptr = & x;       // decl. puntero
  printf("%p\n", ptr);
  ptr = &y;
  double *ptr_pi = &pi;
  printf("%p\n", ptr_pi);

  *ptr = x;     // operador de contenido
                // en una asignacion
  x = 1;
  int z = *ptr; // operador de contenido
                // en una expresion
  printf("%d\n", z);

  int a[10];
  printf("%p\n", a);
  for (int i= 0; i<10; i++) {
    a[i]= i*i;
    printf("%p: %d\n", &a[i], a[i]);
  }
  int k= 1000000000;
  printf("%d\n", a[k]);

  return 0;
}

