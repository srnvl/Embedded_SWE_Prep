#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int lastStoneWeight(vector<int>& stones) {
    // Use a priority queue to sort this vector in descending order
    priority_queue<int> pq(begin(stones), end(stones));
    
    while(pq.size() > 1) {
        int x = pq.top();
        pq.pop();
        int y = pq.top();
        pq.pop();
        if(x > y) {
            pq.push(x - y);
        }
    }
    
    if (!pq.empty()) {
        return pq.top();
    }
    
    return 0;
}

int main() {
    vector<int> stones = {1, 8, 4, 7, 2, 1, 1};
    int result = lastStoneWeight(stones);
    cout << result << endl;
    return 0;
}
