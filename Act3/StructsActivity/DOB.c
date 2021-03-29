#include <stdio.h>
#include "studentstruct.c"
#include "DOB.h"

/* Type your code here */
void SetDate(DOB *s, int m, int d, int y)
{
  (*s).month = m;
  (*s).day = d;
  (*s).year = y;
}
void SetDay(DOB *s, int d)
{
  (*s).day = d;
}
void SetMonth(DOB *s, int m)
{
  (*s).month = m;
}
void SetYear(DOB *s, int y)
{
  (*s).year = y;
}
