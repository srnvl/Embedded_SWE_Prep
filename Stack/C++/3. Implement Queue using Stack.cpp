#include <iostream>
#include <stack>

using namespace std;

struct Queue {

    stack<int> s1, s2;
    
    void enQueue(int x)
    {
        s1.push(x);
    }
    
    int deQueue()
    {
        if(s1.empty() && s2.empty())
        {
            return -1;
        }
        else
        {
            if(s2.empty())
            {
                while(!s1.empty())
                {
                    s2.push(s1.top());
                    s1.pop();
                }
            }
            
            int x = s2.top();
            s2.pop();
            return x;
        }
    }
};


int main()
{
    struct Queue q; 
    q.enQueue(40);
    q.enQueue(30);
    q.enQueue(20);
    q.enQueue(10);
    
    cout << "Top of stack s1 is " << q.s1.top() << endl; 
    
    cout << "Popped out element is: " << q.deQueue() << endl;

    return 0;
}
