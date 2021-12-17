/*
 * Este programa muestra como leer varias palabras del teclado (stdin)
 * Codigo tomado de: https://www.programiz.com/c-programming/c-strings
 *
 * Modificado por: John Sanabria - john.sanabria@correounivalle.edu.co
 * Fecha: 2021-02-26
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include "leercadena.h"

int main(int argc, char *argv[]) {
  char comando[BUFSIZ];
  char **vector;
  int i;
  pid_t pid;
  char *fin = "quit";
  int status = 0;

  while(1) {

    printf("> ");
    leer_de_teclado(BUFSIZ,comando);
    pid = fork();

    if (pid < 0) {
      printf("No pude crear un proceso\n");
      return 2;
    } else if (pid == 0) {

      vector = de_cadena_a_vector(comando);

      if (strcmp(fin, vector[0]) == 0)
      {
        printf("Exit by user break.\n");
        exit(1);
      }
      else
      {
        execvp(vector[0],vector);
        exit(0);
      }
      
    } 
    else 
    {
      wait(&status);
      if (status > 0)
      {
        exit(0);
      }
    }
  }

  return 0;
}
