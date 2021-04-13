#include <stdio.h>
#include <string.h>
#include "pointPrint.h"

void PrintValues(char *c, int *i, char *s, char *nextStr) {
  printf("Character: %c\n", *c);
  printf("Integer: %i\n", *i);
  printf("String: %s\n", s);
  (*i)--;
  if (nextStr != NULL){
    strcpy(s, nextStr);
  }
  (*c) = s[0];
}