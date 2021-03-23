typedef struct s_linked_node linked_node;

struct s_linked_node{
    void* value;
    linked_node* next;
};

typedef struct {
    int length;
    linked_node** nodes;
} linked_list;
 
typedef struct s_list List;

struct s_list{
    void* (*get)(List*, int);
    List* (*append)(List*, void*);
    void (*print)(List*, char*);
    List* (*set)(List*, int, void*);
    linked_list* container;
};

List* new_list(int);
List new_list_unlinked(int);
// void* foreach(linked_list*, void(*for_each)(linked_node*));
