#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NAME_SIZE 256

struct _person{
    char name[NAME_SIZE];
    char surname[NAME_SIZE];
    int DOB;
    struct _person* next;
};
typedef struct _person Person;

Person* create(char name[], char surname[], int DOB);
int push(Person** list, Person* new);
int print(Person* list);
int enqueue(Person* list, Person* new);
Person* find(Person* list, char surname[]);
int delete(Person** list, Person* target);

int main(int argc, const char * argv[]) {
    Person* head = NULL;

    push(&head, create("james", "jameson", 1970));
    push(&head, create("frank", "frankson", 1972));
    print(head);

    enqueue(head, create("alex", "alexios", 1950));
    print(head);

    Person* person = find(head, "frankson");
    printf("%s %s %d\n", person->name, person->surname, person->DOB);
    
    delete(&head, person);
    print(head);
    
    return 0;
}

Person* create(char name[], char surname[], int DOB){
    Person* person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    strcpy(person->surname,surname);
    person->DOB = DOB;
    person->next = NULL;
    return person;
}

int push(Person** list, Person* new){
    new->next = *list;
    *list = new;
    return 0;
}

int print(Person* list){
    if(list == NULL) return 0;
    printf("%s %s %d\n", list->name, list->surname, list->DOB);
    return print(list->next);
}

int enqueue(Person* list, Person* new){
    if(list->next) enqueue(list->next, new);
    else list->next = new;
    return 0;
}

Person* find(Person* list, char surname[]){
    if(!list) return NULL;
    if(strcmp(list->surname, surname) == 0) return list;
    else return find(list->next, surname);
}

int delete(Person** list, Person* target){
    Person* current = *list;
    if(current == target) { //first case
        *list = current->next;
        free(current);
        return 0;
    } else if (current->next == target) {
        current->next = target->next;
        free(target);
        return 0;
    } else if(current->next) {
        return delete(&(current->next), target);
    } else
        return 1;
}