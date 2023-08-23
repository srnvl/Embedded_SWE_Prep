/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    bool isPalindrome(ListNode* head) {
        vector<int> stack;
        ListNode* temp = head; 
        while(temp != NULL)
        {
            stack.push_back(temp -> val);
            temp = temp->next;
        }
        temp = head;
        while(temp != NULL)
        {
            if(temp -> val != stack.back())
            {
                return false;
            }
            stack.pop_back();
            temp = temp -> next;
        }
        return true;
    }
};
