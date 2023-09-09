// Implement Queue using Linked List

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

// Defining Node
struct Node{
  int data;
  struct Node* next;
};

// Defining a Queue
struct Queue{
    struct Node* front;
    struct Node* rear;
};

// Function to create a Queue
struct Queue* createQueue()
{
    struct Queue* queue = (struct Queue*) malloc(sizeof(struct Queue));
    if(!queue)
    {
        printf("Allocation failed!");
        exit(1);
    }
    queue->front == NULL;
    queue->rear == NULL;
    return queue;
}

int isEmpty(struct Queue* queue)
{
    return queue->front == NULL;
}

void enQueue(struct Queue* queue, int data)
{
    struct Node* new_node = (struct Node*) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    
    // If queue is empty
    
    if(isEmpty(queue))
    {
        queue->front = queue->rear = new_node;
        return;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

int deQueue(struct Queue* queue)
{
    // If queue is empty
    if(queue->front == NULL)
    {
        printf("Queue is empty!");
        return -1;
    }
    int data = queue->front->data;
    struct Node* temp = queue->front;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

void printQueue(struct Queue* queue)
{
    if(isEmpty(queue))
    {
        printf("Queue is empty!");
        return;
    }
    
    struct Node* temp = queue->front;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
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
    enQueue(queue, 5);
    
    printQueue(queue);
    
    deQueue(queue);
    deQueue(queue);
    
    printQueue(queue);
    
    return 0;
}
