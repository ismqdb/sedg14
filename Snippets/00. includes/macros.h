/* ******************************************************************************** */

#define heapAllocSized(type, size) ((type*)malloc(size*sizeof(type)))
#define heapAllocArray(type, size) ((type**)malloc(size*sizeof(type)))

#define heapRealloc(type, data, size)\
(data = (type*)realloc(data, size*sizeof(type)))

#define heapArrayRealloc(type, data, size)\
(data = (type**)realloc(data, size*sizeof(type)))

/* ******************************************************************************** */

#define errorAbort(code,text) do { \
    fprintf (stderr, "%s at \"%s\":%d: %s\n", \
        text, __FILE__, __LINE__, strerror (code)); \
    abort (); \
    } while (0)

/* ******************************************************************************** */

#define errnoAbort(text) do { \
    fprintf (stderr, "%s at \"%s\":%d: %s\n", \
        text, __FILE__, __LINE__, strerror (errno)); \
    abort (); \
    } while (0)

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