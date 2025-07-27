/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "../00. includes/standardTypes.h"

/* ******************************************************************************** */

void mark(i32, i32);

/* ******************************************************************************** */

/*
* Height of a individual mark of a ruler.
* Implemented as a number of trailing zeroes of a number.
*/
i32 rulerMarkHeight(i32);
void ruleLevelOrder(i32, i32, i32);
void rulePreOrder(i32, i32, i32);
void ruleInOrder(i32, i32, i32);
void ruleIterative(i32, i32, i32);

/* ******************************************************************************** */