/* ******************************************************************************** */

#include "23. qsort.h"

/* ******************************************************************************** */

i32 partition(i32 array[], i32 left, i32 right){
    i32 i;
    i32 pivot;
    i32 j;
    i32 temp;

    if (right > left) {
        pivot = array[right];
        i = left - 1;
        j = right;

        while (1) {
            while (array[++i] < pivot)
                ;

            while (array[--j] > pivot)
                ;

            if (i >= j) break;

            temp = array[i];
            array[i] = array[j];
            array[j] = temp;
        }

        temp = array[i];
        array[i] = array[right];
        array[right] = temp;
    }

    return i;
}

/* ******************************************************************************** */

none quicksort(i32 array[], i32 left, i32 right){
    i32 i;

    if(right > left){
        i = partition(array, left, right);
        quicksort(array, left, i-1);
        quicksort(array, i+1, right);
    }
}

/* ******************************************************************************** */