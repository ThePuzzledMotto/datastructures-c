#ifndef SINGLYLINKEDLIST_H
#define SINGLYLINKEDLIST_H

#include "./node.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct SList {
    Node* head;
}
SList;

SList* create_slist();

void slist_push_front(SList* list, Node* n);
void slist_push_back(SList* list, Node* n);

// after calling pop functions remember to free the returned data.
char* slist_pop_front(SList* list);
char* slist_pop_back(SList* list);

void slist_print(SList* list);
void slist_free(SList* list);

#endif
