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
    enum {noOfElems = 10};
    
    i8 a[noOfElems];

    for(i32 i = noOfElems-1; i > -1; i--){
        a[noOfElems-i-1] = i;
    }

    shellSort(a, noOfElems);
}

/* ******************************************************************************** */