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
NODE* getMaxItem(STACK* s){
        int t = s.top;

}
int main(void) {
    STACK* s1 = createStack(cloneInt);
    int list1[] = {10, 20, 30, 40, 50};
    STACK* s2 = createStack(cloneInt);
    int list2[] = {10, 20, 30, 40};
    int i;
    	
    for (i = 0; i < 5; i++)
    {
        push(s1, &list1[i]);
    }
    for (i = 0; i < 5; i++)
    {
        push(s2, &list2[i]);
    }
    NODE* max = getMaxItem(s);
    printf("TOtal Number = %d\n\n", *(int*) max->item);
    i = 0;
    while (!isStackEmpty(s1))
    {
        list1[i++] = *(int*) top(s1);
        pop(s1);
    }
    while (!isStackEmpty(s2))
    {
        list2[i++] = *(int*) top(s2);
        pop(s2);
    }
    
    for (i = 0; i < 5; i++)
    {
        printf("%5d", list1[i]);
    }
    for (i = 0; i < 5; i++)
    {
        printf("%5d", list2[i]);
    }

    puts("\n");
    destroyStack(s1);
    destroyStack(s2);
    return 0; 
}
