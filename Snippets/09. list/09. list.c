/* ******************************************************************************** */

#include "./09. list.h"

/* ******************************************************************************** */

struct list listInit(){
    struct list list;

    list.head = nodeAlloc();
    list.tail = nodeAlloc();

    list.head->next = list.tail;
    list.tail->next = list.tail;

    return list;
}

/* ******************************************************************************** */

none listDeleteNext(struct node *t){
    struct node *x = t->next;
    t->next = t->next->next;
    nodeDealloc(x);
}

/* ******************************************************************************** */

struct node* listInsertAfter(i32 v, struct node *t){
    if(t == NULL)
        return NULL;

    struct node *x = nodeAlloc();
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

/* ******************************************************************************** */

struct node* listMoveNextToFront(struct list *list, struct node *t){
    struct node *temp = t->next;
    t->next = t->next->next;
    
    temp->next = list->head->next;
    list->head->next = temp;
    return temp;
}

/* ******************************************************************************** */

none listExchange(struct node *t, struct node *u){
    struct node *temp = t->next;
    
    t->next = t->next->next;
    temp->next = u->next->next;
    
    u->next->next = t->next;
    t->next = u->next;

    u->next = temp;
}

/* ******************************************************************************** */