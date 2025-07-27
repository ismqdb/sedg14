/* ******************************************************************************** */

#include "./parseTree.h"

/* ******************************************************************************** */

struct treeNode* buildParseTree(){
    struct treeNode *x;
    u8 c;

    struct stackArray stack = stackArrayInit(TREE_NODE, 50);

    while(1){
        c = getchar();

        if(c == EOF || c == '\n')
            break;

        if(c == '(' || c == ')' || c == ' ')
            continue;

        x = treeNodeInitChar(c);

        if(c == '+' || c == '*'){
            if(!stackArrayIsEmpty(&stack)){
                x->right = stackArrayPopTreeNode(&stack);
            }
            if(!stackArrayIsEmpty(&stack)){
                x->left = stackArrayPopTreeNode(&stack);
            }
        }

        stackArrayPushTreeNode(&stack, x);
    }

    struct treeNode *returnValue = stackArrayPopTreeNode(&stack);
    return returnValue;
}

/* ******************************************************************************** */