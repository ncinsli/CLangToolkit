#include <stdio.h>
#include "linked_lists.h"

void* iterateInt(void* num){
    if ((int)num % 2 == 0) return "L";
    else return "D";
}

int main(int argc, char* argv[]){
    List l = new _List(0);
    List l1 = new _List(0);
    l.append("HI");
    l.print("%s");
    
    l1.append_("MAN");
    l1.print("%s");
    return 0;
}
