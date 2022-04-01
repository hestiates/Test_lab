#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void quadr(float a, float b, float c, float *x1, float *x2, int *flag)
{
    *x1 = 0;
    *x2 = 0;
    *flag = 0;
  float d = b * b - 4 * a * c;

  if (a == 0)
  {
      *flag = 1;
  }

  if (d > 0 && *flag == 0)
  {
      *x1 = (-b + sqrt(d)) / (2 * a);
      *x2 = (-b - sqrt(d)) / (2 * a);
  }
  else
    if (d == 0)
    {
        *x1 = -b / (2 * a);
        *x2 = *x1;
     }
    else
        *flag = 1;
}
