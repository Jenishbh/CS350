#include<stdio.h>
#include<stdlib.h>
#define N 50

struct queue
{
    char items[N];
    int front;
    int rear;
    int length;
};

typedef struct queue QUEUE;

QUEUE* createQueue()
{
    QUEUE* q = (QUEUE*) malloc(sizeof(QUEUE));
    q->front = 0;
    q->rear = -1;
    q->length = 0;
    return q;
}

void destroyQueue(QUEUE* q)
{
    free(q);
}
void isFull(QUEUE* q){
    return((q->front == 0 && q->rear == q->length-1 || q->front == q->rear+1));
}
void addEnd(QUEUE* q, char newItem) {
    q->rear = (q->rear + 1) % N;
    q->items[q->rear] = newItem;
    q->length++;
}
void addFront(QUEUE* q, char newItem){

    if(q->front == -1){
        q->front = 0;
        q->rear = 0;
    }
    else if (q->front ==0 ){
    q->front = q->length -1;
    }
    else {
        q->front=q->front-1;
    }
    

}

void deleteEnd(QUEUE* q)
{

if(q->front == q->rear){

    q->front=-1;
    q->rear=-1;
}
else if(q->rear == 0){
    q->rear = q->length-1;
}

else{
    q->rear=q->rear-1;
}



}

    void delete(QUEUE* q) {
    q->front = (q->front + 1) % N;
    q->length--; 
}

char front(QUEUE* q) {
    return q->items[q->front]; 
}

int isQueueFull(QUEUE* q) {
    return q->length == N; 
}

int isQueueEmpty(QUEUE* q) {
    return q->length == 0; 
}

int main(void) {
    QUEUE* q = createQueue();
    char str[] = "You love NPU";
    int i;

    i = 0;
    while (str[i] != '\0')
    {
        addFront(q, str[i]);
        i++;
    }

    i = 0;
    while (!isQueueEmpty(q))
    {
        str[i] = front(q);
        delete(q);
        i++;
    }

    puts(str);
    destroyQueue(q);
    return 0;
}
