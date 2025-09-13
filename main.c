/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#include "./Snippets/00. includes/array/array.h"

/* ******************************************************************************** */

i32 main(){
    enum {noOfFloats = 8};

    f32 floats[noOfFloats];

    for(i32 i = 0; i < noOfFloats; i++)
        floats[i] = (f32)i;

    struct array a = fromRawf32(ARRAY_TYPE_FLOAT, floats, noOfFloats); 
    struct array b = arrayCopy(&a);

    struct array c = createArray(ARRAY_TYPE_FLOAT);

    arrayAppend(&c, &a);
    arrayAppend(&c, &b);

    arrayPrint(&a);
    arrayPrint(&b);
    arrayPrint(&c);
}

/* ******************************************************************************** */