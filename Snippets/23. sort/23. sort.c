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

void insertionSortLargeRecord(int array[], int indexes[], int size){
    int v;
    int j;

    for(int i = 0; i < size; i++)
        indexes[i] = i;

    for(int i = 0; i < size; i++){
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

void insertionSortPointers(int array[], int *indexes[], int size){
    int *v;
    int j;

    for(int i = 0; i < size; i++)
        indexes[i] = &array[i];

    for(int i = 0; i < size; i++){
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

void insitu(int array[], int indexes[], int size){
    int j;
    int k;
    int t;

    for(int i = 0; i < size; i++)
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