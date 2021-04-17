#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

char *args[2][3] = {{"ls", "-l", NULL}, {"cat", "forkchildren2.c", NULL}};

int main(int argc, char *argv[]){
    
    for (int i=0; i<2; i++) {
        pid_t pid = fork();
        if (pid < 0)
        {
            perror("Fork failed!");
        }
        else if (pid == 0)
        {
            execvp(args[i][0], args[i]);
            exit(0);
        } else {
            wait(NULL);
            printf("\n\n");
        }
    }
    printf("The parent process is finished\n");
    return 0;
}