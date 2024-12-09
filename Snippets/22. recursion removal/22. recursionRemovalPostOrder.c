/* ******************************************************************************** */

#include "./22. recursionRemovalPostOrder.h"

/* ******************************************************************************** */

void postOrderRR0(struct treeNode *t){
    if(t != NULL){
        postOrderRR0(t->left);
        postOrderRR0(t->right);
        visitTreeNode(t);
    }
}

/* ******************************************************************************** */

void postOrderRR1(struct treeNode *t){
    struct stackArray stack = stackArrayInit(INT, 50);
    struct treeNode *temp;

    l:
        if(t == NULL)
            goto r;

        stackArrayPushTreeNode(&stack, t);
        t = t->left;
        goto l;

    r:
        t = stackArrayPopTreeNode(&stack);

        if(t->right == NULL){
            if(stackArrayIsEmpty(&stack)){
                visitTreeNode(t);
                goto x;
            }
        }
        else {
            stackArrayPushTreeNode(&stack, t);
            temp = t->right;
            t->right = NULL;
            t = temp;
            goto l;
        }

        visitTreeNode(t);
        goto r;

    x:
        return;
}

/* ******************************************************************************** */