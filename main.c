/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "Snippets/23. sort/23. sort.h"
#include "Snippets/23. sort/23. dcount.h"

/* ******************************************************************************** */

i32 main(){
    enum {size = 15};

    enum {maxKeys = 4};

    i32 in[size] = {
        'A', 'B', 'B', 'A', 'C', 'A', 'D', 'A',
        'B', 'B', 'A', 'D', 'D', 'A', 'B'
    };

    distrCount(in, size, maxKeys);

    putchar(10);
}

/* ******************************************************************************** */