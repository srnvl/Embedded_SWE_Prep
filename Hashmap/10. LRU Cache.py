# LRU Cache

'''

Design a data structure that follows the constraints of a Least Recently Used (LRU) cache.

Implement the LRUCache class:

    LRUCache(int capacity) Initialize the LRU cache with positive size capacity.
    int get(int key) Return the value of the key if the key exists, otherwise return -1.
    void put(int key, int value) Update the value of the key if the key exists. Otherwise, add the key-value pair to the cache.
    If the number of keys exceeds the capacity from this operation, evict the least recently used key.

The functions get and put must each run in O(1) average time complexity.

Example 1:

Input
["LRUCache", "put", "put", "get", "put", "get", "put", "get", "get", "get"]
[[2], [1, 1], [2, 2], [1], [3, 3], [2], [4, 4], [1], [3], [4]]
Output
[null, null, null, 1, null, -1, null, -1, 3, 4]

Explanation
LRUCache lRUCache = new LRUCache(2);
lRUCache.put(1, 1); // cache is {1=1}
lRUCache.put(2, 2); // cache is {1=1, 2=2}
lRUCache.get(1);    // return 1
lRUCache.put(3, 3); // LRU key was 2, evicts key 2, cache is {1=1, 3=3}
lRUCache.get(2);    // returns -1 (not found)
lRUCache.put(4, 4); // LRU key was 1, evicts key 1, cache is {4=4, 3=3}
lRUCache.get(1);    // return -1 (not found)
lRUCache.get(3);    // return 3
lRUCache.get(4);    // return 4

 

Constraints:

    1 <= capacity <= 3000
    0 <= key <= 104
    0 <= value <= 105
    At most 2 * 105 calls will be made to get and put.

'''

class Node:
    def __init__(self, key = None, value = None, next = None, prev = None):
        self.key = key
        self.value= value
        self.next = next
        self.prev = prev

class LRUCache:
    def __init__(self, capacity: int):
        self.capacity = capacity
        self.di = {}
        self.head = Node()
        self.tail = Node()
        self.head.next = self.tail
        self.tail.prev = self.head

    # Add at the beginning
    def add_node(self, node: Node):
        node.next = self.head.next
        node.prev = self.head
        self.head.next.prev = node      #self.tail.prev if the list was empty
        self.head.next = node

    def remove_node(self, node: Node):
        node.prev.next = node.next
        node.next.prev = node.prev
    
    def move_to_head(self, node: Node):
        self.remove_node(node)
        self.add_node(node)
    
    def pop_tail(self):
        node = self.tail.prev
        self.remove_node(node)
        return node

    def get(self, key: int) -> int:
        if key not in self.di:
            return -1
        # Retrive the node assoc. with the key
        # and move the value of the key to the head
        node = self.di[key]
        self.move_to_head(node)
        # return value
        return node.value
        
    def put(self, key: int, value: int) -> None:
        if key in self.di:
            # Retrive the node assoc with the key
            # Update the value of the key
            # and move the value of the key to the head
            node = self.di[key]
            node.value = value
            self.move_to_head(node)
        else:
            # Add it to the dictionary and the list
            node = Node(key, value)
            self.di[key] = node
            self.add_node(node)
            if len(self.di) > self.capacity:
                # If capacity is less than the dictionary length
                tail = self.pop_tail()
                del self.di[tail.key]
