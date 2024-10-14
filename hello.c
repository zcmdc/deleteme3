// File hello.c
#include <stdio.h>

int main()
{
  int i,j;

  double x;

  for (i=0;i < 5; i++)
    {
      fork();
    }

  x=0.0;
//start stop watch now
  for (i=0;i < 100000000; i++)
    {
      x = x+ 1.0;
      /* j++ ; */
    }
//end stop watch
  printf("Hello, now World!\n");
  return 0;
}

