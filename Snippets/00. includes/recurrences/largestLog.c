/* ******************************************************************************** */

#include "largestLog.h"

/* ******************************************************************************** */

i32 largestLogRecursive(i32 x){
    if(x < 2)
        return 0;
    else
        return largestLogRecursive(x>>1) + 1;
}

/* ******************************************************************************** */

i32 largestLogIterative(i32 x){
    i32 result = 0;

    for(; x > 1; x >>= 1, result++)
        ;

    return result;
}

/* ******************************************************************************** */

void compareLogs(){
    i32 x = 210556111;
    clock_t t;

    f64 b1;
    f64 b2;
    f64 b3;

    t = clock();
    i32 a1 = (i32)floor(log2(x));
    b1 = ((f64)(clock() - t)) / CLOCKS_PER_SEC;

    t = clock();
    i32 a2 = largestLogRecursive(x);
    b2 = ((f64)(clock() - t)) / CLOCKS_PER_SEC;

    t = clock();
    i32 a3 = largestLogIterative(x);
    b3 = ((f64)(clock() - t)) / CLOCKS_PER_SEC;

    printf("%d %0.3f usecs.\n", a1, b1 * 1000000);
    printf("%d %0.3f usecs.\n", a2, b2 * 1000000);
    printf("%d %0.3f usecs.\n", a3, b3 * 1000000);
}

/* ******************************************************************************** */