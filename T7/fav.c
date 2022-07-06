#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>


#include "fav.h"

/*
int favorables(int n, int sum, int rep) {
 int fav= 0; // número de casos favorables
 for (int i= 0; i<rep; i++) {
  int s= 0; // suma de los dados
  for (int j= 0; j<n; j++)
    s += (rand() % 6)+1; // entrega entero pseudo-aleatorio en [1,6]
  if (s==sum) // caso favorable: los dados suman sum
    fav++;
 }
 return fav;
}
*/
int favorables_par(int n, int sum, int rep, int p){
  int fav= 0; // número de casos favorables
  int fds[p][2]; // pipes
  int pids[p]; // pids
  int tam_bloque = (rep)/p;
  
  for(int i=0; i<p; i++){
    pipe(fds[i]);
    init_rand_seed();
    pids[i] = fork();
    if(pids[i] == 0){ // hijo
      close(fds[i][0]);
      int izq = tam_bloque*i;
      int der = tam_bloque*(i+1) - 1;
      if(i == p-1) der = rep-1;
      int res = favorables(n, sum, der-izq+1);
      write(fds[i][1], &res, sizeof(int));
      exit(0);
    }
    else{ // padre
      close(fds[i][1]);
    }
  }
  
  for(int i=0; i<p; i++){
    waitpid(pids[i], NULL, 0);
    int res_hijo;
    read(fds[i][0], &res_hijo, sizeof(int));
    fav += res_hijo;
  }
  return fav;
}
// explain de before code:
// - n: número de dados
// - sum: suma de los dados
// - rep: número de repeticiones de la prueba
// - p: número de procesos
// - fav: número de casos favorables
// - fds: pipes
// - pids: pids
// - tam_bloque: tamaño de bloque
// - izq: límite izquierdo del bloque
// - der: límite derecho del bloque
// - res: resultado de la prueba
// - res_hijo: resultado del hijo
// - fav: número de casos favorables
// explain izq and der:
// - izq: límite izquierdo del bloque de repeticiones de la prueba (izq <= der) en la prueba de favorables paralelizada
// - der: límite derecho del bloque de repeticiones de la prueba (izq <= der) en la prueba de favorables paralelizada
// que es un bloque de repeticiones de la prueba de favorables paralelizada?
// - un bloque de repeticiones de la prueba de favorables paralelizada es un bloque de repeticiones de la prueba de favorables




// how to run:
// ./fav n sum rep p
// where n is the number of dice, sum is the sum of the dice, rep is the number of repetitions and p is the number of processes
// example:
// ./fav 6 6 100000 4
// will run the program with 4 processes and 100000 repetitions of the test with 6 dice and a sum of 6
// result:
// 4
// the number of favorable cases
// explanation:
// the program will run 4 processes and 100000 repetitions of the test with 6 dice and a sum of 6
// the first process will run the test with the first 100000 repetitions
// the second process will run the test with the second 100000 repetitions
// the third process will run the test with the third 100000 repetitions
// the fourth process will run the test with the fourth 100000 repetitions
// the result will be the number of favorable cases
// the number of favorable cases will be the sum of the results of the 4 processes
// the result will be 4