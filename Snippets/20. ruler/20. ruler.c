/* ******************************************************************************** */

#include "./20. ruler.h"

/* ******************************************************************************** */

none mark(i32 position, i32 size){}

/* ******************************************************************************** */

i32 rulerMarkHeight(i32 num){
    if(num < 1)
        return 1;

    i32 count = 0;

    while((num & 1) == 0){
        count++;
        num >>= 1;
    }

    return count;
}

/* ******************************************************************************** */

none ruleLevelOrder(i32 left, i32 right, i32 tree_height){
    for(i32 i = 1, j = 1; i <= tree_height; i++, j <<= 1)
        for(i32 t = 0; t <= (left + right)/j; t++)
            mark(left + j + t * (j+j), i);
}

/* ******************************************************************************** */

none rulePreOrder(i32 left, i32 right, i32 height){
    i32 middle = (left+right)/2;

    if(height > 0){
        mark(middle, height);
        rulePreOrder(left, middle, height-1);
        rulePreOrder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

none ruleInOrder(i32 left, i32 right, i32 height){
    i32 middle = (left+right)/2;

    if(height > 0){
        ruleInOrder(left, middle, height-1);
        mark(middle, height);
        ruleInOrder(middle, right, height-1);
    }
}

/* ******************************************************************************** */

none ruleIterative(i32 left, i32 right, i32 height){
    for(i32 i = 1; i <= (right-left); i++)
        mark(i, rulerMarkHeight(i));
}

/* ******************************************************************************** */