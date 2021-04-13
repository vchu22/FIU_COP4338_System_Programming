#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void StringToLower(char str[]){
  for (int i=0; i<strlen(str); i++) {
    str[i] = tolower(str[i]);
  }
}
void StringToUpper(char str[]){
  for (int i=0; i<strlen(str); i++) {
    str[i] = toupper(str[i]);
  }
}

int main(int argc, char *argv[]) 
{
  extern char *optarg;
  extern int optind;
  int c, err = 0;
  int lflag = 0, uflag = 0, fflag = 0;
  char *fname;
  static char usage[] = "usage: ./writer [-lu] [-f filename] \"argument string\"\n";

  while ((c = getopt(argc, argv, "luf:")) != -1)
    switch (c)
    {
      case 'l':
        lflag = 1;
        break;
      case 'u':
        uflag = 1;
        break;
      case 'f':
        fflag = 1;
        fname = optarg;
        break;
      case '?':
        err = 1;
        break;
    }

  if (lflag && uflag)
  {
    fprintf(stderr, "Cannot use -l and -u flags simultaneously\n");
    fprintf(stderr, usage, argv[0]);
    exit(1);
  } else if (err)
  {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  if ((argc - optind) < 3 || (argc - optind) > 10) {
    printf("Argument string must between 3 to 10 words.\n");
    return -1;
  }
  char argString[80];
  if (fflag) {
    // create a file with that name or overwrite a previously existing file and write your name in on the first line followed by the "argument string".
    FILE* outFile = NULL;
    outFile = fopen(fname, "w");
    if (outFile == NULL) {
      printf("Could not open file %s.\n", fname);
      return -1;
    }
    if (optind < argc) /* these are the arguments after the command-line options */
    {
      for (; optind < argc; optind++) {
        if (lflag){
          StringToLower(argv[optind]);
          fprintf(outFile, "%s ", argv[optind]);
        }
        else if (uflag){
          StringToUpper(argv[optind]);
          fprintf(outFile, "%s ", argv[optind]);
        }
        else
          fprintf(outFile, "%s ", argv[optind]);
      }
      fprintf(outFile, "\n");
      fflush(stdout);
    }
    fclose(outFile);
  } else {
    // only write your name to the screen followed by "argument string".
    if (optind < argc) /* these are the arguments after the command-line options */
    {
      for (; optind < argc; optind++) {
        if (lflag){
          StringToLower(argv[optind]);
          fprintf(stdout, "%s ", argv[optind]);
        }
        else if (uflag){
          StringToUpper(argv[optind]);
          fprintf(stdout, "%s ", argv[optind]);
        }
        else
          fprintf(stdout, "%s ", argv[optind]);
      }
      fprintf(stdout, "\n");
      fflush(stdout);
    }
  }
  
  return 0;
}