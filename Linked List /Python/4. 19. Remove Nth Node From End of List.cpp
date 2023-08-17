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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        int count = 0;
        ListNode* curr = head;
        while(curr != NULL)
        {
            count += 1;
            curr = curr->next;
        }
        int k = count - n;  // Denoting the node to be deleted
        curr = head;
        if(k == 0)
        {
            ListNode* temp = head;
            head = head-> next;
            delete temp;
            return head;
        }

        for(int i = 0; i < k - 1; i++)
        {
            curr = curr->next;        // Traversing till the node before that node to be deleted 
        } 
        ListNode *temp = curr->next;
        curr->next = curr->next->next;
        delete temp;
        return head;
    }
};
