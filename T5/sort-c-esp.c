#include <string.h>
#include <stdio.h>

void sort(char **noms, int n) {
  char **ult = &noms[n-1];
  char **p = noms;
  while (p < ult) {
    char *p1 = p[0];
    char *p2 = p[1];
    int esp_palabra1 = 0;
    int esp_palabra2 = 0;

    while (*p1 != '\0'){
      if(*p1 == ' '){
        esp_palabra1++;
      }
      p1++;
    }    

    while (*p2 != '\0'){
      if(*p2 == ' '){
        esp_palabra2++;
      }
      p2++;
    }    
    int rc = (esp_palabra1 - esp_palabra2);
    // hasta aqui
    
    if (rc<=0)
      p++;
    else {
      char *tmp= p[0];
      p[0]= p[1];
      p[1]= tmp;
      p= noms;
    }
  }
}