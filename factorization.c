#include <stdio.h>
#include <math.h>


unsigned int fact(unsigned int q){
  unsigned int divisor = (int)sqrt(q);
  unsigned int divisor_2 = 2;
  while(q % divisor != 0 & q % divisor_2 != 0){
    divisor--;
    divisor_2++;
  }
  if (q % divisor == 0)
    return divisor;
  else
    return divisor_2;
}
