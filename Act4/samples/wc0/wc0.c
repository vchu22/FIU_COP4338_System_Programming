#include <stdio.h>

#define DEBUG 0

#define IN  0 /* inside a word */
#define OUT 1 /* outside a world */

int main()
{
  int c, nl, nw, nc, state;
  
  nl = nw = nc = 0;
  state = OUT;
  while((c = getchar()) != EOF) {
    nc++;
    switch(c) {
    case '\n':
      nl++;
      /* no break here*/
    case ' ':
    case '\t':
      state = OUT;
      break;
    default:
      if(state == OUT) {
	state = IN;
	nw++;
#if DEBUG
	printf("\n");
#endif
      }
#if DEBUG
      printf("%c", c);
#endif
    }
  }

#if DEBUG
  printf("\n");
#endif
  printf("%8d%8d%8d\n", nl, nw, nc);

  return 0;
}
