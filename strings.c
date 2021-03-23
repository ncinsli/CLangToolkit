#include "strings.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

void string_print(string* str);
string string_add(string* origin1, char* concat);


string* new_string(){
    string* new_str = (string*)calloc(1, sizeof(string));
    new_str->symbols = new_list(0);
    new_str->print = string_print;
    new_str->add = string_add;
    return new_str;
}

void string_print(string* str){
    int max_len = str->symbols->container->length;
    printf("[");
    int i = 0;
    while (str->symbols->container->nodes[i] != '\0'){
        printf("%s <-", str->symbols->container->nodes[i]->value);
        i++;
    }
}

string string_add(string* origin, char* concat){
    for (int i = 0; i < (int)strlen(concat); i++){
        origin->symbols->append(origin->symbols, (const char*)concat[i]);   
    }
    // printf("%s", origin->symbols->container->nodes[0]->value);
    // origin->symbols->print(origin->symbols, "%s");
    return *origin;
}

string new_string_unlinked() { return *new_string(); }