# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, x):
#         self.val = x
#         self.next = None

class Solution:
    def getIntersectionNode(self, headA: ListNode, headB: ListNode) -> Optional[ListNode]:
        tempA, tempB = headA, headB
        while(tempA != tempB):
            tempA = tempA.next if tempA is not None else headB
            tempB = tempB.next if tempB is not None else headA
        return tempA
