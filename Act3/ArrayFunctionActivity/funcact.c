#include <stdio.h>
#include <string.h>
#include "encode.h"

int main(int argc, char *argv[])
{
  int encodingKey;
  if (argc < 2)
  {
    encodingKey = 3;
  }
  else
  {
    int number = atoi(argv[1]);
    if (number > 5 || number < 1)
    {
      printf("Argument must be a number between 1 and 5\n");
      return 1;
    }
    encodingKey = number;
  }

  printf("Please enter a sentence:\n");
  char sentence[80];
  fgets(sentence, 80, stdin);
  encode(sentence, encodingKey);
  printf("Sentence: %s\n", sentence);
  return 0;
}
