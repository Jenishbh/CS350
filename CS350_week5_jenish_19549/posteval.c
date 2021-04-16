#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>
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

void* cloneInt(void* pItem)
{
	int* p = (int*) pItem;
	int* pClone = (int*) malloc(sizeof(int));
	*pClone = *p;
	return pClone;
}	

int doParse(char *input)
{
    STACK* stack = createStack(cloneInt);
    int num1, num2, interAns;
    
    while(*input)
    {
        if(isdigit(*input))
        {
            interAns = *input - '0';
            push(stack, &interAns);
        }
        else if (*input == '+' || *input == '-' || *input == '*' || *input == '/')
        {
            num2 = *(int*)top(stack);
            pop(stack);
            num1 = *(int*)top(stack);
            pop(stack);
            
            switch(*input)
            {
                case '+':
                    interAns = num1 + num2;
                    break;
                case '-':
                    interAns = num1 - num2;
                    break;
                case '*':
                    interAns = num1 * num2;
                    break;
                case '/':
                    interAns = num1 / num2;
                    break;
            }
            push(stack, &interAns );
        }
        input++;
    }
    
    interAns = *(int*)top(stack);
    destroyStack(stack);
    return interAns;
}

int main(void) {
	char string[256];
    int output;

    do {
        printf("Enter a string or exit to stop: ");
        gets(string);

        if (strcmp(string, "exit") == 0) {
            break;
        }
    
        output = doParse(string);
        printf("Evaluates to: %d\n", output);
    } while(1);
    
    return 0; 
}
