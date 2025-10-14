/* ******************************************************************************** */

#include "23. dcount.h"

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

none simpledc(i32 size){
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

// noOfElems records
// keys: [0, maxKey-1]

none distrCount(i32 *in, i32 noOfElems, i32 maxKey){
    i32 count[maxKey];
    i32 out[noOfElems];

    memset(count, 0, maxKey*sizeof(i32));
    memset(out, 0, noOfElems*sizeof(i32));

    for(i32 i = 0; i < noOfElems; i++)
        count[in[i]]++;

    for(i32 j = 0; j < maxKey; j++)
        count[j] = count[j-1] + count[j];

    for(i32 i = noOfElems-1; i > -1; i--){
        out[count[in[i]]-1] = in[i];
        count[in[i]]--;
    }
    
    for(i32 i = 0; i < noOfElems; i++)
        in[i] = out[i];
}

/* ******************************************************************************** */