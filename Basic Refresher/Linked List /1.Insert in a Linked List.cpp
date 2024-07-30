#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node* next;
};

Node* head = NULL; //global node

void Insert(int x)
{
    Node* temp = new Node(); // defining a temp node and allocating it space dynamically
    temp->data= x; // giving the new node the reqd. data
    temp->next = head;
    head = temp;
}

void Print()
{
    Node* temp = head;
    while(temp != NULL)
    {
        cout << temp -> data << " ";
        temp = temp->next;
    }
    cout << "\n";
}

int main()
{
    Insert(2);
    Print();
    Insert(3);
    Insert(4);
    Insert(5);
    Print();
    return 0;
}
