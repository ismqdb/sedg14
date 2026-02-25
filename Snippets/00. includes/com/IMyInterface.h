/* ******************************************************************************** */

#pragma once

/* ******************************************************************************** */

#include "h_result.h"
#include "guid.h"

/* ******************************************************************************** */

typedef struct IMyInterface IMyInterface;

/* ******************************************************************************** */

struct IMyInterfaceVtbl {
    h_result    (*QueryInterface)(IMyInterface *This, REFIID riid, void **ppvObject);
    u_long32    (*AddRef)(IMyInterface *This);
    u_long32    (*Release)(IMyInterface *This);

    void        (*SayHello)(IMyInterface*);
};

/* ******************************************************************************** */

struct IMyInterface {
    struct IMyInterfaceVtbl *lpvtbl;
};

/* ******************************************************************************** */

static const GUID IID_IMyInterface = { 
    0x12345678, 
    0x1234, 
    0x1234,
    {
        0x12,0x34,0x12,0x34,0x12,0x34,0x12,0x34
    } 
};

/* ******************************************************************************** */