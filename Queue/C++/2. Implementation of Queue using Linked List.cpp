// Implementation of Queue using LinkedList

#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Queue
{
private:
    Node* front;
    Node* rear;
public:
    Queue()
    {
        front = NULL;
        rear = NULL;
    }

    void enQueue(int d)
    {
        Node* temp = new Node();
        temp->data = d;
        temp->next = NULL;
        // If Queue is empty
        if(rear == NULL && front == NULL)
        {
            front = rear = temp;
            return;
        }
        rear->next = temp;
        rear = temp;
    }
    void deQueue(){
        // If Queue is empty
        Node* temp = front;
        if(front == NULL)
        {
            return;
        }
        if(front == rear)
        {
            front = rear = temp;
        }
        else
        {
            front = front->next;
        }
        
        delete(temp);
    }
    void display() {
        Node* temp = front;
        while (temp) 
        {
            cout << temp->data << " ";
            temp = temp->next;
        }
        cout << endl;
    }   
};


int main() {
    Queue q;
    q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
    q.enQueue(4);
    q.enQueue(5);
    q.display();
    q.deQueue();
    q.display();
    q.deQueue();
    q.display();
    return 0;
}
