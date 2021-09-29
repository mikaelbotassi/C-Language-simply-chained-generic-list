#include "people.h"

int main(){
    list *l=listInitialized();
    start(l);
    printAllList(l);
    peopleSearch(l);
    printAllList(l);
    freeList(l);
    printAllList(l);

    return 0;
}