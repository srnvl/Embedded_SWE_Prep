# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def removeElements(self, head: Optional[ListNode], val: int) -> Optional[ListNode]:
        while head is not None and head.val == val:
            head = head.next

        curr = head 
        while curr is not None and curr.next is not None:
        # Here, we checked for curr.next because we are checking for curr.next.val
        # in the next line of code. If we don't check for curr.next, then we get 
        # an attribute error 
            if curr.next.val == val:
                curr.next = curr.next.next
            else:
                curr = curr.next
        return head 
