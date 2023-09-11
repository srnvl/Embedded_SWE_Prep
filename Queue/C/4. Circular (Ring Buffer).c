// Circular buffer

# include <stdio.h>
# include <stdlib.h>

# define MAX_SIZE 1000

int circularBuffer[MAX_SIZE];
int front = 0;
int rear = 0;

int count = 0; // keeping track of elements

void push(int data)
{
    if(count == 5)
    {
        printf("Buffer is full.\n");
    }
    circularBuffer[rear] = data;
    rear = (rear + 1) % MAX_SIZE;
    count++;
}

int pop()
{
    if(count == 0)
    {
        printf("Buffer is empty.\n");
        return -1;
    }
    int data = circularBuffer[front];
    front = (front + 1) % MAX_SIZE;
    count--;
    return data;
}

void print()
{
    if(count == 0)
    {
        printf("Buffer is empty.\n");
    }
    int tempFront = front;
    for(int i = 0; i < count; i++)
    {
        printf("%d ", circularBuffer[tempFront]);
        tempFront = (tempFront + 1) % MAX_SIZE;
    }
    printf("\n");
}

int main()
{
    push(10);
    push(20);
    push(30);
    push(40);
    
    print();
    
    pop();
    print();
    
    return 0;
}
