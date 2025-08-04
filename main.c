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

    shellSort(array, size);

    for(int i = 0; i < size; i++)
        printf("%c ", array[i]);

    putchar(10);
}

/* ******************************************************************************** */