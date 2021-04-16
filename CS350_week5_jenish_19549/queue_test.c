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

void* cloneChar(void* pItem)
{
	char* p = (char*) pItem;
	char* pClone = (char*) malloc(sizeof(char));
	*pClone = *p;
	return pClone;
}

int main(void) {
    QUEUE* q = createQueue(cloneChar);
    char str[] = "You love NPU";
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        enqueue(q, &str[i]);
        i++;
    }

    i = 0;
    while (!isQueueEmpty(q))
    {
        str[i] = *(char*) front(q);
        dequeue(q);
        i++;
    }

    puts(str);
    destroyQueue(q);
    return 0;
}
