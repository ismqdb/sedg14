/* ******************************************************************************** */

#include "./10. parray.h"

/* ******************************************************************************** */

struct parray parrayInit(i32 size){
    struct parray array;

    array.key = (u8*)malloc(size*sizeof(u8));
    array.next = (u8*)malloc(size*sizeof(u8));

    array.head = 0;
    array.tail = 1;
    array.current = 2;

    array.next[array.head] = array.tail;
    array.next[array.tail] = array.tail;

    return array;
}

/* ******************************************************************************** */

none parrayDeinit(struct parray *array){
    free(array->key);
    free(array->next);
}

/* ******************************************************************************** */

none parrayDeleteNext(struct parray *array, u8 t){
    array->next[t] = array->next[array->next[t]];
}

/* ******************************************************************************** */

u8 parrayInsertAfter(struct parray *array, u8 newValue, u8 existing){
    array->key[array->current] = newValue;

    array->next[array->current] = array->next[existing];
    array->next[existing] = array->current;

    return array->current++;
}

/* ******************************************************************************** */

none parrayPrintAll(struct parray *array){
    u8 x = array->next[array->head];

    while(x != array->next[x]){
        printf("%c ", array->key[x]);
        x = array->next[x];
    }

    putchar(10);
}

/* ******************************************************************************** */