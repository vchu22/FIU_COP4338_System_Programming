#ifndef DOB_H
#define DOB_H

typedef struct DOB_struct
{
  int month;
  int day;
  int year;
} DOB;

void SetDate(DOB *s, int m, int d, int y);
void SetDay(DOB *s, int d);
void SetMonth(DOB *s, int m);
void SetYear(DOB *s, int y);

#endif
