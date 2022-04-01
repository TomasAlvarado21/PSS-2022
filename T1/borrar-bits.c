#include <stdio.h>
#include <stdlib.h>

#include "borrar-bits.h"
int posicionBits(int x, int p, int n) {
  int m = ~(-1 << n);
  for (int i = 0; i < sizeof(x) * 8 -n +1; i++) {
    if (((x >> i) & m) == p) {
      return i;
    }
  }
  return -1;
}
unsigned repBitsClase(unsigned x, int i, int k, unsigned val) {
	unsigned x2 = x; // copia porque modificaremos x
	// movemos x para que esté en la posición que nos resulta cómoda
	x >>= i;

	// desactivamos (apagamos, cambiamos a 0)
	// los k bits que queremos reemplazar en x
	unsigned m = -1 << k;
	x &= m;

	// agregamos los bits de reemplazo de val
	x |= val;
	// devolvemos x a su posición original
	x <<= i;

	// volvemos a poner los bits que perdimos
	unsigned m2 = ~(-1 << i);
	return x | (x2 & m2);
}

static char *to_binary(uint x) {
  int len= 0;
  uint z= x;
  do {
    z >>= 1;
    len++;
  } while (z!=0);
  char *s= malloc(len+1);
  char *end = s+len;
  *end-- = 0;
  z= x;
  do {
    *end-- = '0' + (z&1);
    z >>= 1;
  } while (z!=0);
  return s;
}

uint borrar_bits(uint x, uint pat, int len) {
  unsigned mask = x;
  //unsigned mask2 = 0;
  int pos = 0;
  //(mask2 <<= (len-1));
  //mask2 <<= 1;


  if (pat == x){
    x = 0;
    return x;
  }
  while (posicionBits(mask,pat,len)!=-1){
    if (pat == 0){
      break;
    }
    else if (pat == x){
      x = 0;
    }
   
    else{
      if (pos == 32){
        break;
      }
      else{
      //printf("x %s\n", to_binary(x));
      //printf("mask %s\n", to_binary(mask));
      //printf("pos bit %d\n", posicionBits(mask, pat, len));
      pos += posicionBits(mask,pat,len);
      x = repBitsClase(x, pos, len, 0);
      pos += len;
      mask = x;
      //printf(" ret pos %d\n", pos);
      //printf(" ret x %s\n", to_binary(x));
      //printf("numero iteracion ");
      mask >>= pos;

      }
    }

  }
  

  return x;
}

/*
uint main() {
  printf("repBitsClase(0b101010101, 0, 2, 00b11) == 0b%s\n", to_binary(borrar_bits(0b11100011, 0b10,2)));
  //printf("a%d\n", borrar_bits(0b00010001001,0b1,1));
  return 0;
}*/
