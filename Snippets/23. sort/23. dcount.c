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

// N records
// keys: [0, M-1]

none distrCount(i32 *a, i32 N, i32 M){
    i32 count[M];
    i32 b[N];

    memset(count, 0, M*sizeof(i32));
    memset(b, 0, N*sizeof(i32));

    for(i32 i = 0; i < M; i++)
        count[i] = 0;

    for(i32 i = 0; i < N; i++)
        count[a[i]]++;

    for(i32 i = 0; i < M; i++)
        count[i] = count[i-1] + count[i];

    for(i32 i = N-1; i > 0; i--)
        b[count[a[i]]--] = a[i];
    
    for(i32 i = 1; i <= N; i++)
        a[i] = b[i];

    for(i32 i = 0; i < M; i++)
        printf("%d ", count[i]);
    putchar(10);
}

/* ******************************************************************************** */