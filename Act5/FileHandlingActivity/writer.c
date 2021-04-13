#include <stdio.h>
#include <stdlib.h>

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

  if (fflag) {
    // create a file with that name or overwrite a previously existing file and write your name in on the first line followed by the "argument string". 
  } else {
    // only write your name to the screen followed by "argument string".
  }
  return 0;
}