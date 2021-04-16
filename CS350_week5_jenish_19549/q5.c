#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define N 50

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

void isPalindrome(char str[]) 
{ 
    // Start from leftmost and rightmost corners of str 
    int l = 0; 
    int h = strlen(str) - 1; 
  
    // Keep comparing characters while they are same 
    while (h > l) 
    { 
        if (str[l++] != str[h--]) 
        { 
            printf("%s is Not Palindrome\n", str); 
            return; 
        } 
    } 
    printf("%s is palindrome\n", str); 
} 


int main(void) {
	 
    
    isPalindrome("ABLE WAS I ERE I SAW ELBA");
    isPalindrome("ABLE WA I ERE I SAW ELBA");
    return 0; 
}
