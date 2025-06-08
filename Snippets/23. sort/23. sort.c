/* ******************************************************************************** */

#include "./23. sort.h"

/* ******************************************************************************** */

void bubbleSort(int array[], int size){
    int temp;

    for(int i = size; i >= 1; i--)
        for(int j = 0; j <= i; j++)
            if(array[j-1] > array[j]){
                temp = array[j-1];
                array[j-1] = array[j];
                array[j] = temp;
            }
}

/* ******************************************************************************** */

void selectionSort(int array[], int size){
    int min;
    int temp;

    for(int i = 0; i < size; i++){
        min = i;

        for(int k = i; k < size; k++)
            if(array[k] < array[min])
                min = k;

        temp = array[i];
        array[i] = array[min];
        array[min] = temp;
    }
}

/* ******************************************************************************** */

void insertionSort(int array[], int size){
    for(int i = 1; i < size; i++){
        int k = i;
        int temp = array[k];

        while(temp < array[k-1]){
            array[k] = array[k-1];
            k--;
        }
        array[k] = temp;
    }
}

/* ******************************************************************************** */