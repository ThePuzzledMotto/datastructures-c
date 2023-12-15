#ifndef NODE_H
#define NODE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char* data;
    struct Node* next;
}
Node;

Node* create_node(char* data);

#endif
