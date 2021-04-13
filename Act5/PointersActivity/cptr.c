#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int GetArgNum (int argc, char *argn) {
  if (argc < 2)
    return 5;
  else
  {
    int number = atoi(argn);
    if (number > 5 || number < 1)
    {
      printf("Argument must be a number between 1 and 5\n");
      exit(1);
    }
    return number;
  }
}

void GetInputs(char *c, int *i, char *s, float *f) {
  fflush(stdin);
  printf("Enter a single character:\n");
  scanf("%c", c);
  printf("Enter an integer:\n");
  scanf("%i", i);
  fflush(stdin);
  printf("Enter a phrase:\n");
  fgets(s, 50, stdin);
  if (s[strlen(s) - 1] == '\n')
    s[strlen(s) - 1] = '\0';
  printf("Enter a floating point number:\n");
  scanf("%f", f);
}

void PrintPointers(char *c, int *i, char *s, float *f) {
  printf("Character Pointer: %p\n", c);
  printf("Integer Pointer: %p\n", i);
  printf("String Pointer: %p\n", s);
  printf("Floating Point Pointer: %p\n", f);
}

void PrintValues(char *c, int *i, char *s, float *f) {
  printf("Character: %c\n", *c);
  printf("Integer: %i\n", *i);
  printf("String: %s\n", s);
  printf("Floating Point: %.2f\n", *f);
}

int main(int argc, char *argv[])
{
  // Ensure the argument entered is from 1-5 and if no argument is provided default to 5.
  int argNum = GetArgNum(argc, argv[1]);

  // Create variables for a character, an integer, a string and a floating point number. 
  char c;
  int i;
  // The string variable is a char array of a fixed length. In other words, the array variable will have to store the string read from console.
  char s[50];
  float f;

  // Define pointers to those variables types without any initialization of those points to the previous variables. 
  char *cptr = (char*)malloc(sizeof(char));
  int *iptr = (int*)malloc(sizeof(int));
  char *sptr = (char*)malloc(sizeof(char) * 50);
  float *fptr = (float*)malloc(sizeof(float));
  for (int j = 0; j < argNum; j++){
    // Ask the user to enter information for each of these variables one at a time.
    GetInputs(&c, &i, s, &f);
    // Print the unassigned pointers.
    PrintPointers(cptr, iptr, sptr, fptr);
    // Assign pointers to the corresponding variables.
    cptr = &c;
    iptr = &i;
    sptr = s;
    fptr = &f;
    // Print out values for the four variables without using the variables themselves.
    PrintValues(cptr, iptr, sptr, fptr);
    // Print out the addresses of the memory locations that each pointer points to
    PrintPointers(cptr, iptr, sptr, fptr);
    printf("\n");
  }
  
  return 0;
}
