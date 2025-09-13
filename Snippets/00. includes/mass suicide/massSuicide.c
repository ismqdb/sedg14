/* ******************************************************************************** */

#include "./massSuicide.h"

/* ******************************************************************************** */

i32 massSuicideArray(i32 n, i32 m){
    if(n <= 0 || m <= 0)
        return -1;

    if(n<m)
        return -1;

    i32 *array = (i32*)malloc(n*sizeof(i32));

    i32 noOfDead = 0;
    i32 currentCount;

    for(i32 i = 0; i < n; i++)
        array[i] = 1;

    i32 i = 0;

    while(noOfDead < (n-1)){
        currentCount = 0;
        i32 idx;

        while(1){
            if(currentCount == m){
                idx = i-1;
                break;
            }
            if(i == n)
                i = 0;
            if(array[i++] == 1)
                currentCount++;
        }

        printf("%d ", idx);
        array[idx] = 0;
        noOfDead++;
    }

    for(i32 i = 0; i < n; i++)
        if(array[i] == 1){
            free(array);
            putchar(10);
            return i;
        }
}

/* ******************************************************************************** */

none massSuicideLinkedList(i32 n, i32 m){
    if(n <= 0 || m <= 0)
        return;

    if(n<m)
        return;

    i32 i;
    struct node *head;

    struct node *t = nodeAlloc();
    t->key = 0;
    head = t;

    for(i = 1; i < n; i++){
        t->next = nodeAlloc();
        t = t->next;
        t->key = i;
    }
    t->next = head;

    while(t != t->next){
        for(i = 0; i < (m-1); i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;
        free(head);
    }

    putchar(10);
}

/* ******************************************************************************** */

none massSuicideRecursiveDriver(i32 n, i32 m){
    i32 i;
    struct node *head;

    struct node *t = nodeAlloc();
    t->key = 0;
    head = t;

    for(i = 1; i < n; i++){
        t->next = nodeAlloc();
        t = t->next;
        t->key = i;
    }
    t->next = head;

    massSuicideRecursive(t, 5);    
    putchar(10);
}

/* ******************************************************************************** */

i32 massSuicideRecursive(struct node *t, i32 m){
    if(t != t->next){
        struct node *head;

        for(i32 i = 0; i < (m-1); i++)
            t = t->next;
            
        printf("%d ", t->next->key);
        head = t->next;
        t->next = t->next->next;
        free(head);

        massSuicideRecursive(t, m);
    }
}

/* ******************************************************************************** */