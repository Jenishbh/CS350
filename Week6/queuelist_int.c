#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct node 
{
    void* item;
    struct node* next;
};
typedef struct node NODE;

struct queue
{
    NODE* front;
    NODE* rear;
    void* (*clone)(void*);
};
typedef struct queue QUEUE;

QUEUE* createQueue(void* (*clone)(void*))
{
    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->front = NULL;
    q->rear = NULL;
    q->clone = clone;
    return q;
}

void destroyQueue(void* p)
{
    QUEUE* q = (QUEUE*) p;
    NODE* mover = q->front;
    NODE* temp;
    while (mover)
    {
        temp = mover;
        mover = mover->next;
        free(temp->item);
        free(temp);
    }
    free(q);
}

void enqueue(QUEUE* q, void* newItem) {
    NODE* newNode = (NODE*) malloc(sizeof(NODE));
    newNode->item = q->clone(newItem);
    newNode->next = NULL;
    if (q->rear == NULL)
        q->front = newNode;
    else
        q->rear->next = newNode;
    q->rear = newNode;
}

void dequeue(QUEUE* q) {
    NODE* temp = q->front;
    q->front = q->front->next;
    free(temp->item);
    free(temp);
    if (q->front == NULL)
        q->rear = NULL;
}

void* front(QUEUE* q) {
    return q->front->item;
}

int isQueueFull(QUEUE* q) {
    return 0; 
}

int isQueueEmpty(QUEUE* q) {
    return q->front == NULL;
}

void* cloneInt(void* pItem) {
	int* p = (int*) pItem;
	int* pNew = (int*) malloc(sizeof(int));
	*pNew = *p;
	return pNew;
}

int main(void) {
    QUEUE* q = createQueue(cloneInt);
    int list[] = {10, 20, 30, 40, 50};
    int i;
    	
    for (i = 0; i < 5; i++)
    {
        enqueue(q, &list[i]);
    }
    
    i = 0;
    while (!isQueueEmpty(q))
    {
        list[i++] = *(int*) front(q);
        dequeue(q);
    }
    
    for (i = 0; i < 5; i++)
    {
        printf("%5d", list[i]);
    }

    puts("\n");
    destroyQueue(q);
    return 0; 
}
