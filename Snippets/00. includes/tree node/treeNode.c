/* ******************************************************************************** */

#include "./treeNode.h"

/* ******************************************************************************** */

struct treeNode* treeNodeInit(){
    struct treeNode *n = (struct treeNode*)malloc(sizeof(struct treeNode));
    return n;
};

struct treeNode* treeNodeInitChar(u8 c){
    struct treeNode *n = (struct treeNode*)malloc(sizeof(struct treeNode));
    n->info = c;
    return n;
};

void treeNodeDeinit(struct treeNode *n){
    free(n);
}

void visitTreeNode(struct treeNode *t){
    if(t == NULL)
        return;
    
    printf("%c ", t->info);
    fflush(stdout);
}

/* ******************************************************************************** */

i32 tnodeCompare(const void *t1, const void *t2){
    struct tnodePair *d1 = *(struct tnodePair**)t1;
    struct tnodePair *d2 = *(struct tnodePair**)t2;

    return d1->index > d2->index;
}

/* ******************************************************************************** */

i32 binaryTreeDrawRecursive(struct treeNode* t, struct tnodePair **pairs, i32 left, i32 right){
        static i32 current = 0;
        if(t == NULL)
            return -1;
        else {
            struct tnodePair *x = (struct tnodePair*)malloc(sizeof(struct tnodePair));
            x->node = t;
            x->index = (left+right)/2;
            pairs[current++] = x;
        }

        if(t->left != NULL){
            i32 middle = (left+right)/2;
            binaryTreeDrawRecursive(t->left, pairs, left, middle);
        }

        if(t->right != NULL){
            i32 middle = (left+right)/2;
            binaryTreeDrawRecursive(t->right, pairs, middle, right);
        }

        return current;
}

/* ******************************************************************************** */

void externalPathLenTreeNode(struct treeNode *t, i32 level, i32 *len){
    if(t->left || t->right)
        level++;

    if(t->left)
        externalPathLenTreeNode(t->left, level, len);
    else
        len += level;

    if(t->right)
        externalPathLenTreeNode(t->right, level, len);
    else
        len += level;
}

/* ******************************************************************************** */

i32 binaryTreeDrawRecursiveDriver(){
    i32 screenWidth = 80;

    struct treeNode *t = buildParseTree();
    struct tnodePair **pairs = (struct tnodePair**)calloc(20, sizeof(struct tnodePair**));

    i32 k = binaryTreeDrawRecursive(t, pairs, 0, screenWidth);

    qsort(pairs, k, sizeof(struct tnodePair*), tnodeCompare);

    putchar(10);

    for(i32 pos = 0, printed = 0; pos < screenWidth; pos++){
        if(pairs[printed] == NULL)
            continue;

        if(pairs[printed]->index == pos)
            printf("%c", pairs[printed++]->node->info);
        else
            putchar(' ');
    }

    putchar(10);
    putchar(10);

    return 1;
}

/* ******************************************************************************** */