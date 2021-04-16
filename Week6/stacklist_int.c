#include<stdio.h>
#include<stdlib.h>

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
    free(temp->item);
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

void* cloneInt(void* pItem) {
	int* p = (int*) pItem;
	int* pNew = (int*) malloc(sizeof(int));
	*pNew = *p;
	return pNew;
}

int main(void) {
    STACK* s = createStack(cloneInt);
    int list[] = {10, 20, 30, 40, 50};
    int i;
    	
    for (i = 0; i < 5; i++)
    {
        push(s, &list[i]);
    }
    
    i = 0;
    while (!isStackEmpty(s))
    {
        list[i++] = *(int*) top(s);
        pop(s);
    }
    
    for (i = 0; i < 5; i++)
    {
        printf("%5d", list[i]);
    }

    puts("\n");
    destroyStack(s);
    return 0; 
}
