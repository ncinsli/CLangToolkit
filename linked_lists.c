#include "linked_lists.h"
#include <stdlib.h>
#include <stdio.h>
#define _BP(s) printf("%s\n", s);

$$$_Implicit_declarations
    List* linked_list_set(int index, void* vvalue);
    void* linked_list_get(int index);
    void linked_list_print(char* modifier);
    List* linked_list_append(void* element);
    List* linked_list_foreach(void* (*foo)(void* element));

$$$_Explicit_methods
    void* linked_list_get_explicit(List* l, int index){
        this = l;
        return linked_list_get(index);
    }

    List* linked_list_append_explicit(List* l, void* element){
        this = l;
        return linked_list_append(element);
    }

    void linked_list_print_explicit(List* l, char* modifier){
        this = l;
        linked_list_print(modifier);
    }
    List* linked_list_set_explicit(List* l, int index, void* vvalue){
        this = l;
        linked_list_set(index, vvalue);
    }

    List* linked_list_foreach_explicit(List* l, void* (*foo(void* element))){
        this = l;
        linked_list_foreach(foo);
    }


$$$_Constructor
List* _List(int size){ 
    List* list_wrp = (List*)calloc(1, sizeof(List));
    List* l = (List*)calloc(1, sizeof(List));
    if (l == NULL) printf("Allocation failed\n");
    l->length = size; 
    l->nodes = (linked_node*)calloc(size, sizeof(l->nodes[0]));
    linked_node* node_instance = (linked_node*)calloc(1, sizeof(linked_node));

    for (int j = 1; j <= size; j++){
        node_instance = (linked_node*)calloc(1, sizeof(linked_node)); //Get new mem
        if (node_instance == NULL) printf("Allocation failed\n");
        
        l->nodes[j - 1] = node_instance; //Инстансим 
        l->nodes[j - 1]->value = 0;
        if (j != size) l->nodes[j - 1]->next = l->nodes[j];
    }

    list_wrp = l;

    list_wrp->append = linked_list_append;
    list_wrp->print = linked_list_print; 
    list_wrp->get = linked_list_get;
    list_wrp->set = linked_list_set;
    list_wrp->forEach = linked_list_foreach;

    list_wrp->get_ = linked_list_get_explicit;
    list_wrp->set_ = linked_list_set_explicit;
    list_wrp->print_ = linked_list_print_explicit;
    list_wrp->append_ = linked_list_append_explicit;
    list_wrp->forEach_ = linked_list_foreach_explicit;
    
    return list_wrp;
}


// Sets a value to index of list. If index is bigger than list size, extends this list
List* linked_list_set(int index, void* vvalue){ 
    if (this->length <= index){ 
        List* l2wr = _List(index + 1);
        List* l2 = l2wr;
        for (int i = 0; i < this->length; i++)
            l2->nodes[i] = this->nodes[i]; // Копирую значения
        *this = *l2;
        if (this->length > 1){
            for (int jj = 1; jj < this->length; jj++){
                this->nodes[jj - 1]->next = this->nodes[jj];
            }
        }
        this->length = index + 1;
        free(l2wr);
    }
    this->nodes[index]->value = vvalue; 
    return this;
}

// Gets value by index
void* linked_list_get(int index){
    List* l = this;
    return l->nodes[index]->value; 
}

// Prints a list. Modifier param - for printf
void linked_list_print(char* modifier){ 
    List* l = this;
    printf("["); 
    for (int i = 0; i < l->length; i++){
        printf(modifier, linked_list_get(i));
        if (i + 1 != l->length)printf(", ");
    }
    printf("]\n");
}

// Appends element to list
List* linked_list_append(void* element){
    List* l = this;
    linked_list_set(l->length + 1, element);
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
    return this;
}

List* linked_list_foreach(void* (*callback)(void* element)){
     for (int i = 0; i < this->length; i++) this->nodes[i] = callback(this->nodes[i]->value);
}