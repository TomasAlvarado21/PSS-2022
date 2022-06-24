#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

#include "fav.h"
// Function estimate the probability of throwing n dices , the sum of the results is equals to sum
// the parameter rep simulates the throwing rep times the n dices, returning the cases that the sum of the results is equals to sum
// we need to parallelize this function to estimate the probability of throwing n dices , the sum of the results is equals to sum using p cores
// for that we need to invoke p times fork() to create p processes, each process will throw n dices and will sum the results, the sum of the results is equals to sum
int favorables_par(int n, int sum, int rep, int p) {
  int i, pid, status;
  int count = 0;
  int *results = malloc(rep * sizeof(int));
  for (i = 0; i < rep; i++) {
    init_rand_seed();
    pid = fork();
    if (pid == 0) {
      
      int result = throw_dices(n);
      exit(0);
    }
  }
  for (i = 0; i < rep; i++) {
    wait(&status);
  }
  for (i = 0; i < rep; i++) {
    if (results[i] == sum) {
      count++;
    }
  }
  free(results);
  return count; 
}
