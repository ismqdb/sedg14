/* ******************************************************************************** */

#include "./04. convert.h"

/* ******************************************************************************** */

i32 convert(){
   u8 c;
   unsigned long long value = 0;
   i32 pow = 1;

   i32 chunk = 5;
   i32 currentSize = 0;

   u8* ptr = (u8*)malloc(chunk);
   currentSize = chunk;
   i32 i;

   for(i = 0; i < currentSize; i++){
      if(i == (currentSize-1)){
         ptr = (u8*)realloc(ptr, currentSize+chunk);
         currentSize += chunk;
      }

      scanf("%1c", &c);
      if(!isdigit(c) || c == ' ')
         break;
      ptr[i] = c;
   }

   if(i > 9){
      fprintf(stderr, "Overflow. Use 9 digits or less.\n");
      errno = EIO;
      return 0;
   }

   while(i-- > 0){
      value += (pow * (ptr[i] - '0'));
      pow *= 10;
   }

   return value;
}

/* ******************************************************************************** */