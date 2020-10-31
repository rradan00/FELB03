#include "person.h"

Person* create(char name[], char surname[], int DOB);
int push(Person* head, Person* newPerson);
int print(Person* head);
int enqueue(Person* head, Person* newPerson);
Person* find(Person* current, char surname[]);
int removePerson(Person* current, Person* target);

