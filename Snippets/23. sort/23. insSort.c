/* ******************************************************************************** */

#include "../00. includes/standardTypes.h"

/* ******************************************************************************** */

#include "23. insSort.h"

/* ******************************************************************************** */

void insertionSort(i32 array[], i32 size){
    for(i32 i = 1; i < size; i++){
        i32 k = i;
        i32 temp = array[k];

        while(temp < array[k-1]){
            array[k] = array[k-1];
            k--;
        }
        array[k] = temp;
    }
}

/* ******************************************************************************** */

void insertionSortLargeRecord(i32 array[], i32 indexes[], i32 size){
    i32 v;
    i32 j;

    for(i32 i = 0; i < size; i++)
        indexes[i] = i;

    for(i32 i = 0; i < size; i++){
        v = indexes[i];
        j = i;

        while(j > 0 && array[indexes[j-1]] > array[v]){
            indexes[j] = indexes[j-1];
            j--;
        }
        indexes[j] = v;
    }
}

/* ******************************************************************************** */

void insitu(i32 array[], i32 indexes[], i32 size){
    i32 j;
    i32 k;
    i32 t;

    for(i32 i = 0; i < size; i++)
        if(indexes[i] != i){
            t = array[i];
            k = i;

            do {
                j = k;
                array[j] = array[indexes[j]];
                k = indexes[j];
                indexes[j] = j;
            } while (k != i);
            array[j] = t;
        }
}

/* ******************************************************************************** */

void insertionSortPointers(i32 array[], i32 *indexes[], i32 size){
    i32 *v;
    i32 j;

    for(i32 i = 0; i < size; i++)
        indexes[i] = &array[i];

    for(i32 i = 0; i < size; i++){
        v = indexes[i];
        j = i;

        while(*indexes[j-1] > *v){
            indexes[j] = indexes[j-1];
            j--;
        }
        indexes[j] = v;
    }
}

/* ******************************************************************************** */