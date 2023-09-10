#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* getIntersection(struct Node* headA, struct Node* headB) {
    struct Node* tempA = headA;
    struct Node* tempB = headB;
    while (tempA != tempB) {
        if (tempA != NULL) {
            tempA = tempA->next;
        } else {
            tempA = headB;
        }

        if (tempB != NULL) {
            tempB = tempB->next;
        } else {
            tempB = headA;
        }
    }
    return tempA;
}

int main() {
    // Initialize linked list A
    struct Node* headA = (struct Node*)malloc(sizeof(struct Node));
    headA->data = 1;
    headA->next = (struct Node*)malloc(sizeof(struct Node));
    headA->next->data = 9;
    headA->next->next = (struct Node*)malloc(sizeof(struct Node));
    headA->next->next->data = 1;
    headA->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    headA->next->next->next->data = 2;
    headA->next->next->next->next = (struct Node*)malloc(sizeof(struct Node));
    headA->next->next->next->next->data = 4;
    headA->next->next->next->next->next = NULL;

    // Initialize linked list B
    struct Node* headB = (struct Node*)malloc(sizeof(struct Node));
    headB->data = 3;
    headB->next = (struct Node*)malloc(sizeof(struct Node));
    headB->next->data = 2;
    headB->next->next = (struct Node*)malloc(sizeof(struct Node));
    headB->next->next->data = 4;
    headB->next->next->next = NULL;

    // Find the intersection
    struct Node* result = getIntersection(headA, headB);

    // Check if there is an intersection
    if (result != NULL) {
        printf("Intersection Node Value: %d\n", result->data);
    } else {
        printf("No Intersection\n");
    }

    // Free the memory for the linked lists
    struct Node* current = headA;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    current = headB;
    while (current != NULL) {
        struct Node* temp = current;
        current = current->next;
        free(temp);
    }

    return 0;
}
