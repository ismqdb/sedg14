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

void stackLLPushInt(struct stackLL *stack, int v){
    node *t = nodeAlloc();
    t->key = v;
    t->next = stack->head->next;
    stack->head->next = t; 
}

/* ******************************************************************************** */

int stackLLPopInt(struct stackLL *stack){
    int x;
    node *t = stack->head->next;
    stack->head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

/* ******************************************************************************** */

int stackLLIsEmpty(struct stackLL *stack){
    return stack->head->next == stack->tail;
}

/* ******************************************************************************** */