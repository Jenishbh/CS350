#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50
#define MAX_SIZE 100

struct stack
{
	void* items[N];
	int top;
	void* (*clone) (void*);
};

typedef struct stack STACK;

STACK* createStack(void* (*clone) (void*))
{
    STACK* s = (STACK*) malloc(sizeof(STACK));
    s->top = -1;
    s->clone = clone;
    return s;
}

void destroyStack(void* p)
{
    STACK* s = (STACK*) p;
    for (int i = 0; i <= s->top; i++)
    {
        free(s->items[i]);
    }
    free(s);
}

void push(STACK* s, void* newItem)
{
    s->top++;
    s->items[s->top] = s->clone(newItem); 
}

void pop(STACK* s) {
	free(s->items[s->top]);
    s->top--; 
}

void* top(STACK* s) {
    return s->items[s->top];
}

int isStackFull(STACK* s) {
    return s->top == N - 1;
}

int isStackEmpty(STACK* s) {
    return s->top == -1;
}

void* cloneChar(void* pItem)
{
	char* p = (char*) pItem;
	char* pClone = (char*) malloc(sizeof(char));
	*pClone = *p;
	return pClone;
}


void trimLeading(char * str);
    


int main(void) {
	// The demonstration of stack of chars 
    char str[MAX_SIZE];

    printf("Enter any string: ");
    gets(str);

    printf("\nString before trimming leading whitespace: \n%s", str);

    trimLeading(str);
    printf("\n\nString after trimming leading whitespace: \n%s", str);
    

    return 0; 
}

void trimLeading(char * str)
{
    
    int index, i, j;

    index = 0;

    /* Find last index of whitespace character */
    while(str[index] == ' ' || str[index] == '\t' || str[index] == '\n')
    {
        index++;
    }


    if(index != 0)
    {
        /* Shit all trailing characters to its left */
        i = 0;
        while(str[i + index] != '\0')
        {
            str[i] = str[i + index];
            i++;
        }
        str[i] = '\0'; // Make sure that string is NULL terminated
    }
}