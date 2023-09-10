#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* hasCycle(struct Node* head) {
    if (head == NULL || head->next == NULL) {
        return NULL; // No cycle if the list is empty or has only one element.
    }

    struct Node* slow = head;
    struct Node* fast = head;

    // Use Floyd's Cycle Detection Algorithm to detect the cycle.
    while (fast != NULL && fast->next != NULL) {
        slow = slow->next;
        fast = fast->next->next;

        if (slow == fast) {
            break; // Cycle detected
        }
    }

    if (fast == NULL || fast->next == NULL) {
        return NULL; // No cycle
    }

    // Move one pointer to the head and keep the other at the meeting point.
    slow = head;
    while (slow != fast) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow; // Return the starting node of the cycle.
}

int main() {
    // Example usage:
    struct Node* head = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    head->data = 1;
    head->next = node1;

    node1->data = 2;
    node1->next = node2;

    node2->data = 3;
    node2->next = node3;

    node3->data = 4;
    node3->next = node1; // Creating a cycle: 4 -> 2

    struct Node* cycleStart = hasCycle(head);
    if (cycleStart != NULL) {
        printf("Tail connects to node with value %d\n", cycleStart->data);
    } else {
        printf("No cycle\n");
    }

    // Free allocated memory (don't forget to free the memory when done).
    free(head);
    free(node1);
    free(node2);
    free(node3);

    return 0;
}
