#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"
#include "task2.h"

int main(int argc, const char * argv[]) {
    Person* head = malloc(sizeof(Person));
    head->next = NULL;

    push(head, create("james", "jameson", 1970));
    push(head, create("frank", "frankson", 1972));
    print(head);

    enqueue(head, create("alex", "alexios", 1950));
    print(head);

    Person* person = find(head, "frankson");
    printf("%s %s %d\n", person->name, person->surname, person->DOB);
    
    removePerson(head, person);
    print(head);
    
    return 0;
}

