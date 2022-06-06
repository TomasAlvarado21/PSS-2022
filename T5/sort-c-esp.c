#include <string.h>

void sort(char **noms, int n) {
  char **ult= &noms[n-1];
  char **p= noms;
  while (p<ult) {
    char *p1=[0];
    char *p2=[1];
    int c1 = 0;
    int c2 = 0;
    while(*p1 !='/0'){
      while (*p1 != ' '){
        p1++;
      }
      p1++;
      c1++;   
    }

    while(*p2 !='/0'){
      while (*p2 != ' '){
        p2++;
      }
      p2++;
      c2++;      
    }
    
    if(c1>c2){
      int rc = 1;
    }
    else(){
        int rc = -1;
    }
    
    
    //int rc= strcmp(p[0], p[1]);
    
    
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