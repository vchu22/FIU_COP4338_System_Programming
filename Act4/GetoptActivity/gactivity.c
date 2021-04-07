#include <stdio.h>
#include <stdlib.h>

int main(int argc, char **argv)
{
  extern char *optarg;
  extern int optind;
  int c, err = 0;
  int bflag = 0, cflag = 0, dflag = 0;
  char *cname, *dname;
  static char usage[] = "usage: %s [-b] -c cname -d number value1 value2  [value ...]\n";

  while ((c = getopt(argc, argv, "bc:d:")) != -1)
    switch (c)
    {
    case 'b':
      bflag = 1;
      break;
    case 'c':
      cflag = 1;
      cname = optarg;
      break;
    case 'd':
      dflag = 1;
      dname = optarg;
      break;
    case '?':
      err = 1;
      break;
    }

  printf("Flags:");
  if (bflag)
  {
    printf(" -b");
  }
  if (cflag)
  {
    printf(" -c");
  }
  if (dflag)
  {
    printf(" -d");
  }
  printf("\n");

  if (cflag == 0)
  { /* -c was mandatory */
    fprintf(stderr, "%s: missing -c option\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }
  else if (dflag == 0)
  { /* -d was mandatory */
    fprintf(stderr, "%s: missing -d option\n", argv[0]);
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }
  else if (err)
  {
    fprintf(stderr, usage, argv[0]);
    exit(1);
  }

  printf("Parameters: %s %s\n", cname, dname);

  if (optind < argc) /* these are the arguments after the command-line options */
  {
    printf("Values: ");
    for (; optind < argc; optind++)
      printf("%s ", argv[optind]);
    printf("\n");
  }
  else
  {
    printf("no arguments left to process\n");
  }
  exit(0);
}
