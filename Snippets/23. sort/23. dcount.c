/* ******************************************************************************** */

#include "23. dcount.h"

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

void simpledc(i32 size){
    i32 array[size];
    i32 idx[size];

    for(i32 i = 0; i < size; i++){
        array[i] = i;
        idx[i] = (size-1)-i;
    }

    for(i32 i = 0; i < size-1; i++)
        idx[array[i]] = array[i];

    for(i32 i = 0; i < size-1; i++)
        printf("%d ", array[idx[i]]);
}

/* ******************************************************************************** */

// N records
// keys: [0, M-1]

void distrCount(i32 *array, i32 size, i32 maxKeys){
    i32 count[maxKeys];
    i32 idx[size];

    for(i32 i = 0; i < maxKeys; i++){
        count[i] = 0;
    }

    for(i32 i = 0; i < size; i++){
        idx[i] = 0;
    }

    for(i32 i = 0; i < size; i++)
        count[array[i]]++;

    for(i32 i = 0; i < maxKeys-1; i++)
        count[i] = count[i-1] + count[i];

    for(i32 i = size-1; i > 0; i--)
        idx[count[array[i]]--] = array[i];

    for(i32 i = 0; i < size; i++)
        array[i] = idx[i];
}

/* ******************************************************************************** */