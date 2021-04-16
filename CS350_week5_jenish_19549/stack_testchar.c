#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 20

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

int main(void) {
	// The demonstration of stack of chars 
    STACK* s = createStack(cloneChar);
    char str[] = "You love NPU";
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        push(s, &str[i]);
        i++;
    }

    i = 0;
    while (!isStackEmpty(s))
    {
        str[i] = *(char*) top(s);
        pop(s);
        i++;
    }

    puts(str);
    destroyStack(s);

    return 0; 
}
