#pragma once

#include <stdlib.h>

typedef struct dll_node {
    int key;
    struct dll_node *prev;
    struct dll_node *next;
} dll_node;