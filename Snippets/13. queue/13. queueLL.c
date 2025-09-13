/* ******************************************************************************** */

#include "./13. queueLL.h"

/* ******************************************************************************** */

struct queueLL queueLLInit(){
    struct queueLL queue;
    queue.head = NULL;

    return queue;
}

/* ******************************************************************************** */

none queueLLPutInt(struct queueLL *queue, i32 value){
    struct node *item = nodeAlloc();
    struct node **p = &queue->head;

    if(queue->head == NULL){
        queue->head = item;
        return;
    }

    while((*p) != NULL)
        p = &(*p)->next;

    (*p) = item;
}

/* ******************************************************************************** */

struct node* queueLLGetNode(struct queueLL *queue){
    struct node *item = queue->head;

    queue->head = queue->head->next;
    return item;
}

/* ******************************************************************************** */

i32 queueLLIsEmpty(struct queueLL *queue){
    return queue->head == NULL;
}

/* ******************************************************************************** */