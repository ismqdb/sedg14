/* ******************************************************************************** */

#include "./09. listDL.h"

/* ******************************************************************************** */

struct listDL listDLInit(){
    struct listDL list;

    list.head = nodeDLLAlloc();
    list.tail = nodeDLLAlloc();

    list.head->prev = list.head;
    list.head->next = list.tail;

    list.tail->prev = list.head;
    list.tail->next = list.tail;
}

/* ******************************************************************************** */

void listDLDeinit(struct listDL *list){
    free(list->head);
    free(list->tail);
}

/* ******************************************************************************** */

struct nodeDLL* listDLInsertAfter(struct nodeDLL *node, int value){
    struct nodeDLL *new = nodeDLLAlloc();
    new->key = value;

    new->next = node->next;
    node->next = new;
    new->prev = node;

    return new;
}

/* ******************************************************************************** */

void listDLRemoveNext(struct nodeDLL *node){
    node->next = node->next->next;
    node->next->prev = node;
}

/* ******************************************************************************** */