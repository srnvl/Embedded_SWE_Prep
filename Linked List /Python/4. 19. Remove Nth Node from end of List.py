# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeNthFromEnd(self, head: Optional[ListNode], n: int) -> Optional[ListNode]:
        temp = head
        count = 0
        while temp is not None:
            count += 1
            temp = temp.next

 # Denoting the index of the node from the start to be removed at the given position from the end
        k = count - n    
        curr = head
        if (k == 0):
            temp = head
            head = head.next
            del temp     # remove the first node
            return head
        for i in range(0, k-1):
            curr = curr.next
        
        temp = curr.next
        curr.next = curr.next.next
        del temp        # delete the given node  
        return head
