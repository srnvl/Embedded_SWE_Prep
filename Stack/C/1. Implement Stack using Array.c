#include <stdio.h>
#include <stdbool.h>

#define MAX_SIZE 100

// Define a structure for the stack
struct Stack {
    int arr[MAX_SIZE];
    int top;
};

// Initialize the stack
void initialize(struct Stack *stack) {
    stack->top = -1; // Initialize the top index to -1
}

// Check if the stack is empty
bool isEmpty(struct Stack *stack) {
    return stack->top == -1;
}

// Check if the stack is full
bool isFull(struct Stack *stack) {
    return stack->top == MAX_SIZE - 1;
}

// Push an element onto the stack
void push(struct Stack *stack, int value) {
    if (isFull(stack)) {
        printf("Stack overflow\n");
        return;
    }
    stack->arr[++stack->top] = value;
}

// Pop an element from the stack
int pop(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack underflow\n");
        return -1; // Return an error value (you can choose a different approach)
    }
    return stack->arr[stack->top--];
}

// Peek at the top element of the stack without removing it
int peek(struct Stack *stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty\n");
        return -1; // Return an error value (you can choose a different approach)
    }
    return stack->arr[stack->top];
}

int main() {
    struct Stack stack;
    initialize(&stack);

    push(&stack, 1);
    push(&stack, 2);
    push(&stack, 3);

    printf("Top element: %d\n", peek(&stack));

    while (!isEmpty(&stack)) {
        printf("Popped: %d\n", pop(&stack));
    }

    return 0;
}
