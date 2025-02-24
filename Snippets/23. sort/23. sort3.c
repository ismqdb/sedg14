/* ******************************************************************************** */

#include "./23. sort3.h"

/* ******************************************************************************** */

void sort3(int a[], int n){
    assert(n == 3);

    int t;

    if(a[1] > a[2]){
        t = a[1];
        a[1] = a[2];
        a[2] = t;
    }

    if(a[1] > a[3]){
        t = a[1];
        a[1] = a[3];
        a[3] = t;
    }

    if(a[2] > a[3]){
        t = a[2];
        a[2] = a[3];
        a[3] = t;
    }
}

#define maxn 100

void sort3_driver(){
    int n;
    int i;
    int a[maxn];

    n = 0;
    assert(n <= maxn);

    while(scanf("%d", a[n+1]))
        n++;

    a[0] = 0;
    sort3(a, n);

    for(i = 0; i <= n; i++){
        if(i < n)
            assert(a[i] < a[i+1]);
        printf("%d ", a[i]);
    }

    putchar(10);
}

/* ******************************************************************************** */

void selectionSort(int a[], int n){
    int min;
    int t;

    for(int i = 1; i < n; i++){
        min = i;
        for(int j = i+1; j <= n; j++)
            if(a[j] < a[min])
                min = j;

        t = a[min];
        a[min] = a[i];
        a[i] = t;
    }
}

/* ******************************************************************************** */

void insertionSort(int a[], int n){
    int v;
    int j;

    for(int i = 2; i <= n; i++){
        v = a[i];
        j = i;

        while(a[j-1] > v){
            a[j] = a[j-1];
            j--;
        }
        a[j] = v;
    }
}

/* ******************************************************************************** */

void bubbleSort(int a[], int n){
    int t;

    for(int i = n; i >= 1; i--)
        for(int j = 0; j <= i; j++)
            if(a[j-1] > a[j]){
                t = a[j-1];
                a[j-1] = a[j];
                a[j] = t;
            }
}

/* ******************************************************************************** */