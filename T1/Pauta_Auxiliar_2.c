#include <stdio.h>

int posicionBits(int x, int p, int n);
int bits1(int n);

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

unsigned repBitsOriginal(unsigned x, int i, int k, unsigned val) {
	unsigned mask1 = ~((-1)<<k); // 000...011...1 con k unos
	unsigned mask2 = mask1 << i; // 0...0 1^{k} 0^{i}
	val <<= i;
	x &= ~mask2;
	x |= val;
	return x;
}


int main() {
	printf("bits1 de 0x650 es %d!\n", bits1(0x650));
	int res = posicionBits(0x562, 0xB, 4);
	printf("posicionBits(0x562, 0xB, 4) == %d\n", res);
	printf("posicionBits(0x01010101, 0, 8) == %d\n", posicionBits(0x01010101, 0, 8));
	printf("repBitsClase(0x5555FFFF, 8, 12, 0x123) == 0x%X\n", repBitsClase(0x01010101, 8, 12, 0x123));
	printf("repBitsOriginal(0x5555FFFF, 8, 12, 0x123) == 0x%X\n", repBitsOriginal(0x5555FFFF, 8, 12, 0x123));
	return 0;
}


int bits1(int n) {
	int total = 0;
	for (int i = 0; i < sizeof(n)*8; i++) {
		if ((1 & (n >> i)) == 1) {
			total++;
		}
	}
	return total;
}

int posicionBits(int x, int p, int n) {
	int m = ~(-1 << n);
	for (int i = 0; i < sizeof(x) * 8 -n +1; i++) {
		if (((x >> i) & m) == p) {
			return i;
		}
	}
	return -1;
}

