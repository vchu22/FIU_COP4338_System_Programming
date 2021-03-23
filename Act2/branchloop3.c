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
    
    int n = atoi(argv[3]);
    if (n <= 0) {
        return 1;
    } else if (n > 10) {
        printf("Number cannot be bigger than 10\n");
        return 1;
    }
    /// Print name
    do {
        printf("%s %s\n", firstname, lastname);
        n--;
    } while (n > 0);

    int total_length = strlen(firstname) + strlen(lastname);
    // Print the number of characters in your name followed by your name backwards.
    printf("%d ", total_length);
    for (int i = strlen(lastname) - 1; i >= 0; i--) {
        printf("%c", tolower(lastname[i]));
    }
    printf(" ");
    for (int i = strlen(firstname) - 1; i >= 0; i--) {
        printf("%c", tolower(firstname[i]));
    }
    printf("\n");

    return 0;
}
