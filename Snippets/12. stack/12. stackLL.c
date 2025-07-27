/* ******************************************************************************** */

#include "./12. stackLL.h"

/* ******************************************************************************** */

struct stackLL stackLLInit(){
    struct stackLL stack;
    
    stack.head = nodeAlloc();
    stack.tail = nodeAlloc();

    stack.head->next = stack.tail;
    stack.head->key = 0;
    stack.tail->next = stack.tail;

    return stack;
}

/* ******************************************************************************** */

void stackLLPushInt(struct stackLL *stack, i32 v){
    struct node *t = nodeAlloc();
    t->key = v;
    t->next = stack->head->next;
    stack->head->next = t; 
}

/* ******************************************************************************** */

i32 stackLLPopInt(struct stackLL *stack){
    i32 x;
    struct node *t = stack->head->next;
    stack->head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

/* ******************************************************************************** */

i32 stackLLIsEmpty(struct stackLL *stack){
    return stack->head->next == stack->tail;
}

/* ******************************************************************************** */