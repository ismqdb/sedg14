/* ******************************************************************************** */

#include "./12. stackArray.h"

/* ******************************************************************************** */

struct stackArray stackArrayInit(enum stackType type, i32 size){
    struct stackArray stack;

    stack.currentSize = 0;
    stack.chunkSize = 25;
    stack.type = type;

    switch(type){
        case STACK_TYPE_INT:
            stack.data.integer = heapAllocSized(i32, size);
            break;
        case STACK_TYPE_TREE_NODE:
            stack.data.treeNode = heapAllocArray(struct treeNode, size);
            break;
    }

    stack.p = 0;
    stack.currentSize += size;

    #ifdef __linux__
    pthread_mutex_init(&stack.dataMutex, NULL);
    pthread_mutex_init(&stack.ptrMutex, NULL);
    pthread_cond_init(&stack.hasDataCondVar, NULL);
    #endif

    return stack;
}

/* ******************************************************************************** */

none stackArrayDeinit(struct stackArray *stack){
    stack->p = 0;

    switch(stack->type){
        case STACK_TYPE_INT:
            free(stack->data.integer);
            break;
        case STACK_TYPE_TREE_NODE:
            free(stack->data.treeNode);
            break;
    }

    #ifdef __linux__
    pthread_mutex_destroy(&stack->dataMutex);
    pthread_cond_destroy(&stack->hasDataCondVar);
    #endif
}

/* ******************************************************************************** */

none stackArrayPushInt(struct stackArray *stack, i32 v){
    #ifdef __linux__
    pthread_mutex_lock(&stack->dataMutex);
    #endif
    
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        heapRealloc(i32, stack->data.integer, stack->currentSize);
    }

    stack->data.integer[stack->p++] = v;

    #ifdef __linux__
    pthread_cond_signal(&stack->hasDataCondVar);
    pthread_mutex_unlock(&stack->dataMutex);
    #endif
}

/* ******************************************************************************** */

none stackArrayPushTreeNode(struct stackArray *stack, struct treeNode *tnode){
    #ifdef __linux__
    pthread_mutex_lock(&stack->dataMutex);
    #endif
    
    if(stack->p == stack->currentSize){
        stack->currentSize += stack->chunkSize;
        heapArrayRealloc(struct treeNode, stack->data.treeNode, stack->currentSize);
    }

    stack->data.treeNode[stack->p++] = tnode;

    #ifdef __linux__
    pthread_cond_signal(&stack->hasDataCondVar);
    pthread_mutex_unlock(&stack->dataMutex);
    #endif
}

/* ******************************************************************************** */

i32 stackArrayPopInt(struct stackArray *stack){
    #ifdef __linux__
    if(stackArrayIsEmpty(stack))
        pthread_cond_wait(&stack->hasDataCondVar, &stack->dataMutex);

    pthread_mutex_lock(&stack->dataMutex);
    #endif

    i32 value = stack->data.integer[--stack->p];

    #ifdef __linux__
    pthread_mutex_unlock(&stack->dataMutex);
    #endif

    return value;
}

/* ******************************************************************************** */

struct treeNode* stackArrayPopTreeNode(struct stackArray *stack){
    #ifdef __linux__
    if(stackArrayIsEmpty(stack))
        pthread_cond_wait(&stack->hasDataCondVar, &stack->dataMutex);
    
    pthread_mutex_lock(&stack->dataMutex); 
    #endif

    struct treeNode* tnode = stack->data.treeNode[--stack->p];

    #ifdef __linux__
    pthread_mutex_unlock(&stack->dataMutex);
    #endif

    return tnode;
}

/* ******************************************************************************** */

i32 stackArrayIsEmpty(struct stackArray *stack){
    #ifdef __linux__
    pthread_mutex_lock(&stack->ptrMutex);
    #endif
    i32 empty = !stack->p;

    #ifdef __linux__
    pthread_mutex_unlock(&stack->ptrMutex);
    #endif

    return empty;
}

/* ******************************************************************************** */

i32 stackArraySize(struct stackArray *stack){
    #ifdef __linux__
    pthread_mutex_lock(&stack->dataMutex);
    #endif
    i32 size = stack->p > 0 ? stack->p - 1 : 0;

    #ifdef __linux__
    pthread_mutex_unlock(&stack->dataMutex);
    #endif

    return size;
}

/* ******************************************************************************** */