#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(void)
{
  pid_t idPadre = getpid();
  pid_t rc;

  for(int i = 0; i < 5; i++)
  {
    rc = fork();
    
    if(rc < 0)
    {
      printf("No se pudo crear el proceso.\n");
    }
    else if(rc == 0)
    {
      printf("Soy hijo con PID [%d] y mi padre tiene PID [%d]\n", getpid(), idPadre);
      break;   
    }
  }
  return 0;
}


