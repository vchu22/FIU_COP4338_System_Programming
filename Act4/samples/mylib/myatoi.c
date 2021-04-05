#include <stdio.h>

int myatoi(char* str)
{
  char *ptr = str;
  int result = 0;

  if(!ptr) return 0;
  while('0' <= *ptr && *ptr <= '9') {
    result = (result * 10) + (*ptr - '0');
    ptr++;
  }
  return result;
}
