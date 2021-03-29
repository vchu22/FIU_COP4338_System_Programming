#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
  if (argc < 3 || argc > 5)
  {
    printf("Name must be between 2 to 4 words\n");
    return 1;
  }
  // Put your full name on an array
  int length = argc - 1;
  char *fullName[length];
  for (int i = 1; i < argc; i++)
  {
    fullName[i - 1] = argv[i];
  }

  // Identify the characters (letters) that make up your name, and how many times they are repeated
  int fullNameLength = 0;
  int charFound[26] = {0};
  for (int i = 0; i < length; i++)
  {
    fullNameLength += strlen(fullName[i]);
    for (int j = 0; j < strlen(fullName[i]); j++)
    {
      int index = (int)(tolower(fullName[i][j])) - 97;
      charFound[index]++;
    }
  }

  // Display result
  for (int i = 0; i < length; i++)
  {
    printf("%s ", fullName[i]);
  }
  printf("%d\n", fullNameLength);

  for (int i = 0; i < 26; i++)
  {
    if (charFound[i] > 0)
    {
      printf("%c - %d, ", (char)(i + 97), charFound[i]);
    }
  }
  printf("\n");

  return 0;
}
