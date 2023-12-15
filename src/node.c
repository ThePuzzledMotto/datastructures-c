#include "../include/node.h"

Node* create_node(char* data) {
    Node* new_node = (Node*) malloc(sizeof(Node));
    if (new_node == NULL) {
        printf("Error: Malloc could not allocate memory.\n");
        exit(1);
    }

    new_node->data = data;
    new_node->next = NULL;

    return new_node;
}
