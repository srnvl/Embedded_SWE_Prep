# include <iostream>
# define MAX_SIZE 10

using namespace std;

int arr[MAX_SIZE];

int front = 0;
int rear = 0;

bool isFull()
{
    return front == (rear + 1) % MAX_SIZE;
}

bool isEmpty()
{
    return front == rear;
}

void addToQueue(int data)
{
    if(isFull())
    {
        cout << "Queue is full!" << endl;
    }
    arr[rear] = data;
    rear = (rear + 1) % MAX_SIZE;
}

int removeFromQueue()
{
    if(isEmpty())
    {
        cout << "Queue is empty!" << endl;
        return -1;
    }
    int data = arr[front];
    front = (front + 1) % MAX_SIZE;
    return data;
}

void printQueue()
{
    int i = front;
    while (i != rear)
    {
        cout << arr[i] << " ";
        i = (i + 1) % MAX_SIZE;
    }
    cout << endl;
}

int main()
{
    addToQueue(10);
    addToQueue(20);
    addToQueue(30);
    addToQueue(40);
    printQueue();
    
    removeFromQueue();
    printQueue();
    
    return 0;
}
