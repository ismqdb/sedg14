/* ******************************************************************************** */

#include "point.h"

/* ******************************************************************************** */

struct point makePoint(i32 x, i32 y){
    assert(x >= 0);
    assert(y >= 0);

    struct point p = {.x = x, .y = y};
    return p;
}

/* ******************************************************************************** */

i32 isSamePoint(struct point *pt1, struct point *pt2){
    return pt1->x == pt2->x && pt1->y == pt2->y;
}

/* ******************************************************************************** */

struct point *middlePoint(struct point *pt1, struct point *pt2){
    struct point *pt = (struct point*)malloc(sizeof(struct point));
    pt->x = (pt1->x+pt2->x)/2;
    pt->y = (pt1->y+pt2->y)/2;
    return pt;
}

/* ******************************************************************************** */

void drawPoint(struct point *pt){
    
}

/* ******************************************************************************** */

void lineSegment(struct point *pt1, struct point *pt2){
    if(!isSamePoint(pt1, pt2)){
        struct point *m = middlePoint(pt1, pt2);
        drawPoint(m);
        lineSegment(pt1, m);
        lineSegment(m, pt2);
    }
}

/* ******************************************************************************** */