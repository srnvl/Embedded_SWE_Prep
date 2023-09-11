// queue as linked list

#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct llQueue{
    
    struct Node* front;
    struct Node* rear;
};

struct llQueue* createQueue()
{
    struct llQueue* queue = (struct llQueue* )malloc(sizeof(struct llQueue));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
};

bool isEmpty(struct llQueue *queue)
{
    return queue->front == NULL;
}

void enqueue(struct llQueue *queue, int data)
{
    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = NULL;
    if(isEmpty(queue))
    {
        queue->front = queue->rear = new_node;
    }
    queue->rear->next = new_node;
    queue->rear = new_node;
}

int dequeue(struct llQueue *queue)
{
    if(isEmpty(queue))
    {
        printf("queue is empty. cannot deque\n");
        return -1;
    }
    
    struct Node* temp = queue->front;
    int data = temp->data;
    queue->front = queue->front->next;
    free(temp);
    return data;
}

void printList(struct llQueue *queue)
{
    struct Node* temp = queue->front;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int peek(struct llQueue *queue)
{
    if(isEmpty(queue))
    {
        printf("queue is empty.\n");
        return -1;
    }
    return queue->front->data;
}

int main() {
    
    struct llQueue* queue = createQueue();
    enqueue(queue, 10);
    enqueue(queue, 20);
    enqueue(queue, 30);
    enqueue(queue, 40);
    
    printList(queue);
    
    printf("Peek element is: %d\n", peek(queue));
    
    dequeue(queue);
    
    printList(queue);
    
    printf("Peek element is: %d\n", peek(queue));

    return 0;
}
