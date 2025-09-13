/* ******************************************************************************** */

#include "./postfix.h"

/* ******************************************************************************** */

struct array getPostfix(){
    u8 c;
    struct stackLL stack = stackLLInit();

    struct array array = createArray(ARRAY_TYPE_INT);

    while(1){
        i32 readResult = scanf("%1c", &c);
        if(readResult == EOF || c == '\n')
            break;

        if(c == ')'){
            arrayInsert_i32(&array, (u8)stackLLPopInt(&stack));
        }

        if(c == '+')
            stackLLPushInt(&stack, (i32)c);

        if(c == '*')
            stackLLPushInt(&stack, (i32)c);

        while(c >= '0' && c <= '9'){
            arrayInsert_i32(&array, c);
            scanf("%1c", &c);
        }

        if(c != '(')
            arrayInsert_i32(&array, ' ');
            
    }

    while(!stackLLIsEmpty(&stack))
        arrayInsert_i32(&array, (u8)stackLLPopInt(&stack));

    return array;
}

/* ******************************************************************************** */

i32 evaluate(struct array *array){
    u8 c;
    i32 x;
    i32 sum = 0;

    struct stackLL stack = stackLLInit();
    for(i32 i = 0; i < array->size; i++){
        c = array->elems.i[i];

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
            c = array->elems.i[i];
        }
        stackLLPushInt(&stack, x);
    }

    return x;
}

/* ******************************************************************************** */