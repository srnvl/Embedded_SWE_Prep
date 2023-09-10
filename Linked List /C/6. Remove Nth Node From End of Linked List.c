# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

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

struct Node* removeNthFromEnd(struct Node* head, int n){
    struct Node* curr = head;
    int len = 0;
    while(curr != NULL)
    {
        len = len + 1;
        curr = curr->next;
    }
    // printf("%d", len);
    int k = len - n;

    if(k == 0)
    {
        struct Node* temp = head;
        head = head->next;
        free(temp);
        return head;
    }
    
    curr = head;
    for(int i = 0; i < k - 1; i++)
    {
        curr = curr->next;
    }
    struct Node* temp = curr->next;
    curr->next = curr->next->next;
    free(temp);
    return head;
}

int main()
{
    int n;
    
    push(5);
    push(4);
    push(3);
    push(2);
    push(1);
    
    printlist();
    
    printf("Enter a value for n: ");
    scanf("%d", &n);
    
    head = removeNthFromEnd(head, n);
    
    printlist();
    
}
