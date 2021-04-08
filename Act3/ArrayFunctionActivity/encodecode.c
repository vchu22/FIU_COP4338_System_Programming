#include "encode.h"

void encode(char input[80], int shift)
{
  for (int i = 0; i < strlen(input); i++)
  {
    if (!isspace(input[i]))
      input[i] = input[i] + shift;
  }
}

void decode(char *input, int shift)
{
  for (int i = 0; i < strlen(input); i++)
  {
    if (!isspace(input[i]))
      input[i] = input[i] - shift;
  }
}
