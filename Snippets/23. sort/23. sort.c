/* ******************************************************************************** */

#include "./23. sort.h"

/* ******************************************************************************** */

none bubbleSort(i32 array[], i32 size){
    i32 temp;

    for(i32 i = size; i >= 1; i--)
        for(i32 j = 0; j <= i; j++)
            if(array[j-1] > array[j]){
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
}

/* ******************************************************************************** */

none selectionSort(i32 array[], i32 size){
    i32 min;
    i32 temp;

    for(i32 i = 0; i < size; i++){
        min = i;

        for(i32 k = i; k < size; k++)
            if(array[k] < array[min])
                min = k;

        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

/* ******************************************************************************** */