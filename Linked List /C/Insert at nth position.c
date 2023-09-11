# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* insertAtNth(struct Node* head, int data, int n)
{
    struct Node* new_node = (struct Node*) malloc (sizeof(struct Node));
    new_node->data = data;
    if(n == 0)
    {
        new_node->next = head;
        head = new_node;
        return head;
    }
    struct Node*temp = head;
    for(int i = 0; i < n - 1; i++)
    {
        temp = temp->next;
    }
    new_node->next = temp->next;
    temp->next = new_node;
    return head;
}

void printList(struct Node* head)
{
    struct Node*temp = head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    head = insertAtNth(head, 1, 0);
    head = insertAtNth(head, 2, 1);
    head = insertAtNth(head, 3, 2);
    head = insertAtNth(head, 4, 3);
    
    printList(head);
    
    head = insertAtNth(head, 5, 3);
    
    printList(head);
    return 0;
}
