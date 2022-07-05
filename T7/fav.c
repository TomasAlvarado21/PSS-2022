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