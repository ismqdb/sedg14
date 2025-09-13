/* ******************************************************************************** */

#include "./22. recursionRemovalPreOrder.h"

/* ******************************************************************************** */

none preOrderRR0(struct treeNode *t){
    if(t != NULL){
        visitTreeNode(t);
        preOrderRR0(t->left);
        preOrderRR0(t->right);
    }
}

/* ******************************************************************************** */

none preOrderRR1(struct treeNode *t){
    l:
        if(t == NULL)
            goto x;
        visitTreeNode(t);
        preOrderRR1(t->left);
        t = t->right;
        goto l;
    
    x:
        ;
}

/* ******************************************************************************** */

none preOrderRR2(struct treeNode *t){
    struct stackArray stack = stackArrayInit(TREE_NODE_TYPE_TREE, 50);

    l:
        if(t == NULL)
            goto s;
        visitTreeNode(t);
        stackArrayPushTreeNode(&stack, t->right);
        t = t->left;
        goto l;

    s:
        if(stackArrayIsEmpty(&stack))
            goto x;
        t = stackArrayPopTreeNode(&stack);
        goto l;

    x: 
        stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

none preOrderRR3(struct treeNode *t){
    struct stackArray stack = stackArrayInit(TREE_NODE_TYPE_TREE, 50);

    l:
        while(t != NULL){
            visitTreeNode(t);
            stackArrayPushTreeNode(&stack, t->right);
            t = t->left;
        }

        if(stackArrayIsEmpty(&stack))
            goto x;

        t = stackArrayPopTreeNode(&stack);
        goto l;

    x: 
        stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

none preOrderRR4(struct treeNode *t){
    struct stackArray stack = stackArrayInit(TREE_NODE_TYPE_TREE, 50);

    stackArrayPushTreeNode(&stack, t);

    while(!stackArrayIsEmpty(&stack)){
        t = stackArrayPopTreeNode(&stack);

        while(t != NULL){
           visitTreeNode(t); 
           stackArrayPushTreeNode(&stack, t->right);
           t = t->left;
        }
    }

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */