#include <stdio.h>

int main(int argc, char* argv[]){
    if (argc > 4 || argc < 3) {
        printf("Name must be between 2 to 3 words.\n");
        return 1;
    }
    char colors[4][7] = {"red", "blue", "yellow", "green"};
    int choice = -1;
    printf("What is your favorite color? Please enter the corresponding number: 1. %s, 2. %s, 3. %s, 4. %s\n", colors[0], colors[1], colors[2], colors[3]);
    scanf("%d", &choice);

    while (choice < 1 || choice > 4) {
        printf("Not a valid choice. Please enter a number from 1 to 4 representing your favorite color:\n");
        scanf("%d", &choice);
    }
    choice--;
    if (argc == 4) {
        printf("Hello, my name is %s %s %s and my favorite color is %s.\n", argv[1], argv[2], argv[3], colors[choice]);
    } else if (argc == 3) {
        printf("Hello, my name is %s %s and my favorite color is %s.\n", argv[1], argv[2], colors[choice]);
    }
    return 0;
}
