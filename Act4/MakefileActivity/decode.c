#include <string.h>
#include <ctype.h>
#include "decode.h"

void decode(char *input, int shift)
{
  for (int i = 0; i < (int)strlen(input); i++)
  {
    if (!isspace(input[i]))
      input[i] = input[i] - shift;
  }
}
