/* ******************************************************************************** */

#include "./12. stackPA.h"

/* ******************************************************************************** */

struct stackPA stackPAInit(i32 size){
    struct stackPA stack;

    stack.keyArray = malloc(size*sizeof(struct node*));
    stack.next = (i32*)malloc(size*sizeof(i32));

    stack.head = 0;
    stack.tail = 1;
    stack.current = 2;

    stack.next[stack.head] = stack.tail;
    stack.next[stack.tail] = stack.tail;

    return stack;
}

/* ******************************************************************************** */

none stackPAPushInt(struct stackPA *stack, i32 v){
    struct node *new = nodeAllocInt(v);
    stack->keyArray[stack->current] = new;

    stack->next[stack->current] = stack->next[stack->head];
    stack->next[stack->head] = stack->current;

    stack->current++;
}

/* ******************************************************************************** */

i32 stackPAIsEmpty(struct stackPA *stack){
    return stack->current == 2;
}

/* ******************************************************************************** */

struct node* stackPAPopNode(struct stackPA *stack){
    if(stackPAIsEmpty(stack))
        return NULL;

    struct node *ret = stack->keyArray[stack->next[stack->head]];

    stack->current = stack->next[stack->head];
    stack->next[stack->head] = stack->next[stack->current];
    stack->next[stack->current] = 0;

    return ret;
}

/* ******************************************************************************** */

none stackPADeinit(struct stackPA *stack){
    stack->next[stack->head] = 0;
    stack->next[stack->tail] = 0;

    stack->head = 0;
    stack->tail = 0;
    stack->current = 0;

    free(stack->keyArray);
}

/* ******************************************************************************** */