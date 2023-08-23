# Refer GFG for neat explaination

# Node class
class Node:

	# Constructor to initialize the node object
	def __init__(self, data):
		self.data = data
		self.next = None

class LinkedList:

	# Function to initialize head
	def __init__(self):
		self.head = None

	# Function to insert a new node at the beginning
	def push(self, new_data):
		new_node = Node(new_data)
		new_node.next = self.head
		self.head = new_node

	# Utility function to print the linked LinkedList
	def printList(self):
		temp = self.head
		print(temp.data,end=' ')
		temp = temp.next
		while(temp != self.head):
			print (temp.data,end=' ')
			temp = temp.next

	""" function to insert a new_node in a list in sorted way.
	Note that this function expects a pointer to head node
	as this can modify the head of the input linked list """
	def sortedInsert(self, new_node):
		
		current = self.head

		# Case 1 of the above algo
		if current is None:
			new_node.next = new_node
			self.head = new_node
		
		# Case 2 of the above algo
		elif (current.data >= new_node.data):
			
			# If value is smaller than head's value then we
			# need to change next of last node
			while current.next != self.head :
				current = current.next
			current.next = new_node
			new_node.next = self.head
			self.head = new_node			

		
		# Case 3 of the above algo
		else:
			
			# Locate the node before the point of insertion
			while (current.next != self.head and
				current.next.data < new_node.data):
				current = current.next

			new_node.next = current.next
			current.next = new_node


# Driver program to test the above function
#llist = LinkedList()
arr = [12, 56, 2, 11, 1, 90]

list_size = len(arr)

# start with empty linked list
start = LinkedList()

# Create linked list from the array arr[]
# Created linked list will be 1->2->11->12->56->90
for i in range(list_size):
	temp = Node(arr[i])
	start.sortedInsert(temp)

start.printList()
