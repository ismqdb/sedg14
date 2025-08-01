/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/node/node.h"

/* ******************************************************************************** */

struct queueLL {
    struct node *head;
};

/* ******************************************************************************** */

struct queueLL queueLLInit();

/* ******************************************************************************** */

void queueLLPutInt(struct queueLL*, i32);

/* ******************************************************************************** */

struct node* queueLLGetNode(struct queueLL*);

/* ******************************************************************************** */

i32 queueLLIsEmpty(struct queueLL*);

/* ******************************************************************************** */