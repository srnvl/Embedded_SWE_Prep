#include <iostream>
#include <stack>
#define MAX 1000

using namespace std;

class Stack{
    int top;
    
public:
    int a[MAX];
    Stack(){
        top = -1;
    }
    
    // void push(int x);
    // int pop();
    // int peek();
    // bool isEmpty();
    // bool isFull();
    
    bool isFull()
    {
        return (top >= MAX - 1);
    }
    
    bool isEmpty()
    {
        return (top < 0);
    }


    void push(int x)
    {
        if(isFull() == true)
        {
            cout << "Stack is full!" << endl;
            return;
        }
        a[++top] = x;
        cout << "Pushed " << x << " onto the stack" << endl;
        
    }
    
    int pop()
    {
        if(isEmpty() == true)
        {
            cout << "Stack is empty!" << endl;
            return -1;
        }
        else
        {
            int x = a[top--];
            cout << "Popped " << x << " from the stack" << endl;
            return x;
        }
    }
    
    int peek()
    {
        int x = a[top];
        return x;
    }
    
};

// bool Stack:: isFull()
// {
//     return (top >= MAX - 1);
// }

// bool Stack:: isEmpty()
// {
//     return (top < 0);
// }


// void Stack:: push(int x)
// {
//     if(isFull() == true)
//     {
//         cout << "Stack is full!" << endl;
//         return;
//     }
//     a[++top] = x;
//     cout << "Pushed " << x << " onto the stack" << endl;
// }

// int Stack:: pop()
// {
//     if(isEmpty() == true)
//     {
//         cout << "Stack is empty!" << endl;
//         return -1;
//     }
//     else
//     {
//         int x = a[top--];
//         cout << "Popped " << x << " from the stack" << endl;
//         return x;
//     }
// }

// int Stack:: peek()
// {
//     int x = a[top];
//     return x;
// }


int main()
{
    class Stack s;
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    
    s.pop();
    int x = s.peek();
    cout << "Current top value is: " << x << endl;
    

    return 0;
}
