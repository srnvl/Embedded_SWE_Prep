// stack as array

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct ArrayStack{          // defines what parameters to be used: Array[MAX_SIZE] and top variable
    int top;
    int arr[MAX_SIZE];
};

void initialize(struct ArrayStack* stack)
{
    stack->top = -1;
}

bool isEmpty(struct ArrayStack* stack)
{
    return stack->top == -1;
}

bool isFull(struct ArrayStack* stack)
{
    return stack->top == MAX_SIZE;
}

void push(struct ArrayStack* stack, int data)
{
    if(isFull(stack))
    {
        printf("Stack is full!");
        return;
    }
    stack->arr[++stack->top] = data;
    printf("Pushed %d in the stack.\n", data);
}

int pop(struct ArrayStack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty!");
        return -1;
    }
    int data = stack->arr[stack->top--];
    // printf("Popped %d from the stack.", data);
    return data;
}

int peek(struct ArrayStack* stack)
{
    if(isEmpty(stack))
    {
        printf("Stack is empty!");
        return -1;
    }
    return stack->arr[stack->top];
}

int main()
{
    struct ArrayStack stack;
    initialize(&stack);
    push(&stack, 4);
    push(&stack, 3);
    push(&stack, 2);
    push(&stack, 1);
    
    printf("Top value is: %d\n", peek(&stack));
    printf("Popped value is: %d\n", pop(&stack));
    
    printf("Popped value is: %d\n", pop(&stack));
    
    return 0;
}
