/* ******************************************************************************** */

#include "./13. queueArray.h"

/* ******************************************************************************** */

none queueArrayPutInt(struct queueArray *queue, i32 v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.integer = (i32*)realloc(queue->data.integer, queue->current_size*sizeof(i32));
    }
    queue->data.integer[queue->tail++] = v;
}

/* ******************************************************************************** */

none queueArrayPutTreeNode(struct queueArray *queue, struct treeNode *v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.treeNode = 
            (struct treeNode**)realloc(
                queue->data.treeNode, 
                queue->current_size*sizeof(struct treeNode)
            );
    }
    queue->data.treeNode[queue->tail++] = v;
}

/* ******************************************************************************** */

i32 queueArrayGetInt(struct queueArray *queue){
    i32 t = queue->data.integer[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

/* ******************************************************************************** */

struct treeNode* queueArrayGetTreeNode(struct queueArray *queue){
    struct treeNode *t = queue->data.treeNode[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

/* ******************************************************************************** */

struct queueArray queueArrayInit(enum treeNodeType type, i32 size){
    struct queueArray queue;
    queue.chunk_size = 25;
    queue.current_size = 0;
    queue.type = type;

    queue.current_size = size;

    switch(type){
        case STACK_TYPE_TREE:
            queue.data.integer = (i32*)malloc(queue.current_size*sizeof(i32));
        break;

        case TREE_NODE_TYPE_TREE:
            queue.data.treeNode = (struct treeNode**)malloc(
                queue.current_size*sizeof(struct treeNode)
            );
        break;
    }

    queue.head = 0;
    queue.tail = 0;
    return queue;
}

/* ******************************************************************************** */

i32 queueArrayIsEmpty(struct queueArray *queue){
    return queue->head == queue->tail;
}

/* ******************************************************************************** */

none queueArrayDeinit(struct queueArray *queue){
    queue->head = 0;
    queue->tail = 0;

    switch(queue->type){
        case STACK_TYPE_TREE:
            free(queue->data.integer);
        break;

        case TREE_NODE_TYPE_TREE:
            free(queue->data.treeNode);
        break;
    }
}

/* ******************************************************************************** */