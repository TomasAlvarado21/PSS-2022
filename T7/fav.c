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
// Function estimate the probability of throwing n dices , the sum of the results is equals to sum
// the parameter rep simulates the throwing rep times the n dices, returning the cases that the sum of the results is equals to sum
// we need to parallelize this function to estimate the probability of throwing n dices , the sum of the results is equals to sum using p cores
// for that we need to invoke p times fork() to create p processes, each process will throw n dices and will sum the results, the sum of the results is equals to sum

int favorables_par(int n, int sum, int rep, int p){
  int fav= 0; // número de casos favorables
  int pid;
  int status;
  int i;
  for (i= 0; i<p; i++) {
    pid= fork();
    if (pid==0) {
      fav+= favorables(n, sum, rep);
      exit(0);
    }
    else {
      wait(&status);
    }
  }
  return fav;
}