#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdbool.h>

int main(void)
{
  char fullname[4][50];
  char input[50];
  int index = 0;
  char c;
  while (index == 0 || c != '\n' && c != EOF)
  {
    c = getchar();
    input[index] = c;
    index++;
  }
  input[index] = '\0';

  printf("%s\n", input);

  int length = 0;
  if (length < 2 || length > 4)
  {
    printf("Name must be between 2 to 4 words\n");
    return 1;
  }

  return 0;
}
