/* ******************************************************************************** */

#include "./18. treeTraversal.h"

/* ******************************************************************************** */

none levelOrder(struct treeNode *t){
    struct queueArray queue = queueArrayInit(TREE_NODE_TYPE_TREE, 50);

    queueArrayPutTreeNode(&queue, t);

    while(!queueArrayIsEmpty(&queue)){
        t = queueArrayGetTreeNode(&queue);
        
        visitTreeNode(t);

        if(t->left != NULL)
            queueArrayPutTreeNode(&queue, t->left);

        if(t->right != NULL)
            queueArrayPutTreeNode(&queue, t->right);
    }

    queueArrayDeinit(&queue);
}

/* ******************************************************************************** */

none preOrder(struct treeNode *t){
    struct stackArray stack = stackArrayInit(TREE_NODE_TYPE_TREE, 50);

    stackArrayPushTreeNode(&stack, t);

    while(!stackArrayIsEmpty(&stack)){
        t = stackArrayPopTreeNode(&stack);

        visitTreeNode(t);

        if(t->right != NULL)
            stackArrayPushTreeNode(&stack, t->right);

        if(t->left != NULL)
            stackArrayPushTreeNode(&stack, t->left);
    }

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

none inOrder(struct treeNode *t){
    struct stackArray stack = stackArrayInit(TREE_NODE_TYPE_TREE, 50);
    struct treeNode *temp;
    
    do {
        if(t->left != NULL){
            temp = t->left;
            t->left = NULL;
            stackArrayPushTreeNode(&stack, t);
            t = temp;
        } else {
            visitTreeNode(t);
            t = stackArrayPopTreeNode(&stack);
            
            if(t->right != NULL){
                stackArrayPushTreeNode(&stack, t->right);
                t->right = NULL;
            }
        }
    } while(!stackArrayIsEmpty(&stack));

    visitTreeNode(t);
    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

none postOrder(struct treeNode *t){
    struct stackArray stack = stackArrayInit(TREE_NODE_TYPE_TREE, 50);
    struct treeNode *temp;

    do {
        if(t->left != NULL && t->right != NULL){
            temp = t->right;
            t->right = NULL;
            stackArrayPushTreeNode(&stack, t);
            stackArrayPushTreeNode(&stack, temp);
            t = t->left;
        } else {
            visitTreeNode(t);
            t = stackArrayPopTreeNode(&stack);
        }
    } while(!stackArrayIsEmpty(&stack));

    visitTreeNode(t);

    stackArrayDeinit(&stack);
}

/* ******************************************************************************** */

none preOrderIterative(struct treeNode *t){
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
}

/* ******************************************************************************** */

none preOrderRecursive(struct treeNode *t){
    if(t != NULL){
        visitTreeNode(t);
        preOrderRecursive(t->left);
        preOrderRecursive(t->right);
    }
}

/* ******************************************************************************** */

none inOrderRecursive(struct treeNode *t){
    if(t != NULL){
        inOrderRecursive(t->left);
        visitTreeNode(t);
        inOrderRecursive(t->right);
    }
}

/* ******************************************************************************** */