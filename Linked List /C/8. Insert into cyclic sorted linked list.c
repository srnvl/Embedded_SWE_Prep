#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void printlist(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void push(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

struct Node* insertInCyclicList(struct Node* head, struct Node* n)
{
    // If the list is empty, make the new node the head and point it to itself.
    if (head == NULL)
    {
        n->next = n;  // Circular reference to itself.
        head = n;
    }
    else if (n->data <= head->data)
    {
        // If the new node's data is less than or equal to the head's data,
        // insert it before the head.
        struct Node* curr = head;
        while (curr->next != head)
        {
            curr = curr->next;
        }
        curr->next = n;
        n->next = head;
        head = n;
    }
    else
    {
        // Find the correct position to insert the new node.
        struct Node* curr = head;
        while (curr->next != head && curr->next->data < n->data)
        {
            curr = curr->next;
        }
        n->next = curr->next;
        curr->next = n;
    }
    return head;
}

int main() {
    push(11);
    push(9);
    push(7);
    push(3);
    printlist(head);
    
    struct Node* n = (struct Node*)malloc(sizeof(struct Node));
    n->data = 8;
    n->next = NULL;
    
    insertInCyclicList(head, n);
    printf("After insertion:\n");
    printlist(head);

    return 0;
}
