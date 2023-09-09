#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Define a structure for the stack
struct Stack {
    int top;
    unsigned capacity;
    char* array;
};

// Function to create a new stack
struct Stack* createStack(unsigned capacity) {
    struct Stack* stack = (struct Stack*)malloc(sizeof(struct Stack));
    stack->capacity = capacity;
    stack->top = -1;
    stack->array = (char*)malloc(stack->capacity * sizeof(char));
    return stack;
}

// Function to check if the stack is empty
bool isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, char item) {
    stack->array[++stack->top] = item;
}

// Function to pop an element from the stack
char pop(struct Stack* stack) {
    if (!isEmpty(stack)) {
        return stack->array[stack->top--];
    }
    return '$'; // Placeholder character for empty stack
}

// Function to check if the given expression has valid parentheses
bool isValidExpression(char* expression) {
    struct Stack* stack = createStack(strlen(expression));

    for (int i = 0; expression[i]; i++) {
        if (expression[i] == '(' || expression[i] == '[' || expression[i] == '{') {
            push(stack, expression[i]);
        } else if (expression[i] == ')' || expression[i] == ']' || expression[i] == '}') {
            if (isEmpty(stack)) {
                free(stack->array);
                free(stack);
                return false;
            }
            
            char topChar = pop(stack);
            
            if ((expression[i] == ')' && topChar != '(') ||
                (expression[i] == ']' && topChar != '[') ||
                (expression[i] == '}' && topChar != '{')) {
                free(stack->array);
                free(stack);
                return false;
            }
        }
    }
    
    bool result = isEmpty(stack);
    free(stack->array);
    free(stack);
    return result;
}

int main() {
    char expression[] = "{[()]()}";

    if (isValidExpression(expression)) {
        printf("The expression is valid.\n");
    } else {
        printf("The expression is not valid.\n");
    }

    return 0;
}
