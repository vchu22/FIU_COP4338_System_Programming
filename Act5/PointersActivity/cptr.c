#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "encode.h"

int main(int argc, char *argv[])
{
  int argNum;
  if (argc < 2)
  {
    argNum = 5;
  }
  else
  {
    int number = atoi(argv[1]);
    if (number > 5 || number < 1)
    {
      printf("Argument must be a number between 1 and 5\n");
      return 1;
    }
    argNum = number;
  }
  // Create variables for a character, an integer, a string and a floating point number. 
  char c;
  int i;
  char* s;
  float f;
  
}
