#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdio.h>

int N_CORES;

typedef unsigned long long ull;
typedef unsigned int uint;
ull buscar_factor(ull x, ull l, ull r){
	for(ull k = l; k <= r; k++){
		if(x % k == 0){
			return k; // k divide a x
		}
	}
	return 0; // no se encontr ́o divisor en [l, r]
}

ull buscar_factor_par(ull x, ull l, ull r){

	int pids[N_CORES];
	int fds[N_CORES][2];

	ull tam_bloque = (r-l+1)/N_CORES;
	
	for(int i=0; i<N_CORES; i++){
		pipe(fds[i]);
		pids[i] = fork();

		if(pids[i] == 0){ // hijo
			close(fds[i][0]);
			ull izq = l+tam_bloque*i;
			ull der = l+tam_bloque*(i+1) - 1;
			if(i == N_CORES-1) der = r;
			ull res = buscar_factor(x, izq, der);
			write(fds[i][1], &res, sizeof(ull));
			exit(0);
		}
		else{ // padre
			close(fds[i][1]);
		}
	}

	ull res = 0;
	for(int i=0; i<N_CORES; i++){
		waitpid(pids[i], NULL, 0);
		ull res_hijo;
		read(fds[i][0], &res_hijo, sizeof(ull));
		if(res_hijo != 0){
			res = res_hijo;
		}
	}
	return res;
}


int main(int argc, char* argv[]){
	N_CORES = atoi(argv[1]);

	
	const ull PRIMO = 1e9+7;

	ull res = buscar_factor_par(67543411, 2, PRIMO-1);

	printf("Divisor: %d\n", res);

	return 0;
}

// explain the code:
// - N_CORES: número de procesos
// - PRIMO: primo
// - res: divisor de 67543411
// explain the code:
// - buscar_factor_par: busca el divisor de 67543411 en [2, PRIMO-1]
// - x: 67543411
