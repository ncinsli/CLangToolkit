// Некоторые дефы
    #define new *
    #define $$$_Explicit_methods
    #define $$$_Explicit_declarations
    #define $$$_Implicit_declarations
    #define $$$_Implicit_methods
    #define $$$_Constructor
    #define $$$_Globals

    typedef struct s_linked_node linked_node;
    typedef struct s_list List;

struct s_linked_node{
    void* value;
    linked_node* next;
};

struct s_list{
    $$$_Explicit_declarations
        void* (*get_)(List*, int);
        List* (*append_)(List*, void*);
        void (*print_)(List*, char*);
        List* (*set_)(List*, int, void*);
        List* (*forEach_)(List*, void* (*foo(void* element)));

    $$$_Implicit_declarations
        void* (*get)(int);
        List* (*append)(void*);
        void (*print)(char*);
        List* (*set)(int, void*);
        List* (*forEach)(void* (*)(void* element));
    // Поля
        int length;
        linked_node** nodes;
};

$$$_Globals
    List* this;
    List* _List(int);
