#include <stdio.h>
#include <stdlib.h>

// Define a structure for a single node in the linked list
struct Node {
    int data;
    struct Node* next;
};

// Define a structure for the stack
struct Stack {
    struct Node* top;
};

// Function to create a new node with the given data
struct Node* newNode(int data) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    if (!node) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    node->data = data;
    node->next = NULL;
    return node;
}

// Function to initialize an empty stack
struct Stack* createStack() {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    if (!stack) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    stack->top = NULL;
    return stack;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == NULL);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int data) {
    struct Node* node = newNode(data);
    node->next = stack->top;
    stack->top = node;
    printf("%d pushed to the stack.\n", data);
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        exit(1);
    }
    struct Node* temp = stack->top;
    int data = temp->data;
    stack->top = temp->next;
    free(temp);
    return data;
}

// Function to display the elements in the stack
void display(struct Stack* stack) {
    struct Node* current = stack->top;
    printf("Stack: ");
    while (current != NULL) {
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main() {
    struct Stack* stack = createStack();

    push(stack, 1);
    push(stack, 2);
    push(stack, 3);

    display(stack);

    printf("Popped element: %d\n", pop(stack));
    printf("Popped element: %d\n", pop(stack));

    display(stack);

    return 0;
}
