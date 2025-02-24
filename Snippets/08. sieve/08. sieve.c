/* ******************************************************************************** */

#include "./08. sieve.h"

/* ******************************************************************************** */

int sieve(int size){
    assert(size >= 2);

    int i,j;
    
    int* a = (int*)malloc(size*sizeof(int));

    for(a[1]=0, i=2; i<size; i++)
        a[i]=1;

    for(i=2; i <= size/2; i++)
        for(j=2; j <= size/i; j++)
            if((i*j)<size)
                a[i*j] = 0;

    for(i = 1; i < size; i++)
        if(a[i]){
            int result = a[i];
            free(a);
            return result;
        }
}

/* ******************************************************************************** */

int sieveUnbounded(){
    unsigned long long i;
    unsigned long long j;

    size_t size = 30000000;

    int vec[(int)pow(10, 9)];

    for(vec[1] = 0, i = 2; i < size; i++)
        vec[i] = 1;

    for(i = 2; i <= size / 2; i++)
        for(j = 2; j <= size / i; j++)
            if((i * j) < size)
                vec[i * j] = 0;

    int biggestIdx = 0;

    for(i = 1; i < size; i++)
        if(vec[i])
            biggestIdx = i;

    return biggestIdx;
}

/* ******************************************************************************** */

int sieveOptimized(){
    unsigned long long i;
    unsigned long long j;

    size_t n = 340000000;

    int lp[n+1];
    int pr[n+1];

    int prCurrent = 0;

    for (int i=2; i <= n; ++i) {
        if (lp[i] == 0) {
            lp[i] = i;
            pr[prCurrent++] = i;
        }

        for (int j = 0; i * pr[j] <= n; ++j) {
            lp[i * pr[j]] = pr[j];
            if (pr[j] == lp[i]) {
                break;
            }
        }
    }

    int biggestIdx = 0;

    for(i = 1; i < n; i++)
        if(lp[i])
            biggestIdx = i;

    return biggestIdx;
}

/* ******************************************************************************** */