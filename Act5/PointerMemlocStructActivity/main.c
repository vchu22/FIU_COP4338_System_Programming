#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main(void)
{
  Structure *stc1 = (Structure *)malloc(sizeof(Structure));
  Structure *stc2 = (Structure *)malloc(sizeof(Structure));
  Structure *stc3 = (Structure *)malloc(sizeof(Structure));
  Structure *stc4 = (Structure *)malloc(sizeof(Structure));
  Structure *stc5 = (Structure *)malloc(sizeof(Structure));

  // Ask the user to enter information for each of these variables one at a time.
  fflush(stdin);
  printf("Enter a single character:\n");
  scanf("%c", stc1->character);
  fflush(stdin);
  printf("Enter a phrase:\n");
  fgets(stc1->stringp, 50, stdin);
  printf("Enter an integer:\n");
  scanf("%i", stc1->integer);
  printf("Enter a floating point number:\n");
  scanf("%f", stc1->floatingPoint);

  return 0;
}
