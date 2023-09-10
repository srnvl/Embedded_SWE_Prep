#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int data)
{
    struct Node* new_node = (struct Node* )malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

void printlist()
{
    struct Node* temp = head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

struct Node* oddEven(struct Node* head)
{
    if(head == NULL || head->next == NULL)
    {
        return head;
    }
    struct Node* odd = head;
    struct Node* odd_head = odd;
    struct Node* even_head = head->next;
    struct Node* even = even_head;
    while(even && even->next)
    {
        odd->next = even->next;
        odd = odd->next;
        even->next = odd->next;
        even = even->next;
    }
    odd->next = even_head;
    return odd_head;
}

int main()
{
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    
    printlist();
    
    struct Node* result = oddEven(head);
    printlist();
    
}
