#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
  extern char *optarg;
  extern int optind;
  int c, err = 0;
  int fflag = 0;
  char *fname;
  static char usage[] = "usage: ./reader [-f \"filename\"] 'lines'\n";

  while ((c = getopt(argc, argv, "luf:")) != -1)
    switch (c)
    {
    case 'f':
      fflag = 1;
      fname = optarg;
      break;
    case '?':
      err = 1;
      break;
    }

  if (optind >= argc)
  {
    printf("Must include an integer argument.\n");
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }
  if (!fflag)
  {
    // if no -f flag, provided have a hardwired name from previous program 2 (bar.txt)
    fname = "bar.txt";
  }
  // read from file
  FILE *inFile = NULL;
  inFile = fopen(fname, "r");
  if (inFile == NULL)
  {
    printf("Could not open file %s.\n", fname);
    return -1;
  }

  printf("Opening file \"%s\"\n", fname);
  int lineNum = 1;
  const int lastLine = atoi(argv[optind]);
  char currLine[80], currWord[80];
  while (fgets(currLine, 80, inFile) && lineNum <= lastLine)
  {
    int wordNum = 1;
    while (sscanf(currLine, "%s", currWord) >= 1)
    {
      printf("File Sentence %d word %d = %s\n", lineNum, wordNum, currWord);
      strncpy(currLine, currLine + strlen(currWord) + 1, strlen(currLine) - strlen(currWord) + 1);
      wordNum++;
    }
    lineNum++;
  }
  fflush(stdout);
  fclose(inFile);
  return 0;
}
