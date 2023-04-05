/* 

    Given an integer, find the position of leftmost bit set
    
    Example:
    
    n = 9 (1001)
    Output: 4
    
    n = 4 (100)
    Output: 3


*/

#include<iostream>
using namespace std;


int LeftMostBitSet(int n){
    int pos = 0;
    while(n){
        pos += 1;
        n = n >> 1;
    }
    return pos;
};

int main()
{
    int l1, l2;
    l1 = LeftMostBitSet(9);
    l2 = LeftMostBitSet(4);
    cout << l1 << "\n" << l2 << endl;
    return 0;
}
