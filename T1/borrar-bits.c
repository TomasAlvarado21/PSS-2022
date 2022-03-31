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
unsigned repBitsOriginal(unsigned x, int i, int k, unsigned val) {
  unsigned mask1 = ~((-1)<<k); // 000...011...1 con k unos
  unsigned mask2 = mask1 << i; // 0...0 1^{k} 0^{i}
  val <<= i;
  x &= ~mask2;
  x |= val;
  return x;
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
  unsigned mask3 = 1;
  mask3 <<= sizeof(x)*2;
  mask = mask | mask3;
  unsigned mask2 = 0;
  int pos = 0;
  (mask2 <<= (len-1));
  mask2 <<= 1;
  while (posicionBits(mask,pat,len)!=-1){
    if (pat == 0){
      break;
    }
    else{
      printf("mask %s\n", to_binary(mask));
      printf("pos bit %d\n", posicionBits(x, pat, len));
      pos += posicionBits(mask,pat,len);
      x = repBitsOriginal(x, pos, len, mask2);
      pos += len;
      printf("pos %d\n", pos);
      printf("x %s\n", to_binary(x));
      mask >>= pos;      
    }

  }
//10001001
//100110111
//1101000

  return x;
}
/*
uint main() {
  printf("repBitsClase(0b101010101, 0, 2, 00b11) == 0b%s\n", to_binary(borrar_bits(0b00010001001, 0b1,1)));
  //printf("a%d\n", borrar_bits(0b00010001001,0b1,1));1101000011
  return 0;
}*/
