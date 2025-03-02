/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include <stdio.h>

/* ******************************************************************************** */

/*
* Bitwise equivalent.
*/
int xnor(size_t, size_t);

/* ******************************************************************************** */

/*
* Add immediate shifted.
*/
int addis(int, int);

/* ******************************************************************************** */

/*
* Turn off rightmost one bit.
* Result is zero if none.
*/
size_t torob(size_t);

/* ******************************************************************************** */

/*
* Is power of 2?
*/
int ipot(size_t);

/* ******************************************************************************** */

/*
* Turn on rightmost zero bit.
* Result is all ones if none.
*/
size_t torzb(size_t);

/* ******************************************************************************** */

/*
* Turn off trailing ones.
* Result is x if none.
*/
size_t toto(size_t);

/* ******************************************************************************** */

/*
* Is unsigned of the form pow(2, n) - 1? 
*/
int uptnmo(size_t);

/* ******************************************************************************** */

/*
* Turn on trailing zeroes.
* Result is x if none.
*/
size_t totz(size_t);

/* ******************************************************************************** */

/*
* Single one bit on rightmost zero bit.
* Result is zero if none.
*/
size_t soborzb(size_t);

/* ******************************************************************************** */

/*
* Single zero bit on rightmost one bit.
* Result is all ones if none.
*/
size_t szborob(size_t);

/* ******************************************************************************** */

/*
* Ones instead of trailing zeroes.
* Result is zero if none.
*/
size_t oitz(size_t);

/* ******************************************************************************** */

/*
* Zeroes instead of trailing ones.
* Result is all ones if none.
*/
size_t zito(size_t);

/* ******************************************************************************** */

/*
* Isolate rightmost bit.
* Result is zero if none.
*/
size_t irb(size_t);

/* ******************************************************************************** */

/*
* One instead of rightmost one and trailing zeroes.
* Result is all zeroes if there is no one bit.
* Result is integer one if there is no trailing zeroes.
*/
size_t oirotz(size_t);

/* ******************************************************************************** */

/*
* One instead of rightmost zero and trailing ones.
* Result is all ones if there is no zero bit.
* Result is integer one if there is no trailing ones.
*/
size_t oirzto(size_t);

/* ******************************************************************************** */

/*
* Turn off rightmost contiguous string of ones.
*/
size_t torcso(size_t);

/* ******************************************************************************** */

/*
* Is a non-negative integer of the form:
* pow(2, j) - pow(2, k), for some j >= k >= 0?
*/
int dop(size_t);

/* ******************************************************************************** */