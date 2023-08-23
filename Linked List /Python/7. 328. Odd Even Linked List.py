# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def oddEvenList(self, head: Optional[ListNode]) -> Optional[ListNode]:

        # if list is empty or having a single node:
        if not head or not head.next:
            return head
        
        # separating the list into odd list and even list and combine them
        odd_head = odd = head
        even_head = even = head.next

        while even and even.next:
            odd.next = even.next
            odd = odd.next
            even.next = odd.next
            even = even.next

        # combine the odd list with even list and return it
        odd.next = even_head
        return odd_head
