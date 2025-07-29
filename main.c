/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "Snippets/23. sort/23. sort.h"

/* ******************************************************************************** */

i32 main(){
    enum {size = 15};

    i32 array[size] = {
        'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 
        'E', 'X', 'A', 'M', 'P', 'L', 'E'
    };
    i32 indexes[size] = {0, 10, 8, 14, 7, 5, 13, 11, 6, 2, 12, 3, 1, 4, 9};

    insitu(array, indexes, size);

    for(int i = 0; i < size; i++)
        printf("%c ", array[indexes[i]]);

    putchar(10);
}

/* ******************************************************************************** */