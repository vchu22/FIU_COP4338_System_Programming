#include <stdio.h>
#include <string.h>
#include "structure.h"

void GetInputs(Structure *stc)
{
  fflush(stdin);
  printf("Enter a single character:\n");
  scanf("%c", (*stc).character);
  printf("Enter an integer:\n");
  scanf("%i", (*stc).integer);
  fflush(stdin);
  printf("Enter a phrase:\n");
  fgets((*stc).stringp, 50, stdin);
  if ((*stc).stringp[strlen((*stc).stringp) - 1] == '\n')
    (*stc).stringp[strlen((*stc).stringp) - 1] = '\0';
  printf("Enter a floating point number:\n");
  scanf("%f", (*stc).floatingPoint);
}
