#include "stdio.h"
#include "stdlib.h"
#include "unistd-h"
#include "sys/wait.h"
//Feck-Melzer

char *argsdumm[] = {"ls", NULL};
char *args[] = {"ps", "df", "pwd"}

int main(int argc, char* argv[])
{
  for(int i = 0; i < 4; i++)
  {
    pid_t p = fork();
    if(p == 0)
    {
      execvp(argsdumm[0], args);
      argsdumm[0] = args[i];
      printf("failed to execute");
    }
    else{
      int status;
      wait(-1, &status, 0);
    }
  }
  printf("done.\n");
  return 1
}
