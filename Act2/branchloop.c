#include <stdio.h>
#include <string.h>

int main(int argc, char* argv[]){
    if (argc != 3) {
        printf("Name must be exactly 2 words.\n");
        return 1;
    }
    char fullname[100] = "";
    strcat(fullname, argv[1]);
    strcat(fullname, " ");
    strcat(fullname, argv[2]);
    strcat(fullname, " ");
    for (int i = 0; i < 10; i++) {
        printf("%s\n", fullname);
    }
    // Count how many characters are in your first name and last name.
    int firstname_length = strlen(argv[1]);
    int lastname_length = strlen(argv[2]);
    if (firstname_length > lastname_length) {
        printf("My first name is bigger than my last name.\n");
    } else if (firstname_length < lastname_length) {
        printf("My last name is bigger than my first name.\n");
    } else {
        printf("My first and last name have the same number of characters.\n");
    }

    return 0;
}
