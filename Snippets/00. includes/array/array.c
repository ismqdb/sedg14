/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

struct array createArray(enum treeNodeType type){
    struct array a;

    a.currentSize = 0;
    a.blockSize = 25;
    a.allocatedSize = a.blockSize;
    
    switch(type){
        case TREE_NODE_TYPE_INT:
            a.data.ints = heapAllocSized(i32, a.currentSize);
        break;
    }

    return a;
}

/* ******************************************************************************** */

none destroyArray(struct array *a){
    a->currentSize = 0;

    switch(a->type){
        case TREE_NODE_TYPE_INT:
            free(a->data.ints);
        break;
    }
}

/* ******************************************************************************** */

i32 insertInt(struct array *a, i32 value){
    if(a->currentSize == a->allocatedSize){
        a->allocatedSize += 25;
        a->data.ints = heapRealloc(i32, a->data.ints, a->allocatedSize);
    }
    a->data.ints[a->currentSize] = value;
    a->currentSize++;
}

/* ******************************************************************************** */