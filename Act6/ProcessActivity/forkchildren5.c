#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(void)
{
  printf("Parent PID at entry is %d\n", (int)getpid());
  pid_t pid = fork();

  if (pid < 0)
  {
    perror("Fork failed!");
  }
  if (pid == 0)
  {
    printf("I am child %d\n", (int)getpid());
    sleep(5);
    exit(0);
  }
  else if (pid > 0)
  {
    wait();
    printf("Parent PID at exit is %d\n", (int)getpid());
  }
  return 0;
}
