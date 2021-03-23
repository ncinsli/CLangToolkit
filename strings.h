#include "linked_lists.h"

typedef struct s_string string;

struct s_string {
    List* symbols;
    void (*print)(string*);
    string (*add)(string*, char*);
};

string* new_string();
string new_string_unlinked();