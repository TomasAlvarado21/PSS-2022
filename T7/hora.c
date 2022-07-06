#include <stdio.h>
#include <time.h>


// program excecutable file: hora.exe
// the program has show the current time in the console

int main(){
  time_t tiempo = time(NULL);
  struct tm *tmPtr = localtime(&tiempo);
  printf("%d:%d:%d\n", tmPtr->tm_hour, tmPtr->tm_min, tmPtr->tm_sec);
    return 0;
}