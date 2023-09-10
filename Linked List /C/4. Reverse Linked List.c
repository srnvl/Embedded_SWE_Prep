#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    if(!new_node)
    {
        printf("Memory allocation failed");
        return;
    }
    new_node->data = data;
    new_node->next= head;
    head = new_node;
}

void printList()
{
    struct Node* temp = head;
    while(temp != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
        
    }
    printf("\n");
}

struct Node* reverseList()
{
    struct Node* curr = head;
    struct Node* prev = NULL;
    
    while(curr)
    {
        struct Node* next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }
    head = prev;
    return head;
}

int main()
{
    
    push(4);
    push(3);
    push(2);
    push(1);
    
    printList();
    
    reverseList();
    printList();
    
    while(head)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}
