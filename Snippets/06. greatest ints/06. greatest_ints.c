#include "06. greatest_ints.h"

void greatest_ints(size_t *x, size_t *y){
   for(size_t i = ULLONG_MAX; i > 0; i--)
      for(size_t j = ULLONG_MAX; j > 0; j--)
         if(gcd(i,j) == 1 && i!=j){
            *x = i;
            *y = j;
            return;
         }
}