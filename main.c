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
    enum {size = 20};

    enum {maxKeys = 10};

    i32 elems[size] = {
        0, 1, 2, 3, 4, 5, 6, 7, 8, 9,
        9, 8, 7, 6, 5, 4, 3, 2, 1, 0
    };

    distrCount(elems, size, maxKeys);
}

/* ******************************************************************************** */