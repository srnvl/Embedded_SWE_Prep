#include <iostream>
#include <string>
#include <stack>
#include <vector>

using namespace std;

bool isValid(string s)
{
    stack<char> st;
    for (auto i : s)
    {
        if(i == '(' || i == '{' || i == '[')
        {
            st.push(i);
        }
        else
        {
            if(st.empty() || 
            (i == ')' && st.top() != '(') || 
            (i == '}' && st.top() != '{') || 
            (i == ']' && st.top() != '['))
            {
                return false;
            }
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    string s = "(())";
    string m = "[{[}])";
    int x = isValid(s);
    int y = isValid(m);
    cout << "Condition is " << x << " for s" << endl;
    cout << "Condition is " << y << " for m" << endl;
    return 0;
}
