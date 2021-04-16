#include<stdio.h>

#include<stdlib.h>

#include<string.h>





//------------------------------------------

// Defination of the structure for stack

//------------------------------------------

typedef struct stack{

char character;

struct stack *link;

}stack;





//----------------------------------------------

// Push function for stack

//----------------------------------------------

void push(struct stack **top, char character)

{

struct stack *temp;

temp=(struct stack*)malloc(sizeof(struct stack));



temp->character = character;

temp->link = *top;

*top = temp;

}



//----------------------------------------

// isEmpty function for stack

//----------------------------------------

int isEmpty(struct stack **top)

{

if(*top == NULL)

return 0;

else

return 1;

}





//--------------------------------

// Pop function for stack

//--------------------------------

char pop(struct stack **top,int *isempty)

{

struct stack *temp=*top;

char character;

int y=isEmpty(&temp);

if(y==0)

{

*isempty = 1;

//printf("stack is empty\n");

return;

}



temp = *top;

character = temp->character;

*top = temp->link;

free(temp);

return character;

}



void delimiterChecker(stack **top,char str[],int length){

char character;

int i = 0,isempty = 0;





while(str[i] != '\0'){

character = str[i];

switch(character){

case '[':

case '(':

case '{':

push(top,character);

break;



case ']':

case ')':

case '}':

pop(top,&isempty);

break;

//default:





}

i++;

}

int y = isEmpty(top);

//printf("y = %d \n",y);

if(!(isEmpty(top)) && isempty == 0 ){

printf("You have entered a valid string. \n");

}

else

printf("You have entered a invalid string.\n");



}



int main(){

stack *top = NULL;

char str[15];

int length;



printf("Enter the string : ");

scanf("%s",str);



length = strlen(str);



delimiterChecker(&top,str,length);



}