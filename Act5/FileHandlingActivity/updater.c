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
  static char usage[] = "usage: ./updater -f filename \"argument string\"\n";

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

  if ((argc - optind) != 5) {
    printf("Argument string must be exactly 5 words.\n");
    return -1;
  }
  char argString[80];
  if (fflag) {
    // append the passed "argument string" to the file opened.
    FILE* outFile = NULL;
    outFile = fopen(fname, "a");
    if (outFile == NULL) {
      printf("Could not open file %s.\n", fname);
      return -1;
    }
    if (optind < argc) /* these are the arguments after the command-line options */
    {
      for (; optind < argc; optind++) {
        fprintf(outFile, "%s ", argv[optind]);
      }
      fprintf(outFile, "\n");
      fflush(stdout);
    }
    fclose(outFile);
  } else {
    printf("Must include a -f flag and a filename.\n");
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }
  
  return 0;
}