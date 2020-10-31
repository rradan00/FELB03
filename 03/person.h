#ifndef PARSER_H
#define PARSER_H

#define NAME_SIZE 256

struct _person{
    char name[NAME_SIZE];
    char surname[NAME_SIZE];
    int DOB;
    struct _person* next;
};
typedef struct _person Person;

#endif