#include <stdio.h>
#include <stdlib.h>

// Define a structure for a stack
struct Stack {
    int* array;
    int top;
    unsigned capacity;
};

// Function to create a stack with a given capacity
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (int*)malloc(stack->capacity * sizeof(int));
    return stack;
}

// Function to check if a stack is empty
int isEmpty(struct Stack* stack) {
    return stack->top == -1;
}

// Function to push an element onto the stack
void push(struct Stack* stack, int item) {
    if (stack->top == stack->capacity - 1) {
        printf("Stack is full. Cannot push %d.\n", item);
        return;
    }
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
int pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty. Cannot pop.\n");
        return -1;
    }
    return stack->array[stack->top--];
}

// Function to enqueue an element into the queue
void enqueue(struct Stack* stack, int item) {
    push(stack, item);
}

// Function to dequeue an element from the queue
int dequeue(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Queue is empty. Cannot dequeue.\n");
        return -1;
    }

    // Pop the top element from the stack
    int item = pop(stack);

    // If the stack is empty, return the popped item
    if (isEmpty(stack)) {
        return item;
    }

    // Recursively dequeue the remaining items
    int temp = dequeue(stack);

    // Push the popped item back onto the stack
    push(stack, item);

    return temp;
}

int main() {
    struct Stack* stack = createStack(100);

    enqueue(stack, 1);
    enqueue(stack, 2);
    enqueue(stack, 3);

    printf("Dequeued: %d\n", dequeue(stack));
    printf("Dequeued: %d\n", dequeue(stack));

    enqueue(stack, 4);

    printf("Dequeued: %d\n", dequeue(stack));
    printf("Dequeued: %d\n", dequeue(stack));

    free(stack->array);
    free(stack);

    return 0;
}
