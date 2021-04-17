#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

void CreateChildProcess() {
  pid_t pid = fork();
  if (pid < 0)
  {
    perror("Fork failed!");
  }
  if (pid == 0)
  {
    for (int i=1; i<=6; i++) {
      printf("I am child %d and this is message num %d\n", (int)getpid(), i);
      sleep(5);
    }
    exit(0);
  }
}

int main(void)
{
  pid_t cpid[5];
  printf("Parent PID at entry is %d\n", (int)getpid());
  for (int i=0; i<5; i++) {
    CreateChildProcess();
    cpid[i] = wait(NULL);
    printf("Children %d exiting\n", cpid[i]);
  }
  printf("Parent PID at exit is %d\n", (int)getpid());
  return 0;
}
