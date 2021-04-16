// student.h
#ifndef __STUDENT_H__
#define __STUDENT_H__

#define MAX_STUDENTS 32

typedef struct {
     char name[100];
     int number;
     float average;
    } student;

// Returns array index of where student placed in array
int student_add_to_array(student s);

// Returns how many students are in the array

int student_get_number();

// Returns a student at a given index

student student_get(int index);

#endif