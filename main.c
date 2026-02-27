/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* ******************************************************************************** */

#include "Snippets/23. sort/23. qsort.h"
#include "Snippets/12. gstack/12. array_stack.c"

/* ******************************************************************************** */

i32 main(){
    struct element_ops ops = {i32_copy, i32_destroy};
    struct i_gstack *stack = array_stack_create(sizeof(i32), ops);

    i32 a = 10;
    i32 b = 20;

    stack->lp_vtbl->push(stack, &a);
    stack->lp_vtbl->push(stack, &b);

    i32 *top = stack->lp_vtbl->top(stack);
    printf("%d\n", *top);

    stack->lp_vtbl->pop(stack);

    top = stack->lp_vtbl->top(stack);
    printf("%d\n", *top);
}

/* ******************************************************************************** */