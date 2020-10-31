#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define INPUT_FILE "input.txt"
#define OUTPUT_FILE "output.txt"

int print (Person* head);
int _print(Person* person);
Person* create(char name[], char surname[], int DOB);

int insertAfter(Person* head, Person* person, Person* newPerson);
int insertBefore(Person* head, Person* person, Person* newPerson);
int _insertBefore(Person* head, Person* current, Person* person, Person* newPerson);
int sort(Person* head);
int _sort(Person* head, Person* current);
int insertSorted(Person* head, Person* newPerson);
int _insertSorted(Person* head, Person* current, Person* newPerson);
int swap(Person* head, Person** aAdr, Person** bAdr);
int _swap(Person* head, Person* current, Person** aAdr, Person** bAdr);
int readFromFile(Person* head);
int dumpToFile(Person* head);
int _dumpToFile(Person* current, FILE* file);

Person* create(char name[], char surname[], int DOB){
    Person* person = (Person*)malloc(sizeof(Person));
    strcpy(person->name, name);
    strcpy(person->surname,surname);
    person->DOB = DOB;
    person->next = NULL;
    return person;
}

int print(Person* head){
    return _print(head->next);
}
int _print(Person* person){
    if(person == NULL) return 0;
    printf("%s %s %d\n", person->name, person->surname, person->DOB);
    return _print(person->next);
}

int insertAfter(Person* head, Person* person, Person* newPerson){
    newPerson->next = person->next;
    person->next = newPerson;
    return 0;
}

int insertBefore(Person* head, Person* person, Person* newPerson){
    return _insertBefore(head, head, person, newPerson);
}
int _insertBefore(Person* head, Person* current, Person* person, Person* newPerson){
    if(current->next == person){
        current->next = newPerson;
        newPerson->next = person;
        return 0;
    } else 
        return _insertBefore(head, current->next, person, newPerson);
}

//looks nice, but slow
//refactor l8r
int sort(Person* head){
    return _sort(head, head->next);
}
int _sort(Person* head, Person* current){
    Person* next = current->next;

    if(!current->next) return 0;
    if(strcmp(current->name, current->next->name) > 0){
        swap(head, &current, &next);
        return _sort(head, head);
    } else
        return _sort(head, next);
}

int swap(Person* head, Person** aAdr, Person** bAdr){
    return _swap(head, head, aAdr, bAdr);
}
int _swap(Person* head, Person* current, Person** aAdr, Person** bAdr){
    Person* a = *aAdr;
    Person* b = *bAdr;
    if(current->next == a){
        current->next = b;
        a->next = b->next;
        b->next = a;
        *aAdr = b;
        *bAdr = a;
        return 0;
    } else
        return _swap(head, current->next, aAdr, bAdr);
}

int insertSorted(Person* head, Person* newPerson){
    if(!head->next) { 
        head->next = newPerson; 
        return 0;
    }
    return _insertSorted(head, head->next, newPerson);
}
int _insertSorted(Person* head, Person* current, Person* newPerson){
    if(strcmp(current->name, newPerson->name) > 0) 
        return insertBefore(head, current, newPerson);
    else
        if(!current->next) { 
            current->next = newPerson;
            return 0;
        }
        return _insertSorted(head, current->next, newPerson);
}

int readFromFile(Person* head){
    FILE* file = fopen(INPUT_FILE, "r");

    if(!file) return 1;

    while(!feof(file)){
        char name[NAME_SIZE];
        char surname[NAME_SIZE];
        int DOB;
        fscanf(file, " %s %s %d", name, surname, &DOB);
        insertSorted(head, create(name, surname, DOB));
    }

    fclose(file);
    return 0;
}

int dumpToFile(Person* head){
    FILE* file = fopen(OUTPUT_FILE, "w");

    if(!file) return 1;

    return _dumpToFile(head->next, file);
}
int _dumpToFile(Person* current, FILE* file){
    if(!current){
        fclose(file);
        return 0;
    } else {
        fprintf(file, "%-10s %-10s %3d\n", current->name, current->surname, current->DOB);
        return _dumpToFile(current->next, file);
    }
}
