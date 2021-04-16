#include<stdio.h>

#include"do.h"
#include"student.h"

void do_student_prompt(void){
     //get all details
     int num;
     float avg;
     printf("Enter student number: ");
     scanf("%d", &num);
     //get average
     printf("Enter student average: ");
     scanf("%f", &avg);
     //create an student object
     student s = {.name = 0, .number = num , .average = avg};
     //add to the array
     int index = student_add_to_array(s);
     //check index
     if(index == -1){
         //error adding
         printf("Student array is full\n");
     }
     else {
         printf("Student added to array at index %d\n", index);
     }
}

//function for printing all students
void do_list_all_students(void){
    //get number of students
    int n = student_get_number();
    printf("Total of %d students\n", n);
    //now print all the students
    for(int i = 0; i < n; i++){
        //get students
        student s = student_get(i);
        //print
        printf("%d - %f\n", s.number, s.average);
    }
}