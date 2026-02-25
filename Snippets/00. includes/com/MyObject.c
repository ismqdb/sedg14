/* ******************************************************************************** */

#include "MyObject.h"

/* ******************************************************************************** */

u_long32 My_AddRef(IMyInterface *This){
    MyObject *obj = (MyObject*)This;
    return ++obj->refCount;
}

/* ******************************************************************************** */

u_long32 My_Release(IMyInterface *This){
    MyObject *obj = (MyObject*)This;
    u_long32 count = --obj->refCount;

    if(count == 0)
        free(obj);

    return count;
}

/* ******************************************************************************** */

h_result My_QueryInterface(IMyInterface *This, REFIID riid, void **ppvObject){
    if(!ppvObject)
        return E_POINTER;

    if(isEqualGUID(riid, &IID_IUnknown) || isEqualGUID(riid, &IID_IMyInterface)){
        *ppvObject = This;
        My_AddRef(This);
        return S_OK;
    }

    *ppvObject = NULL;
    return E_NOINTERFACE;
}

/* ******************************************************************************** */

void My_SayHello(IMyInterface* This) {
    printf("Hello from pure C COM (with our own IUnknown)!\n");
}

/* ******************************************************************************** */

h_result CreateMyObject(IMyInterface **ppObj){
    struct IMyInterfaceVtbl *my_vtbl = 
        (struct IMyInterfaceVtbl*)malloc(sizeof(struct IMyInterfaceVtbl)); 

    my_vtbl->QueryInterface = My_QueryInterface;
    my_vtbl->AddRef = My_AddRef;
    my_vtbl->Release = My_Release;
    my_vtbl->SayHello = My_SayHello;

    if(!ppObj)
        return E_POINTER;

    MyObject *obj = (MyObject*)malloc(sizeof(MyObject));

    if(!obj){
        return E_OUTOFMEMORY;
    }

    obj->interface.lpvtbl = my_vtbl;
    obj->refCount = 1;

    *ppObj = &obj->interface;

    return S_OK;
}

/* ******************************************************************************** */