#include <stdio.h>
#include <stdlib.h>

#include "borrar-bits.h"
// p es el patron
int posicionBits(int x, int p, int n) {
	int m = ~(-1 << n);
	for (int i = 0; i < sizeof(x) * 8 -n +1; i++) {
		if (((x >> i) & m) == p) {
			return i;
		}
	}
	return -1;
}

uint borrar_bits(uint x, uint pat, int len) {
  unsigned mask = x;
  while (posicionBits(x, pat, len))
}