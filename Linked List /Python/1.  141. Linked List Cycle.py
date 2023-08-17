# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def hasCycle(self, head: Optional[ListNode]) -> bool:
        s = set()   # Create a set which stores visited nodes
        temp = head
        while temp:
            if temp in s:  # if that particular node is present in set "s"
                return True
            else:
                s.add(temp)  # Add a node if it's unseen
            temp = temp.next
        return False
