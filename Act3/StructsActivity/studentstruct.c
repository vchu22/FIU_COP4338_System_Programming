#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "DOB.h"

enum StudentYear
{
  Freshman = 1,
  Sophomore = 2,
  Junior = 3,
  Senior = 4
};

typedef struct Student_struct
{
  char firstName[30];
  char lastName[30];
  char studentID[7];
  DOB dob;
  enum StudentYear studentYear;
  float GPA;
} Student;

int main(int argc, char *argv[])
{
  Student student;
  student.GPA = 3.0;
  int c;
  char *optarg;
  while (c = getopt(argc, argv, "imdycg") != 1)
  {
    switch (c)
    {
    case 'i':
      if (strlen(optarg) != 7)
        return false;
      for (int j = 0; j < (int)strlen(optarg); j++)
      {
        if (!isdigit(optarg[j]))
        {
          printf("Not a valid ID\n");
          return 1;
        }
      }
      break;
    case 'm':
      student.dob.month = atoi(optarg);
      break;
    case 'd':
      student.dob.day = atoi(optarg);
      break;
    case 'y':
      student.dob.year = atoi(optarg);
      break;
    case 'c':
      student.studentYear = atoi(optarg);
      break;
    case 'g':
      student.GPA = atof(optarg);
      break;
    default:
      abort();
    }
  }

  // bool firstNameFilled = false;
  // while (i < argc)
  // {
  //   if (strcmp(argv[i], "-i") == 0)
  //   {
  //     i++;
  //     if (validID(argv[i]))
  //     {
  //       strcpy(student.studentID, argv[i]);
  //     }
  //     else
  //     {
  //       printf("ID is invalid\n");
  //       return 1;
  //     }
  //   }
  //   else if (strcmp(argv[i], "-m") == 0)
  //   {
  //     i++;
  //     student.dob.month = atoi(argv[i]);
  //   }
  //   else if (strcmp(argv[i], "-d") == 0)
  //   {
  //     i++;
  //     student.dob.day = atoi(argv[i]);
  //   }
  //   else if (strcmp(argv[i], "-y") == 0)
  //   {
  //     i++;
  //     student.dob.year = atoi(argv[i]);
  //   }
  //   else if (strcmp(argv[i], "-c") == 0)
  //   {
  //     i++;
  //     student.studentYear = atoi(argv[i]);
  //   }
  //   else if (strcmp(argv[i], "-g") == 0)
  //   {
  //     i++;
  //     student.GPA = atof(argv[i]);
  //   }
  //   else
  //   {
  //     if (!firstNameFilled)
  //     {
  //       strcpy(student.firstName, argv[i]);
  //       firstNameFilled = true;
  //     }
  //     else
  //     {
  //       strcpy(student.lastName, argv[i]);
  //     }
  //   }
  //   i++;
  // }
}
