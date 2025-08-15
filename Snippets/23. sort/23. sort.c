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

void shellSort(i32 array[], i32 size){
    i32 i;
    i32 j;
    i32 h;
    i32 temp;

    for(h = 1; h <= size/9; h = 3*h+1)
        ;

    for(; h > 0; h /= 3){
        for(i = h; i < size; i++){
            temp = array[i];
            j = i;

            while(j>h && array[j-h]>temp){
                array[j] = array[j-h];
                j -= h;
            }
            array[j] = temp;
        }
    }
}

/* ******************************************************************************** */