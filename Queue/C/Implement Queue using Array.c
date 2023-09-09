// Implement queue using array

# include <stdio.h>
# include <stdlib.h>

# define MAX_SIZE 100

struct Queue{
    int front, rear, size;
    int array[MAX_SIZE];
};

// function to create a queue

struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*)malloc(sizeof(struct Queue));
    if(!queue)
    {
        printf("Memory allocation failed");
        exit(1);
    }
    queue->front = -1;
    queue->rear = -1;
    queue->size = 0;
    return queue;
};

int isEmpty(struct Queue* queue)
{
    return queue->size == 0;
}

int isFull(struct Queue* queue)
{
    return queue->size == MAX_SIZE;
}

void enQueue(struct Queue* queue, int value)
{
    if (isFull(queue))
    {
        printf("Queue is full");
        exit(1);
    }
    if(queue->front == -1)
    {
        queue->front = 0;
    }
    queue->rear = (queue->rear + 1) % MAX_SIZE;
    queue->array[queue->rear] = value;
    queue->size++;
    printf("Enqueued: %d\n", value);
}

int deQueue(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty");
        exit(1);
    }
    queue->front = (queue->front + 1) % MAX_SIZE;
    int value = queue->array[queue->front];
    queue->size--;
    return value;
}

int size(struct Queue* queue)
{
    return queue->size;
}

int front(struct Queue* queue)
{
    if (isEmpty(queue))
    {
        printf("Queue is empty.\n");
        exit(1);
    }
    return queue->array[queue->front];
}

void printQueue(struct Queue* queue)
{
    int i;
    for(i = queue->front; i <= queue->rear; i++)
    {
        printf("%d", queue->array[i]);
    }
    printf("\n");
}

int main()
{
    struct Queue* queue = createQueue();
    enQueue(queue, 1);
    enQueue(queue, 2);
    enQueue(queue, 3);
    enQueue(queue, 4);

    printQueue(queue);
    
    printQueue(queue);

    printf("Front element: %d\n", front(queue));
    printf("Queue size: %d\n", size(queue));

    printf("Dequeued: %d\n", deQueue(queue));
    printf("Dequeued: %d\n", deQueue(queue));

    printQueue(queue);

    return 0;
}
