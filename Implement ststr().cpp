#include <iostream>
#include <string>

using namespace std;


int ststr(string h, string n)
{
    int x = n.size();
    
    for(int i = 0; i < h.size(); i++)
    {
        if(h[i] == n[0] && h.substr(i, x) == n)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    string h, n;
    cout << "Enter a string: ";
    cin >> h;
    cout << "Enter another string: ";
    cin >> n;
    
    cout << "First occurence of the second string in the main string: " << ststr(h, n) << endl; 
    
    return 0;
}
