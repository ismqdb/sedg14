/* ******************************************************************************** */

#include "./05. binary.h"

/* ******************************************************************************** */

i32 binary(i32 num){
    i32 *ptr = (i32*)malloc(sizeof(i32));
    i32 currentSize = 1;
    for(i32 i = 0; num>0; i++){
        *(ptr+i) = num%2;
        num/=2;
        currentSize++;
        ptr = (i32*)realloc(ptr, currentSize*sizeof(i32));
    }
    currentSize--;

    while(currentSize-->0)
        printf("%d", *(ptr+currentSize));
        
    free(ptr);
    putchar(10);
}

/* ******************************************************************************** */