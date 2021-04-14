#ifndef STRUCTURE_H
#define STRUCTURE_H

typedef struct Structure_struct
{
  char character;
  char *stringp;
  int integer;
  float floatingPoint;
} Structure;

void GetInputs(Structure *stc);

#endif
