#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>
#include <unistd.h>

int para_quitar = 0;

void buscar(char * direccion) {
  DIR*d = opendir(".");
  if (d == NULL) {
    return;
  }

  for (struct dirent *entry = readdir(d); entry != NULL; entry = readdir(d)) {
    char *nombre = entry->d_name;
    struct stat statbuf;
    stat(nombre, &statbuf);
    if (S_ISREG(statbuf.st_mode) && strcmp(nombre, "a.out") == 0) {
      char buf[512];
      getcwd(buf, 512);
      printf("%s/%s\n", buf + para_quitar, nombre);
    }
    if (strcmp("..", nombre) == 0 || strcmp(".", nombre) == 0) {
      continue;
    }
    if (S_ISDIR(statbuf.st_mode)) {
      chdir(nombre);
      buscar(".");
      chdir("..");
    }
  }
  closedir(d);
}


int main() {
  char buf[512];
  getcwd(buf, 512);
  para_quitar = strlen(buf) + 1;
  buscar(".");
}
