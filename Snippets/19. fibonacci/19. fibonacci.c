/* ******************************************************************************** */

#include "./19. fibonacci.h"

/* ******************************************************************************** */


i32 fibonacciIterative(i32 n){
    i32 i;
    i32 array[n+2];
    array[0] = array[1] = 1;

    for(i = 2; i <= n; i++)
        array[i] = array[i-1] + array[i-2];
        
    return array[n];
}

/* ******************************************************************************** */

i32 fibonacciRecursive(i32 n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    return fibonacciRecursive(n-1) + fibonacciRecursive(n-2);
}

/* ******************************************************************************** */

i32 fibonacciRR1(i32 n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    struct stackArray stack = stackArrayInit(INT, 50);

    for(i32 i = n; i >= 2; i--)
        stackArrayPushInt(&stack, i);

    stackArrayPushInt(&stack, 1);

    while(stackArraySize(&stack) > 1){
        i32 n1 = stackArrayPopInt(&stack);
        i32 n2 = stackArrayPopInt(&stack);

        stackArrayPushInt(&stack, n1+n2);
    }  

    return stackArrayPopInt(&stack);
}

/* ******************************************************************************** */

i32 fibonacciRR2(i32 n){
    if(n < 0)
        return -1;

    if(n <= 1)
        return 1;
    
    struct stackArray stack = stackArrayInit(INT, 50);
    i32 array[n+2];

    for(i32 i = n; i >= 2; i--)
        stackArrayPushInt(&stack, i);

    stackArrayPushInt(&stack, 1);

    array[0] = 1;

    for(i32 i = 2; !stackArrayIsEmpty(&stack); i++){
        i32 n1 = stackArrayPopInt(&stack);

        array[i] = n1+array[i-1];
    }  

    return array[n]; 
}

/* ******************************************************************************** */

i32 fibonacciRR3(){
    
}

/* ******************************************************************************** */