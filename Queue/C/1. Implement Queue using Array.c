// queue as array

#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

#define MAX_SIZE 100

struct ArrayQueue{
    int front;
    int rear;
    int arr[MAX_SIZE];
};

void initialize(struct ArrayQueue* queue)
{
    queue->front = -1;
    queue->rear = -1;
}

bool isEmpty(struct ArrayQueue* queue)
{
    return queue->front == -1;
}

bool isFull(struct ArrayQueue* queue)
{
    return (queue->rear + 1) % MAX_SIZE == queue->front;
}

void enqueue(struct ArrayQueue* queue, int data)
{
    if(isFull(queue))
    {
        printf("Queue is full. Cannot enqueue element %d.\n", data);
        return;
    }
    if(isEmpty(queue))
    {
        queue->rear = 0;
        queue->front = 0;
    }
    else
    {
        queue->rear = (queue->rear + 1) % MAX_SIZE;
    }
    queue->arr[queue->rear] = data;
    printf("Enqueued %d in the queue.\n", data);
}

int dequeue(struct ArrayQueue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty. Cannot dequeue elements.\n");
        return -1;
    }
    int data = queue->arr[queue->front];
    if(queue->front == queue->rear)
    {
        queue->front = -1;
        queue->rear = -1;
    }
    else
    {
        queue->front = (queue->front + 1) % MAX_SIZE;
    }
    return data;
}

int peek(struct ArrayQueue* queue)
{
    if (isEmpty(queue)) {
        printf("Queue is empty. Cannot peek.\n");
        return -1; // Return an error value
    }
    return queue->arr[queue->front];
}

int main()
{
    struct ArrayQueue queue;
    initialize(&queue);
    enqueue(&queue, 1);
    enqueue(&queue, 2);
    enqueue(&queue, 3);
    enqueue(&queue, 4);
    enqueue(&queue, 5);
    printf("Front element is: %d\n", peek(&queue));
    dequeue(&queue);
    printf("Front element is: %d\n", peek(&queue));
    return 0;
}
