#include "../include/slist.h"

SList* create_slist() {
    SList* new_list = (SList*) malloc(sizeof(SList));
    if (new_list == NULL) {
        printf("Error: Malloc could not allocate memmory!\n");
        exit(1);
    }

    new_list->head = NULL;
    return new_list;
}

void slist_push_front(SList* list, Node* n) {
    if (list == NULL) {
        printf("Error: slist_push_front() failed because SList is NULL\n");
    }
    else if (list->head == NULL) {
        list->head = n;
    }
    else {
        Node* tmp = list->head;
        list->head = n;
        n->next = tmp;
    }
}

void slist_push_back(SList* list, Node* n) {
    if (list == NULL) {
        printf("Error: slist_push_back() failed because SList is NULL\n");
    }
    else if (list->head == NULL) {
       list->head = n;
    }
    else {
        Node* tmp = list->head;
        while (tmp->next != NULL) {
            tmp = tmp->next;
        }
        tmp->next = n;
    }
}

char* slist_pop_front(SList* list) {
    if (list == NULL || list->head == NULL) {
        printf("Error: slist_pop_front() failed cause of stack underflow\n");
        return NULL;
    }
    else {
        Node* removed_node = list->head;
        char* removed_node_data = strdup(list->head->data);
        if (removed_node_data == NULL) {
            printf("Error: on slist_pop_front() string memmory allocation failed\n");
            return NULL;
        }

        list->head = list->head->next;

        free(removed_node);
        return removed_node_data;
        // remember to free removed_node_data.
    }
}

char* slist_pop_back(SList* list) {
    if (list == NULL || list->head == NULL) {
        printf("Error: slist_pop_back() failed cause of stack underflow\n");
        return NULL;
    }
    else {
        Node* tmp = list->head;
        Node* prev;
        while (tmp->next != NULL) {
            prev = tmp;
            tmp = tmp->next;
        }

        Node* removed_node = tmp;
        char* removed_node_data = strdup(tmp->data);
        if (removed_node_data == NULL) {
            printf("Error: on slist_pop_front() string memmory allocation failed\n");
            return NULL;
        }

        prev->next = tmp->next;

        free(removed_node);
        return removed_node_data;
        // remember to free removed_node_data.
    }
}

void slist_print(SList* list) {
    if (list == NULL || list->head == NULL) {
        printf("Error: slist_print() was given a NULL list\n");
    }
    else {
        Node* tmp = list->head;
        printf("--- SList ---\n");
        for (int i = 1; tmp != NULL; i++) {
            printf("%d. %s\n", i, tmp->data);
            tmp = tmp->next;
        }
        printf("-------------\n");
    }
}


void slist_free(SList* list) {
    if (list == NULL) {
        return;
    }
    else {
        Node* tmp;
        while (list->head != NULL) {
            tmp = list->head;
            list->head = list->head->next;
            free(tmp);
        }
        free(list);
    }
}
