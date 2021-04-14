#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main(void)
{
  Structure **stc = (Structure *)malloc(sizeof(Structure) * 5);

  // Ask the user to enter information for each of these variables one at a time.
  for (int i = 0; i < 1; i++)
  {
    GetInputs(&stc + sizeof(Structure) * i);
  }
  printf("\n");
  for (int i = 0; i < 1; i++)
  {
    printf("Structure %d:\n", i + 1);
    printf("\tStructure %d pointer: %p\n", i + 1, &stc + sizeof(Structure) * i);
    printf("\tCharacter: %c\n", stc[0]->character);
    printf("\tInteger:\n");
    printf("\tString:\n");
    printf("\tFloating Point:\n");
  }
  free(stc);
  return 0;
}
