#include "person.h"

#define OUTPUT_FILE "output.txt"
#define INPUT_FILE "input.txt"

int insertSorted(Person* head, Person* newPerson);
int insertAfter(Person* head, Person* person, Person* newPerson);
int insertBefore(Person* head, Person* person, Person* newPerson);
int sort(Person* head);
int swap(Person* head, Person** a, Person** b);
int readFromFile(Person* head);
int dumpToFile(Person* head);

//Utility
int print (Person* head);
Person* create(char name[], char surname[], int DOB);