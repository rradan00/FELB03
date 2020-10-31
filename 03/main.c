#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "task3.h"
#include "person.h"

int main(int argc, const char * argv[]) {
    Person* head = malloc(sizeof(Person));
    head->next = NULL;

    readFromFile(head);

    Person* hank = create("Hank", "Hill", 1921);
    insertAfter(head, head, hank);
    insertBefore(head, hank, create("Jill", "Jillbert", 1961));

    sort(head);

    dumpToFile(head);
    
    return 0;
}




