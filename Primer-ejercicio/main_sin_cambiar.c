#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
/*
int main(void)
{
  int idPadre = getpid();
  pid_t padre = getppid();
  pid_t rc;

  for(int i = 0; i < 5; i++)
  {
    if(getpid() == idPadre)
    {
      rc = fork();
      if(rc < 0)
      {
        printf("No se pudo crear el proceso.");
      }
      else if(rc == 0)
      {
        printf("\nSoy hijo con PID [%d] y mi padre tiene PID [%d]\n", getpid(), getppid());
        return 0;
      }
    }
  }
}
*/