// File hello.c
#include <stdio.h>

int main()
{
  int i,j;

  double x,y,z,w;

  x=0.0;
  z=0.0;
  w=0.0;
  y=0.0;
//start stop watch now
  for (i=0;i < 100000000; i++)
    {
      w = w+ 2.718 ;
    }

  for (i=0;i < 100000000; i++)
    {
      x = x+ 3.14159 ;
    }
  for (i=0;i < 100000000; i++)
    {
      y = y+ 1.414 ;
    }
  for (i=0;i < 100000000; i++)
    {
      z = z+ 1.001;
      /* j++ ; */
    }
//end stop watch
  //printf("check my numbers %f!\n",x);
  return 0;
}

