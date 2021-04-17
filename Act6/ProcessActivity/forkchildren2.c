#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>

int main(int argc, char *argv[]){
    char *args1[] = {"ls", "-l", NULL};
    execvp("ls", args1);

    char *args2[] = {"cat", "forkchildren2.c", NULL};
    execvp("cat", args2);
    return 0;
}