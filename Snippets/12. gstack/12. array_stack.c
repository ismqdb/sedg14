/* ******************************************************************************** */

#include "./12. array_stack.h"

/* ******************************************************************************** */

none array_stack_push(struct i_gstack *self, const none *elem){
    struct array_stack *stack = (struct array_stack*)self;

    if(stack->size == stack->capacity){
        stack->capacity = stack->capacity ? stack->capacity * 2 : 4;
        stack->data = realloc(stack->data, stack->capacity * stack->elem_size);
    }

    none *dst = (char*)stack->data + stack->size * stack->elem_size;
    stack->ops.copy(dst, elem);
    stack->size++;
}

/* ******************************************************************************** */

none array_stack_pop(struct i_gstack *self){
    struct array_stack *stack = (struct array_stack*)self;
    assert(stack->size > 0);

    none *elem = (char*)stack->data + (stack->size-1) * stack->elem_size;
    
    stack->ops.destroy(elem);
    stack->size--;
}

/* ******************************************************************************** */

none *array_stack_top(struct i_gstack *self){
    struct array_stack *stack = (struct array_stack*)self;

    assert(stack->size > 0);

    return (char*)stack->data + (stack->size-1) * stack->elem_size;
}

/* ******************************************************************************** */

struct i_gstack* array_stack_create(size_t elem_size, struct element_ops ops){
    struct array_stack *stack = malloc(sizeof(struct array_stack));
    stack->base.lp_vtbl = &array_stack_vtbl;

    stack->data = NULL;
    stack->elem_size = elem_size;
    stack->size = 0;
    stack->capacity = 0;
    stack->ops = ops;

    return (struct i_gstack*)stack;
}

/* ******************************************************************************** */