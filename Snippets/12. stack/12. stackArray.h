/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>
#include <pthread.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"

#include "../00. includes/allocMacros.h"
#include "../00. includes/errorMacros.h"

/* ******************************************************************************** */

struct stackArray {
    enum treeNodeType type;
    union {
        i32* integer;
        struct treeNode** treeNode;
    } data;
    i32 p;
    i32 currentSize;
    i32 chunkSize;

    pthread_mutex_t dataMutex;
    pthread_mutex_t ptrMutex;
    pthread_cond_t hasDataCondVar;
};

/* ******************************************************************************** */

none stackArrayPushInt(struct stackArray*, i32);
none stackArrayPushTreeNode(struct stackArray*, struct treeNode*);

/* ******************************************************************************** */

i32 stackArrayPopInt(struct stackArray*);
struct treeNode* stackArrayPopTreeNode(struct stackArray*);

/* ******************************************************************************** */

struct stackArray stackArrayInit(enum treeNodeType, i32);

/* ******************************************************************************** */

none stackArrayDeinit(struct stackArray*);

/* ******************************************************************************** */

i32 stackArrayIsEmpty(struct stackArray*);

/* ******************************************************************************** */

i32 stackArraySize(struct stackArray*);

/* ******************************************************************************** */