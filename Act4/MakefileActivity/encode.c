#include <string.h>
#include <ctype.h>
#include "encode.h"

void encode(char *input, int shift)
{
  for (int i = 0; i < (int)strlen(input); i++)
  {
    if (!isspace(input[i]))
      input[i] = input[i] + shift;
  }
}
