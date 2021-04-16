#include<stdio.h>

#include "student.h"
#include "do.h"


//this function print the menu and returns the
//number entered by the user

int get_user_choice(void){
    printf("Enter you command number:\n");
    printf("1) Add new Student \n");
    printf("2) List number of students \n");
    printf("3) List all students \n");
    printf("-1) Exit program \n");
    printf("cmd: ");
    int n;
    scanf("%d", &n);
    return n;
}

//the main function

int main(){
    printf("CSCI-112-Final Gradebook Code by Your Name\n");
    //loop indefinitely
    int n_students;
    while(1){
        //get choice
        int choice = get_user_choice();
        switch(choice){
            case 1:
                //call the prompt student function
                do_student_prompt();
                break;
            case 2:
                //get the number of students
                n_students = student_get_number();
                printf("Number of student: %d\n", n_students);
                break;
            case 3:
                //print all students
                do_list_all_students();
                break;
            case -1:
                //exit
                printf("All done\n");
                return 0;
            default:
                //print invalid choice
                printf("Invalid choice\n");
        }
    }
}

