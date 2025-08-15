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

/* ******************************************************************************** */

    i32 in[size-1];
    i32 idx[size-1];

    for(int i = 0; i < size-1; i++){
        in[i] = i;
        idx[i] = (size-1)-i;
    }

    for(int i = 0; i < size-1; i++)
        idx[in[i]] = in[i];

    for(int i = 0; i < size-1; i++)
        printf("%d ", idx[in[i]]);

    putchar(10);
}

/* ******************************************************************************** */