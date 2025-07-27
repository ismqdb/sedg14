/* ******************************************************************************** */

#include "./08. sieve.h"

/* ******************************************************************************** */

i32 sieve(i32 size){
    assert(size >= 2);

    i32 i,j;
    
    i32* a = (i32*)malloc(size*sizeof(i32));

    for(a[1]=0, i=2; i<size; i++)
        a[i]=1;

    for(i=2; i <= size/2; i++)
        for(j=2; j <= size/i; j++)
            if((i*j)<size)
                a[i*j] = 0;

    for(i = 1; i < size; i++)
        if(a[i]){
            i32 result = a[i];
            free(a);
            return result;
        }
}

/* ******************************************************************************** */

i32 sieveUnbounded(){
    unsigned long long i;
    unsigned long long j;

    size_t size = 30000000;

    i32 vec[(i32)pow(10, 9)];

    for(vec[1] = 0, i = 2; i < size; i++)
        vec[i] = 1;

    for(i = 2; i <= size / 2; i++)
        for(j = 2; j <= size / i; j++)
            if((i * j) < size)
                vec[i * j] = 0;

    i32 biggestIdx = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            biggestIdx = i;

    return biggestIdx;
}

/* ******************************************************************************** */

i32 sieveOptimized(){
    unsigned long long i;
    unsigned long long j;

    size_t n = 340000000;

    i32 lp[n+1];
    i32 pr[n+1];

    i32 prCurrent = 0;

    for (i32 i=2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr[prCurrent++] = i;
        }

        for (i32 j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    i32 biggestIdx = 0;

    for(i = 1; i < n; i++)
        if(lp[i])
            biggestIdx = i;

    return biggestIdx;
}

/* ******************************************************************************** */