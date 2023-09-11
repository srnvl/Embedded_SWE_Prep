# include <stdio.h>
# include <stdlib.h>

struct Node{
    int data;
    struct Node* next;
};

struct Node* head = NULL;

void push(int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    head = new_node;
}

struct Node* deletefromNthPosition(struct Node* head, int pos)
{
    if(pos == 0)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    struct Node* curr = head;
    for(int i = 0; i < pos - 1; i++)
    {
        if(curr == NULL || curr->next == NULL)
        {
            return head;
        }
        curr = curr->next;
    }
    
    if(curr == NULL || curr->next == NULL)
    {
        return head;
    }
    
    struct Node* temp = curr->next;
    curr->next = temp->next;
    free(temp);
    return head;
}

struct Node* deleteByValue(struct Node* head, int n)
{
    if(head == NULL)
    {
        return NULL;
    }
    
    if(head->data == n)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    struct Node* curr = head;
    struct Node* prev = NULL;

    while (curr != NULL)
    {
        if (curr->data == n)
        {
            prev->next = curr->next;
            free(curr);
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    return head;
}

void printList(struct Node* head)
{
    struct Node* temp = head;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    
    printList(head);
    
    head = deletefromNthPosition(head, 2);
    
    printList(head);
    
    head = deleteByValue(head, 4);
    
    printList(head);
    return 0;
}
