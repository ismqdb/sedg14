#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef enum {INT, TREE_NODE} data_type;

typedef struct tree_node {
    char info;
    struct tree_node* left;
    struct tree_node* right;
} tree_node;

tree_node* n_init(char);
void n_deinit(tree_node*);
void visit_n_f(tree_node*);