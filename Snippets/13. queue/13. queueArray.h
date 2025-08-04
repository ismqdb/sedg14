/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/treeNodeDataType.h"
#include "../00. includes/tree node/treeNode.h"

/* ******************************************************************************** */

struct queueArray {
    treeNodeDataType type;
    union {
        i32* integer;
        struct treeNode **treeNode;
    } data;
    i32 head;
    i32 tail;
    i32 chunk_size;
    i32 current_size;
};

/* ******************************************************************************** */

void queueArrayPuvtInt(struct queueArray*, i32);
void queueArrayPutTreeNode(struct queueArray*, struct treeNode*);

/* ******************************************************************************** */

i32 queueArrayGetInt(struct queueArray*);
struct treeNode* queueArrayGetTreeNode(struct queueArray*);
struct treeNodeRS* queueArrayGetTreeNodeRS(struct queueArray*);

/* ******************************************************************************** */

struct queueArray queueArrayInit(treeNodeDataType, i32);
void queueArrayDeinit(struct queueArray*);

/* ******************************************************************************** */

i32 queueArrayIsEmpty(struct queueArray*);

/* ******************************************************************************** */