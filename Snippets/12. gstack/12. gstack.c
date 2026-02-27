/* ******************************************************************************** */

#include "./12. gstack.h"

/* ******************************************************************************** */

struct gstack* stack_create(size_t elem_size){
    struct gstack *stack = (struct gstack*)malloc(sizeof (struct gstack));

    stack->elem_size = elem_size;
    stack->size = 0;
    stack->capacity = 4;
    stack->data = malloc(elem_size * stack->capacity);

    return stack;
}

/* ******************************************************************************** */

void stack_push(struct gstack *stack, none *elem){
    if(stack->size == stack->capacity){
        stack->capacity *= 2;
        stack->data = realloc(stack->data, stack->capacity * stack->elem_size);
    }

    none *dest = (char*)stack->data + stack->size * stack->elem_size;
    memcpy(dest, elem, stack->elem_size);

    stack->size++;
}

/* ******************************************************************************** */

none stack_pop(struct gstack *stack){
    assert(stack->size > 0);
    stack->size--;
}

/* ******************************************************************************** */

none* stack_top(struct gstack *stack){
    assert(stack->size > 0);
    return (char*)stack->data + (stack->size-1)*stack->elem_size;
}

/* ******************************************************************************** */