#include "./14. 2d.h"

int two_d_main(){
    #define size 5
    int array[size][size] = {0};

    for(int i = 1; i < size; i++)
        for(int j = 1; j < size; j++)
            if(gcd(i, j) == 1)
                array[i][j] = 1;
            else
                array[i][j] = 0;

    putchar(10); 
}