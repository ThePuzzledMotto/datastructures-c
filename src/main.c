#include "../include/slist.h"

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv) {

    SList* list = create_slist();

    slist_push_back(list, create_node("First"));
    slist_push_back(list, create_node("Second"));
    slist_push_back(list, create_node("Third"));

    slist_print(list);

    char* front_data = slist_pop_front(list);
    char* last_data = slist_pop_back(list);
    slist_free(list);

    printf("front data: %s\n", front_data);
    free(front_data);

    printf("last data: %s\n", last_data);
    free(last_data);

    return 0;
}
