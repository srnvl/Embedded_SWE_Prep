# include <iostream>
# include <stdlib.h>

using namespace std;

class Node{
public:
    int data;
    Node* next;
};

class Stack{
    Node* top;
    
public:
    Stack()
    {
        top = NULL;
    }
    
    bool isEmpty()
    {
        return top == NULL;
    }
    
    void push(int data)
    {
        Node* new_node = new Node();
        new_node->data = data;
        new_node->next = top;
        top = new_node;
    }
    
    int pop()
    {
        if(isEmpty())
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else{
            Node* temp = top;
            int data = top->data;
            top = top->next;
            delete temp;
            return data;
        }
    }
    
    int peek()
    {
        if(isEmpty())
        {
            cout << "Empty" << endl;
            return -1;
        }
        else{
            return top->data;
        }
    }
    
};


int main()
{
    class Stack s;
    s.push(40);
    s.push(30);
    s.push(20);
    s.push(10);
    
    int x = s.peek();
    cout << "Top value is: " << x << endl;
    
    s.pop();
    int y = s.peek();
    cout << "Top value is: " << y << endl;
    return 0;
}
