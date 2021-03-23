#include <stdio.h>
#include "linked_lists.h"

int main(int argc, char* argv[]){
    List list0 = new_list_unlinked(0);
    list0.append(&list0, "n");
    list0.append(&list0, "i");
    list0.append(&list0, "g");
    list0.append(&list0, "g");
    list0.append(&list0, "e");
    list0.append(&list0, "r");

    list0.print(&list0, "%s");

    system("pause");
    return 0;
}
