/* ******************************************************************************** */

#include "./array.h"

/* ******************************************************************************** */

struct array createArray(enum arrayType t){
    assert(t > ARRAY_TYPE_MIN && t < ARRAY_TYPE_MAX);

    struct array array;

    array.type = t;
    array.size = 0;
    array.capacity = 16;

    switch(array.type){
        case ARRAY_TYPE_INT:
            array.elems.i = heapAllocSized(i32, array.capacity);
            array.elems.i[0] = '\0';
            break;

        case ARRAY_TYPE_FLOAT:
            array.elems.f = heapAllocSized(f32, array.capacity);
            array.elems.f[0] = '\0';
            break;
    }

    return array;
}

/* ******************************************************************************** */

struct array fromRawi32(enum arrayType t, i32 *elems, i32 size){
    assert(t > ARRAY_TYPE_MIN && t < ARRAY_TYPE_MAX);

    struct array array = createArray(t);

    while(array.capacity < size)
        reserve(&array);

    memcpy(array.elems.i, elems, size*sizeof(i32));
    array.size = size;

    return array;
}

/* ******************************************************************************** */

struct array fromRawf32(enum arrayType t, f32 *elems, i32 size){
    assert(t > ARRAY_TYPE_MIN && t < ARRAY_TYPE_MAX);

    struct array array = createArray(t);

    while(array.capacity < size)
        reserve(&array);

    memcpy(array.elems.f, elems, size*sizeof(f32));
    array.size = size;

    memset(elems, '\0', size*sizeof(f32));

    return array;
}

/* ******************************************************************************** */

none destroyArray(struct array *array){
    array->size = 0;

    switch(array->type){
        case ARRAY_TYPE_INT:
            free(array->elems.i);
            break;

        case ARRAY_TYPE_FLOAT:
            free(array->elems.f);
            break;
    }
}

/* ******************************************************************************** */

none reserve(struct array *array){
    array->capacity *= 2;

    switch(array->type){
        case ARRAY_TYPE_INT:
            array->elems.i = 
                heapRealloc(i32, array->elems.i, array->capacity);
            break;

        case ARRAY_TYPE_FLOAT:
            array->elems.f = 
                heapRealloc(f32, array->elems.f, array->capacity);
            break;
    }
}

/* ******************************************************************************** */

none* getBytes(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            return (none*)array->elems.i;

        case ARRAY_TYPE_FLOAT:
            return (none*)array->elems.f;
    }
}

/* ******************************************************************************** */

i32 byteSize(struct array *array){
    switch(array->type){
        case ARRAY_TYPE_INT:
            return sizeof(i32) * array->size;

        case ARRAY_TYPE_FLOAT:
            return sizeof(f32) * array->size;
    }
}

/* ******************************************************************************** */

none inserti32(struct array *array, i32 value){
    if(array->size == array->capacity)
        reserve(array);

    array->elems.i[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none insertf32(struct array *array, f32 value){
    if(array->size == array->capacity)
        reserve(array);

    array->elems.f[array->size] = value;
    array->size++;
}

/* ******************************************************************************** */

none filli32(struct array *array, i32 *ptr, i32 size){
    assert(array->type > ARRAY_TYPE_MIN && array->type < ARRAY_TYPE_MAX);
    memset(array->elems.i, *ptr, size*sizeof(i32));
}

/* ******************************************************************************** */

none fillf32(struct array *array, f32 *ptr, i32 size){
    assert(array->type > ARRAY_TYPE_MIN && array->type < ARRAY_TYPE_MAX);
    memset(array->elems.f, *ptr, size*sizeof(f32));
}

/* ******************************************************************************** */

struct array arrayMove(struct array *src){
    struct array dest = createArray(src->type);

    while(dest.capacity < src->size)
        reserve(&dest);

    switch(src->type){
        case ARRAY_TYPE_INT:
            dest = fromRawi32(src->type, src->elems.i, src->size);
            break;

        case ARRAY_TYPE_FLOAT:
            dest = fromRawf32(src->type, src->elems.f, src->size);
            break;
    }
    dest.size = src->size;

    destroyArray(src);

    return dest;
}

/* ******************************************************************************** */

struct array arrayCopy(struct array *src){
    struct array dest = createArray(src->type);

    while(dest.capacity < src->size)
        reserve(&dest);

    switch(src->type){
        case ARRAY_TYPE_INT:
            dest = fromRawi32(src->type, src->elems.i, src->size);
            break;

        case ARRAY_TYPE_FLOAT:
            dest = fromRawf32(src->type, src->elems.f, src->size);
            break;
    }
    dest.size = src->size;

    return dest;
}

/* ******************************************************************************** */