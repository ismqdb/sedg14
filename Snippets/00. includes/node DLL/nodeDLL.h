/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdlib.h>

/* ******************************************************************************** */

struct nodeDLL {
    int key;
    struct nodeDLL *prev;
    struct nodeDLL *next;
};

/* ******************************************************************************** */