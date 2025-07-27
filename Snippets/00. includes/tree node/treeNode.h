/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../parse tree/parseTree.h"

/* ******************************************************************************** */

struct treeNode {
    u8 info;
    struct treeNode* left;
    struct treeNode* right;
};

/* ******************************************************************************** */

struct tnodePair {
    struct treeNode *node;
    i32 index;
};

/* ******************************************************************************** */

struct treeNode* treeNodeInit();
struct treeNode* treeNodeInitChar(u8);

/* ******************************************************************************** */

void treeNodeDeinit(struct treeNode*);

/* ******************************************************************************** */

i32 binaryTreeDrawRecursive(struct treeNode*, struct tnodePair**, i32, i32);
void externalPathLenTreeNode(struct treeNode*, i32, i32*);
i32 binaryTreeDrawRecursiveDriver();
void visitTreeNode(struct treeNode*);
i32 tnodeCompare(const void*, const void*);

/* ******************************************************************************** */