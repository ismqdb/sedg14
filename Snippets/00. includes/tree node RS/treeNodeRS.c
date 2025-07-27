/* ******************************************************************************** */

#include "./treeNodeRS.h"

/* ******************************************************************************** */

void treeNodeRSVisit(struct treeNodeRS *node){
    printf("%d\n", node->value.integer);
}

/* ******************************************************************************** */

struct treeNodeRS* createNode(i32 value){
    struct treeNodeRS *t = malloc(sizeof(struct treeNodeRS));
    t->value.integer = value;
    return t;
}

/* ******************************************************************************** */

struct treeNodeRS* insertChild(struct treeNodeRS* node, i32 value){
    struct treeNodeRS *x = createNode(value);
    node->child = x;
    return x;
}

/* ******************************************************************************** */

struct treeNodeRS* insertSibling(struct treeNodeRS *parent, struct treeNodeRS *node, i32 value){
    struct treeNodeRS *x = createNode(value);

    struct treeNodeRS *it = node;

    while(it->sibling != NULL){
        it = it->sibling;
    }

    it->sibling = x;
    it->sibling->parent = parent;

    return it->sibling;
}

/* ******************************************************************************** */

void treeNodeRSLevelOrderTraversal(struct treeNodeRS *node){
    struct queueArray queue = queueArrayInit(INT, 50);
    struct treeNodeRS *temp1, *temp2;

    queueArrayPutTreeNodeRS(&queue, node);

    while(!queueArrayIsEmpty(&queue)){
        node = queueArrayGetTreeNodeRS(&queue);

        treeNodeRSVisit(node);

        if(node->sibling){
            temp1 = node;
            while(1){
                temp2 = temp1->sibling;
                temp1->sibling = NULL;
                queueArrayPutTreeNodeRS(&queue, temp2);

                if(!temp2->sibling)
                    break;

                temp1 = temp2;
            }
        }

        if(node->child)
            queueArrayPutTreeNodeRS(&queue, node->child);
    }

    putchar(10);
}

/* ******************************************************************************** */

void treeNodeRSExternalPathLen(struct treeNodeRS *t, i32 level, i32 *result){
    if(!t) return;

    if(t->child || t->sibling)
        level++;

    if(t->child)
        treeNodeRSExternalPathLen(t->child, level, result);
    else
        result += level;

    if(t->sibling)
        treeNodeRSExternalPathLen(t->sibling, level, result);
    else
        result += level;
}

/* ******************************************************************************** */