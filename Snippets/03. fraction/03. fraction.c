#include "./03. fraction.h"

static void swap(int *x, int *y){
    int z;

    z = *x;
    *x = *y;
    *y = z;
}

static int gcd_mod(int u, int v){
    int t;

    u = abs(u);
    v = abs(v);

    while(u>0){
        if(u<v)
            swap(&u, &v);
        u %= v;
    }
    return v;
}

fraction reduce(fraction x){
    int gcd = gcd_mod(x.numerator, x.denominator);

    x.numerator /= gcd;
    x.denominator /= gcd;

    return x;
}