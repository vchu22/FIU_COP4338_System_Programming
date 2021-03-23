#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int main(int argc, char* argv[]){
    if (argc < 4) {
        printf("Error - missing name\n");
        return 1;
    }
    // get name length
    char *firstname = argv[1];
    char *lastname = argv[2];
    int total_length = strlen(firstname) + strlen(lastname);
    int n = atoi(argv[3]);
    if (n > total_length) {
        printf("Error - index too long\n");
        return 1;
    } else if (n <= 0) {
        return 1;
    }

    char letter;
    if (n <= strlen(firstname)) {
        letter = firstname[n - 1];
    } else {
	    letter = lastname[n - (int)strlen(firstname) - 1];
    }
    // Turn all letters to upper case
    for (int i = 0; i < strlen(firstname); i++) {
        firstname[i] = toupper(firstname[i]);
    }
    for (int i = 0; i < strlen(lastname); i++) {
        lastname[i] = toupper(lastname[i]);
    }

    printf("%s %s %c\n", firstname, lastname, letter);
    return 0;
}
