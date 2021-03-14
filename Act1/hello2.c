#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc > 4 || argc < 3) {
        printf("Name must be between 2 to 3 words.\n");
        return 1;
    } else if (argc == 4) {
        printf("Hello, my name is %s %s %s.\n", argv[1], argv[2], argv[3]);
    } else if (argc == 3) {
        printf("Hello, my name is %s %s.\n", argv[1], argv[2]);
    }
    return 0;
}
