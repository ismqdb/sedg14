/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <ctype.h>

/* ******************************************************************************** */

#include "../00. includes/array/array.h"
#include "../00. includes/node/node.h"

/* ******************************************************************************** */

struct stackLL {
    node *head;
    node *tail;
};

/* ******************************************************************************** */

struct stackLL stackLLInit();
void stackLLDeinit();

/* ******************************************************************************** */

void stackLLPushInt(struct stackLL*, int);

/* ******************************************************************************** */

int stackLLPopInt(struct stackLL*);

/* ******************************************************************************** */

int stackLLIsEmpty(struct stackLL*);

/* ******************************************************************************** */