#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef struct fraction {
    int numerator;
    int denominator;
} fraction;

static void swap(int*, int*);
static int gcd_mod(int, int);

fraction reduce(fraction);