/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

#include "../../13. queue/13. queueArray.h"
#include "../parse tree/parseTree.h"

/* ******************************************************************************** */

struct treeNodeRS {
    union {
        i32 integer;
    } value;

    struct treeNodeRS *child;
    struct treeNodeRS *sibling;
    struct treeNodeRS *parent;
};

/* ******************************************************************************** */

struct treeNodeRS* createNode(i32);
struct treeNodeRS* insertChild(struct treeNodeRS*, i32);
struct treeNodeRS* insertSibling(struct treeNodeRS*, struct treeNodeRS*, i32);

/* ******************************************************************************** */

void treeNodeRSLevelOrderTraversal(struct treeNodeRS*);
void treeNodeRSExternalPathLen(struct treeNodeRS*, i32, i32*);

/* ******************************************************************************** */

void treeNodeRSVisit(struct treeNodeRS*);

/* ******************************************************************************** */