// stack as linked list

# include <stdio.h>
# include <stdbool.h>
# include <stdlib.h>

struct Node
{
    int data;
    struct Node* next;
};

struct llStack{
    struct Node* top;
};

bool isEmpty(struct llStack* stack)
{
    return stack->top == NULL;
}

void push(struct llStack* stack, int data)
{
    struct Node* new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = stack->top;
    stack->top = new_node;
    printf("Pushed %d onto the stack\n", new_node->data);
}

int pop(struct llStack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty!");
        return -1;
    }
    struct Node* temp = stack->top;
    stack->top = stack->top->next;
    int data = temp->data;
    printf("Popped %d from the stack\n", data);
    free(temp);
    return data;
}


void printList(struct llStack* stack)
{
    struct Node* temp = stack->top;
    while(temp)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main()
{
    struct llStack stack;
    push(&stack, 40);
    push(&stack, 30);
    push(&stack, 20);
    push(&stack, 10);
    printList(&stack);
    
    pop(&stack);
    printList(&stack);
    int is_Empty = isEmpty(&stack);
    printf("Is stack empty?: %d", is_Empty);
    
    return 0;
}
