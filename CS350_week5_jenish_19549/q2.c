#include<stdio.h>
#include<stdlib.h>
#define N 20

struct queue
{
    void* items[N];
    int front;
    int rear;
    int length;
    void* (*clone) (void*);
};

typedef struct queue QUEUE;

QUEUE* createQueue(void* (*clone) (void*))
{
    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->front = 0;
    q->rear = -1;
    q->length = 0;
    q->clone = clone;
    return q;
}

void destroyQueue(void* p)
{
    QUEUE* q = (QUEUE*) p;
    for (int i = 0; i < q->length; i++)
    {
        free(q->items[i]);
    }
    free(q);
}

void enqueue(QUEUE* q, void* newItem) {
    q->rear = (q->rear + 1) % N;
    q->items[q->rear] = q->clone(newItem);
    q->length++;
}

void dequeue(QUEUE* q) {
	free(q->items[q->front]);
    q->front = (q->front + 1) % N;
    q->length--; 
}

void* front(QUEUE* q) {
    return q->items[q->front]; 
}

int isQueueFull(QUEUE* q) {
    return q->length == N; 
}

int isQueueEmpty(QUEUE* q) {
    return q->length == 0; 
}

void* cloneInt(void* pItem)
{
	char* p = (char*) pItem;
	char* pClone = (char*) malloc(sizeof(char));
	*pClone = *p;
	return pClone;
}

int calculateSum(QUEUE* q)
{
    QUEUE* temp = createQueue(cloneInt);
    int sum=0;
    int *p;

    while(!isQueueEmpty(q))
    {
        p = front(q);
        sum += *p;
        enqueue(temp, q);
        dequeue(q);
        
    }

    while(!isQueueEmpty(temp))
    {
        p = front(temp);
        
        enqueue(q, p);
        dequeue(temp);
    }
    return sum;
}

int main(void) {
    QUEUE* q = createQueue(cloneInt);
    int list[] = {10,20,30,40,50};
    
    for(int i = 0; i<5; i++)
    {
        enqueue(q, &list[i]);
    }
    int sum = calculateSum(q);
    printf("sum = %d\n", sum);

    while (!isQueueEmpty(q))
    {
        printf("%d\n", *(int*) front(q));
        dequeue(q);
        
    }

    
    destroyQueue(q);
    return 0;
}