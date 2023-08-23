# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    def isPalindrome(self, head: Optional[ListNode]) -> bool:
        temp = head
        stack = []
        isPalin = True
        while temp is not None:
            stack.append(temp)
        
        temp = head
        while temp is not None:
            if temp.val != stack.end():
                isPalin == False
            stack.pop()
            temp = temp.next
            isPalin = True
        return isPalin        
