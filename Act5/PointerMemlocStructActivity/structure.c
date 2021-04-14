#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "structure.h"

void GetInputs(Structure *stc)
{
  char c;
  int i;
  char s[50];
  float f;

  fflush(stdin);
  printf("Enter a single character:\n");
  scanf("%c", &c);
  printf("Enter an integer:\n");
  scanf("%i", &i);
  fflush(stdin);
  printf("Enter a phrase:\n");
  fgets(s, 50, stdin);
  if (s[strlen(s) - 1] == '\n')
    s[strlen(s) - 1] = '\0';
  printf("Enter a floating point number:\n");
  scanf("%f", &f);

  (*stc).character = c;
  (*stc).integer = i;
  (*stc).stringp = s;
  (*stc).floatingPoint = f;
}
