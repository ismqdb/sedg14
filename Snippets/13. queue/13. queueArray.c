/* ******************************************************************************** */

#include "./13. queueArray.h"

/* ******************************************************************************** */

void queueArrayPutInt(queueArray *queue, int v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.integer = (int*)realloc(queue->data.integer, queue->current_size*sizeof(int));
    }
    queue->data.integer[queue->tail++] = v;
}

/* ******************************************************************************** */

void queueArrayPutTreeNode(queueArray *queue, treeNode *v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.treeNode = (treeNode**)realloc(queue->data.treeNode, queue->current_size*sizeof(treeNode));
    }
    queue->data.treeNode[queue->tail++] = v;
}

/* ******************************************************************************** */

void queueArrayPutTreeNodeRS(queueArray *queue, struct treeNodeRS *v){
    if(queue->tail == queue->current_size){
        queue->current_size += queue->chunk_size;
        queue->data.tree_node_rs = (struct treeNodeRS**)realloc(queue->data.tree_node_rs, queue->current_size*sizeof(struct treeNodeRS));
    }
    queue->data.tree_node_rs[queue->tail++] = v;
}

/* ******************************************************************************** */

int queueArrayGetInt(queueArray *queue){
    int t = queue->data.integer[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

/* ******************************************************************************** */

treeNode* queueArrayGetTreeNode(queueArray *queue){
    treeNode *t = queue->data.treeNode[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

/* ******************************************************************************** */

struct treeNodeRS* queueArrayGetTreeNodeRS(queueArray *queue){
    struct treeNodeRS *t = queue->data.tree_node_rs[queue->head++];
    if(queue->head == queue->tail){
        queue->head = 0;
        queue->tail = 0;
    }
    return t;
}

/* ******************************************************************************** */

queueArray queueArrayInit(treeNodeDataType type, int size){
    queueArray queue;
    queue.chunk_size = 25;
    queue.current_size = 0;
    queue.type = type;

    queue.current_size = size;

    switch(type){
        case INT:
            queue.data.integer = (int*)malloc(queue.current_size*sizeof(int));
        break;

        case TREE_NODE:
            queue.data.treeNode = (treeNode**)malloc(queue.current_size*sizeof(treeNode));
        break;

        case TREE_NODE_RS:
            queue.data.tree_node_rs = (struct treeNodeRS**)malloc(queue.current_size*sizeof(struct treeNodeRS));
        break;
    }

    queue.head = 0;
    queue.tail = 0;
    return queue;
}

/* ******************************************************************************** */

int queueArrayIsEmpty(queueArray *queue){
    return queue->head == queue->tail;
}

/* ******************************************************************************** */

void queueArrayDeinit(queueArray *queue){
    queue->head = 0;
    queue->tail = 0;

    switch(queue->type){
        case INT:
            free(queue->data.integer);
        break;

        case TREE_NODE:
            free(queue->data.treeNode);
        break;

        case TREE_NODE_RS:
            free(queue->data.tree_node_rs);
        break;

    }
}

/* ******************************************************************************** */