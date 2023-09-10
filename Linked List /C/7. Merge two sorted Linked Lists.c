#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

struct Node* mergeList(struct Node* list1, struct Node* list2) {
    struct Node* dummy = (struct Node*)malloc(sizeof(struct Node));
    struct Node* curr = dummy;

    dummy->next = NULL; // Initialize the dummy node's next pointer to NULL

    if (list1 == NULL) {
        curr->next = list2;
    }
    if (list2 == NULL) {
        curr->next = list1;
    }

    while (list1 != NULL && list2 != NULL) {
        if (list1->data <= list2->data) {
            curr->next = list1;
            list1 = list1->next;
        } else {
            curr->next = list2;
            list2 = list2->next;
        }
        curr = curr->next;
    }

    head = dummy->next;
    free(dummy);
    return head;
}

void printlist(struct Node* head) {
    struct Node* temp = head;
    while (temp) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    struct Node* node1 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node2 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node3 = (struct Node*)malloc(sizeof(struct Node));

    node1->data = 1;
    node1->next = node2;

    node2->data = 2;
    node2->next = node3;

    node3->data = 4;
    node3->next = NULL;

    struct Node* list1 = node1;

    struct Node* node4 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node5 = (struct Node*)malloc(sizeof(struct Node));
    struct Node* node6 = (struct Node*)malloc(sizeof(struct Node));

    node4->data = 1;
    node4->next = node5;

    node5->data = 3;
    node5->next = node6;

    node6->data = 4;
    node6->next = NULL;

    struct Node* list2 = node4;

    head = mergeList(list1, list2);

    printlist(head);

    return 0;
}
