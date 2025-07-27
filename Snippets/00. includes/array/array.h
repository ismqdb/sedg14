/* ******************************************************************************** */

#ifndef ARRAY_H
#define ARRAY_H

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

/* ******************************************************************************** */

#include "../treeNodeDataType.h"
#include "../allocMacros.h"
#include "../standardTypes.h"

/* ******************************************************************************** */

struct array {
    treeNodeDataType type;

    union {
        i32* ints;
    } data;

    i32 currentSize;
    i32 allocatedSize;
    i32 blockSize;
};

/* ******************************************************************************** */

struct array createArray(treeNodeDataType);
void destroyArray(struct array*);
i32 insertInt(struct array*, i32);

/* ******************************************************************************** */

#endif

/* ******************************************************************************** */