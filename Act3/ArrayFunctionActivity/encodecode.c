#include "encode.h"

void encode(char input[80], int shift)
{
  char front[shift];
  for (int i = 0; i < shift; i++)
  {
    front[i] = input[i];
  }
  for (int i = 0; i < strlen(input) - shift; i++)
  {
  }
}
