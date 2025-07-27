/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "Snippets/23. sort/23. sort.h"

/* ******************************************************************************** */

i32 main(){
    enum {size = 5};

    i32 array[size] = {5, 7, 1, 4, 6};
    i32 indexes[size];

    for(int i = 0; i < size; i++)
        indexes[i] = i;

    insertionSortLargeRecord(array, indexes, size);

    for(int i = 0; i < size; i++)
        printf("%d ", array[indexes[i]]);

    putchar(10);
}

/* ******************************************************************************** */