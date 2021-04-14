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

  if (!fflag) {
    // provided have a hardwired name from previous program 2 (bar.txt)
    fname = "bar.txt";
  }
  // append the passed "argument string" to the file opened.
  FILE* inFile = NULL;
  inFile = fopen(fname, "r");
  if (inFile == NULL) {
    printf("Could not open file %s.\n", fname);
    return -1;
  }
  if (optind < argc)
  {
    for (; optind < argc; optind++) {
      fprintf(inFile, "%s ", argv[optind]);
    }
    fprintf(inFile, "\n");
    fflush(stdout);
  }
  fclose(inFile);  
  return 0;
}