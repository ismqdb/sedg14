/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../00. includes/standardTypes.h"

/* ******************************************************************************** */

struct parray {
    u8 *key;
    u8 *next;
    i32 current;
    i32 head;
    i32 tail; 
};

/* ******************************************************************************** */

struct parray parrayInit(i32);
void parrayDeinit(struct parray*);

/* ******************************************************************************** */

void parrayDeleteNext(struct parray*, u8);
u8 parrayInsertAfter(struct parray*, u8, u8);
void parrayPrintAll(struct parray*);

/* ******************************************************************************** */