/* ******************************************************************************** */

#include "./22. recursionRemovalInOrder.h"

/* ******************************************************************************** */

none inOrderRR0(struct treeNode *t){
    if(t != NULL){
        inOrderRR0(t->left);
        visitTreeNode(t);
        inOrderRR0(t->right);
    }
}

/* ******************************************************************************** */

none inOrderRR1(struct treeNode *t){
    struct stackArray stack = stackArrayInit(STACK_TYPE_TREE, 50);

    l:
        if(t == NULL)
            goto r;

        stackArrayPushTreeNode(&stack, t);
        t = t->left;
        goto l;

    r:
        t = stackArrayPopTreeNode(&stack);
        visitTreeNode(t);

        if(t->right == NULL){
            if(stackArrayIsEmpty(&stack))
                goto x;
        }
        else {
            t = t->right;
            goto l;
        }

        goto r;

    x:
        return;
}

/* ******************************************************************************** */