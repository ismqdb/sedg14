/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

#include "../00. includes/tree node/treeNode.h"
#include "../00. includes/parse tree/parseTree.h"

/* ******************************************************************************** */

#include "../12. stack/12. stackArray.h"
#include "../13. queue/13. queueArray.h"

/* ******************************************************************************** */

none levelOrder(struct treeNode*);
none preOrder(struct treeNode*);
none inOrder(struct treeNode*);
none postOrder(struct treeNode*);

/* ******************************************************************************** */

none preOrderIterative(struct treeNode*);

/* ******************************************************************************** */

none preOrderRecursive(struct treeNode*);
none inOrderRecursive(struct treeNode*);

/* ******************************************************************************** */