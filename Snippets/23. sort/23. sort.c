/* ******************************************************************************** */

#include "./23. sort.h"

/* ******************************************************************************** */

void bubbleSort(i32 array[], i32 size){
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

void selectionSort(i32 array[], i32 size){
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
            t = indexes[i];
            k = i;

            do {
                j = k;
                indexes[j] = array[indexes[j]];
                k = indexes[j];
                indexes[j] = j;
            } while (k != i);
            indexes[j] = t;
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