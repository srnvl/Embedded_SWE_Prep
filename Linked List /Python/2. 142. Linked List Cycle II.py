# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def detectCycle(self, head: Optional[ListNode]) -> Optional[ListNode]:
        temp = head
        s = set()
        while temp is not None:
            if temp in s:
                return temp
            else:
                s.add(temp)
                temp = temp.next
        return None
