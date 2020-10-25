#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define NAME_SIZE 256
#define STUDENTS_FILE "students.txt"

typedef struct _student {
    char name[NAME_SIZE];
    char surname[NAME_SIZE]; 
    int score;
    int relative;
} Student;

int read(Student** students, int* count);
int grade(Student* students, int count);
int print(Student* students, int count);

int main(){
    Student* students;
    int count;

    int errors = read(&students, &count);
    if(errors) exit(errors);

    grade(students, count);
    print(students, count);
}

int read(Student** students, int* count){
    FILE* file = fopen(STUDENTS_FILE, "r");
    if(!file) {
        printf("Students file missing or not accessible!\n");
        return 1;
    }

    int n = 0;
    *students = malloc(0);
    while(!feof(file)){
        Student student;
        fscanf(file, " %s %s %d", student.name, student.surname, &student.score);
        *students = realloc(*students, (n + 1)*sizeof(Student));
        (*students)[n] = student;
        n++;
    }
    *count = n;

    return 0;
}

int grade(Student* students, int count){
    int max = 0;
    for(int i = 0; i < count; i++)
        if(students[i].score > max) max = students[i].score;

    for(int i = 0; i < count; i++)
        students[i].relative = round((double)students[i].score/max*100);

    return 0;
}

int print(Student* students, int count){
    for(int i = 0; i < count; i++)
        printf("%-10s %-10s %3d %3d%\n", students[i].name, students[i].surname, students[i].score, students[i].relative);

    return 0;
}