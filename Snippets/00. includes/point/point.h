/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

/* ******************************************************************************** */

#include "../standardTypes.h"

/* ******************************************************************************** */

struct point {
    i32 x;
    i32 y;
};

/* ******************************************************************************** */

struct point makePoint(i32 x, i32 y);
i32 isSamePoint(struct point*, struct point*);
struct point *middlePoint(struct point*, struct point*);
void drawPoint(struct point*);
void lineSegment(struct point*, struct point*);

/* ******************************************************************************** */