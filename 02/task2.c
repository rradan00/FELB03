#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "person.h"

Person* create(char name[], char surname[], int DOB){
    Person* person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    strcpy(person->surname,surname);
    person->DOB = DOB;
    person->next = NULL;
    return person;
}

int push(Person* head, Person* newPerson){
    newPerson->next = head->next;
    head->next = newPerson;
    return 0;
}

int print(Person* head){
    Person* next = head->next;
    if(next == NULL) return 0;
    printf("%s %s %d\n", next->name, next->surname, next->DOB);
    return print(next);
}

int enqueue(Person* head, Person* newPerson){
    if(head->next) enqueue(head->next, newPerson);
    else head->next = newPerson;
    return 0;
}

Person* find(Person* current, char surname[]){
    Person* next = current->next;
    if(!next) return NULL;
    if(strcmp(next->surname, surname) == 0) return next;
    else return find(next, surname);
}

int removePerson(Person* current, Person* target){
    Person* next = current->next;
    if(next == target){
        current->next = target->next;
        free(target);
        return 1;
    } else
        return removePerson(next, target);
}