/* ******************************************************************************** */

#include "./postfix.h"

/* ******************************************************************************** */

struct array getPostfix(){
    u8 c;
    struct stackLL stack = stackLLInit();

    struct array array = createArray(INT);

    while(1){
        i32 readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            insertInt(&array, (u8)stackLLPopInt(&stack));
        }

        if(c == '+')
            stackLLPushInt(&stack, (i32)c);

        if(c == '*')
            stackLLPushInt(&stack, (i32)c);

        while(c >= '0' && c <= '9'){
            insertInt(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            insertInt(&array, ' ');
            
    }

    while(!stackLLIsEmpty(&stack))
        insertInt(&array, (u8)stackLLPopInt(&stack));

    //printf("\n");
    return array;
}

/* ******************************************************************************** */

i32 evaluate(struct array *array){
    u8 c;
    i32 x;
    i32 sum = 0;

    struct stackLL stack = stackLLInit();
    for(i32 i = 0; i < array->currentSize; i++){
        c = array->data.ints[i];

        if(c == ' ')
            continue;

        x = 0;

        if(c == '+')
            x = stackLLPopInt(&stack) + stackLLPopInt(&stack); 

        if(c == '*')
            x = stackLLPopInt(&stack) * stackLLPopInt(&stack);

        while(c>='0' && c<='9'){
            x = 10*x + (c-'0');
            i++;
            c = array->data.ints[i];
        }
        stackLLPushInt(&stack, x);
    }

    return x;
}

/* ******************************************************************************** */