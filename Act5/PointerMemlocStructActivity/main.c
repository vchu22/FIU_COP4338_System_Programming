#include <stdio.h>
#include <stdlib.h>
#include "structure.h"

int main(void)
{
  Structure **stc = (Structure *)malloc(sizeof(Structure) * 5);

  // Ask the user to enter information for each of these variables one at a time.
  // GetInputs(stc1);
  for (int i = 0; i < 5; i++)
  {
    printf("Structure %d:\n", i + 1);
    printf("\tStructure %d pointer: %p\n", i + 1, &stc + sizeof(Structure) * i);
    printf("\tCharacter:\n");
    printf("\tInteger:\n");
    printf("\tString:\n");
    printf("\tFloating Point:\n");
  }

  return 0;
}
