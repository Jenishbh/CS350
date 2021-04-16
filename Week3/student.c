#include "student.h"

//create an array of students
static student studentArray[MAX_STUDENTS];
//a variable to represent the current number of students
static int numStudents = 0;


//implement add to array
int student_add_to_array(student s){
    //if all places are filled then return -1
    if(numStudents == MAX_STUDENTS)
        return -1;
    //else add to the array
    studentArray[numStudents] = s;
    //increase number of student and return index
    return numStudents++;
}

int student_get_number(){
    //return numstudent
    return numStudents;
}

student student_get(int index){
    //check if index is out of range
    if(index < 0 || index >= numStudents){
        student empty = {.name = 0, .number = 0 , .average = 0};
        return empty;
    }
    //return data
    return studentArray[index];
}