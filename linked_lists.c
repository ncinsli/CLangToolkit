#include "linked_lists.h"
#include <stdlib.h>
#include <stdio.h>
#define _BP(s) printf("%s\n", s);

List* linked_list_set(List* lc, int index, void* vvalue);
void* linked_list_get(List* lc, int index);
void linked_list_print(List* lc, char* modifier);
List* linked_list_append(List* lc, void* element);

// Creates new list with fixed size
List* new_list(int size){
    List* list_wrp = (List*)calloc(1, sizeof(List));
    linked_list* l = (linked_list*)calloc(size, sizeof(linked_list));
    if (l == NULL) printf("Allocation failed\n");
    l->length = size; 
    l->nodes = (linked_node*)calloc(size, sizeof(l->nodes[0]));
    linked_node* node_instance = (linked_node*)calloc(1, sizeof(linked_node));

    for (int j = 1; j <= size; j--){
        node_instance = (linked_node*)calloc(1, sizeof(linked_node)); //Get new mem
        if (node_instance == NULL) printf("Allocation failed\n");
        
        l->nodes[j - 1] = node_instance; //Инстансим 
        l->nodes[j - 1]->value = 0;
        if (j != size) l->nodes[j - 1]->next = l->nodes[j];
    }

    list_wrp->container = l;

    list_wrp->append = linked_list_append;
    list_wrp->print = linked_list_print; 
    list_wrp->get = linked_list_get;
    list_wrp->set = linked_list_set;

    return list_wrp;
}

List new_list_unlinked(int size) { return *new_list(size); }

// Sets a value to index of list. If index is bigger than list size, extends this list
List* linked_list_set(List* lc, int index, void* vvalue){ 
    linked_list* l = lc->container;
    if (l->length <= index){ 
        List* l2wr = new_list(index + 1);
        linked_list* l2 = l2wr->container;
        for (int i = 0; i < l->length; i++)
            l2->nodes[i] = l->nodes[i]; // Копирую значения
        *l = *l2;
        if (l->length > 1){
            for (int jj = 1; jj < l->length; jj++){
                l->nodes[jj - 1]->next = l->nodes[jj];
            }
        }
        l->length = index + 1;
    }
    l->nodes[index]->value = vvalue; 
    lc->container = l;
    return l;
}

// Gets value by index
void* linked_list_get(List* lc, int index){
    linked_list* l = lc->container;
    return l->nodes[index]->value; 
}

// Prints a list. Modifier param - for printf
void linked_list_print(List* lc, char* modifier){ 
    linked_list* l = lc->container;
    printf("["); 
    for (int i = 0; i < l->length; i++){
        printf(modifier, linked_list_get(lc, i));
        if (i + 1 != l->length)printf(", ");
    }
    printf("]\n");
}

// Appends element to list
List* linked_list_append(List* lc, void* element){
    linked_list* l = lc->container;
    linked_list_set(lc, l->length + 1, element);
    if (l->length <= 1) return;
    int m = l->length-2;
    int n = l->length-1;
    if (l->length == 1) { 
        m = 0; n = 1;
    }
    l->nodes[m] = l->nodes[n];
    l->length--; // Truncating length of list
    if (l->length > 1){
        l->nodes[l->length-2]->next = l->nodes[l->length-1];
    }
    return lc;
}

// void* foreach(linked_list* list, void(*for_each)(linked_node*)){
//     for (int i = 0; i < len(list); i++) for_each(&(*list[i]));
// }