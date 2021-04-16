#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    void* item;
    struct node* next;
};
typedef struct node NODE;

struct stack
{
    NODE *top;
    void* (*clone)(void*);
};
typedef struct stack STACK;

STACK* createStack(void* (*clone)(void*))
{
    STACK* s = (STACK*) malloc(sizeof(STACK));
    s->top = NULL;
    s->clone = clone;
    return s;
}

void destroyStack(void* p)
{
    STACK* s = (STACK*) p;
    NODE* mover = s->top;
    NODE* temp;
    while (mover)
    {
        temp = mover;
        mover = mover->next;
        free(temp->item);
        free(temp);
    }
    free(s);
}

void push(STACK* s, void* newItem)
{
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->item = s->clone(newItem);
    newNode->next = s->top;
    s->top = newNode;
}

void pop(STACK* s) {
    NODE* temp = s->top;
    s->top = s->top->next;
    //free(temp->item);
    free(temp);
}

void* top(STACK* s) {
    return s->top->item;
}

int isStackFull(STACK* s) {
    return 0;
}

int isStackEmpty(STACK* s) {
    return s->top == NULL;
}

void* cloneChar(void* pItem) {
	char* p = (char*) pItem;
	char* pNew = (char*) malloc(sizeof(char));
	*pNew = *p;
	return pNew;
}

int getLenght(STACK* s){

    int count = 0;
    NODE* mover =s->top;

    while(mover != NULL){

        count++;
        mover = mover ->next;
    }
    return count;
}

int main(void) {
    STACK* s = createStack(cloneChar);
    char str[] = "You love NPU";
    int len = strlen(str);
    int i = 0;
    
    for (i = 0; i < len; i++)
    {
    	push(s, &str[i]);
    }
    printf("Total number = %d\n", getLenght(s));
    i = 0;
    while (!isStackEmpty(s))
    {
    	str[i++] = *(char*) top(s);
    	pop(s);
    }

    puts(str);
    puts("\n");


    
    destroyStack(s);
    return 0; 
}
