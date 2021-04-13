#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "pointPrint.h"

int GetArgNum (int argc, char *argn) {
  // Ensure the argument entered is from 1-3 and the sentence are entered.  Errors out if not. 
  int number = atoi(argn);
  if (number > 3 || number < 1)
  {
    printf("Number argument must be an integer between 1 and 3\n");
    exit(1);
  }
  if (number != argc - 2) {
    printf("Number argument must be equal to the number of strings entered\n");
    exit(1);
  }
  return number;
}

int main(int argc, char *argv[])
{
  if (argc < 2){
    printf("An integer argument between 1 and 3 must be entered\n");
    exit(1);
  } else if (argc < 3)
  {
    printf("A string argument must be entered\n");
    exit(1);
  }
  
  // Create variables for a character, an integer, a string pointer.
  char c;
  int i;
  // The string variable is a string pointer that has not been allocated.
  char s[50];

  // Define pointers to those variables types without any initialization of those points to the previous variables
  char *cptr = (char*)malloc(sizeof(char));
  int *iptr = (int*)malloc(sizeof(int));
  char *sptr = (char*)malloc(sizeof(char *) * 50);

  // Assign: [using argc and argv]
  i = GetArgNum(argc, argv[1]);
  strcpy(s, argv[2]);
  c = s[0];
  
  // Assign pointers to the corresponding variables.
  cptr = &c;
  iptr = &i;
  sptr = s;
  
  while (i >= 1)
  {
    PrintValues(cptr, iptr, sptr, argv[argc - i + 1]);
  }
  return 0;
}
