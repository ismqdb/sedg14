/* ******************************************************************************** */

#define runningTime(function, result) do { \
    clock_t t; \
    f64 sec;\
    \
    t = clock(); \
    \
    function; \
    sec = ((f64)(clock() - t)) / CLOCKS_PER_SEC; \
    result = sec; \
    } \
    while(0)

/* ******************************************************************************** */