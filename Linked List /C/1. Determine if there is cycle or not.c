#include<stdio.h>
#include<stdbool.h>

struct Node {
    int data;
    struct Node* next;
};

struct Node* head = NULL;

bool hasCycle(head)
{
  if(head == NULL || head->next == NULL)
  {
    return false;
  }

  struct Node* hare = head;
  struct Node* tortoise = head;

  while(hare != NULL && hare->next != NULL) // i.e. hare is not empty node or hare should be pointing to next node
    {
      tortoise = tortoise->next;
      hare = hare->next->next;
    }
  
  if(tortoise == hare)
  {
    return true;
  }
  else
  {
    return false;
  }

}

int main()
{
  struct Node*  head = (struct Node* ) malloc(sizeof(struct Node));
  struct Node* node1 = (struct Node* ) malloc(sizeof(struct Node));
  struct Node* node2 = (struct Node* ) malloc(sizeof(struct Node));
  struct Node* node3 = (struct Node* ) malloc(sizeof(struct Node));

  head->data = 1;
  head->next = node1;

  node1->data = 2;
  node1->next = node2;

  node2->data = 3;
  node2->next = node3;

  node3->data = 4;
  node3->next = node1;

  bool hasCycleResult = hasCycle(head);
  if(hasCycleResult == true)
  {
      printf("Has cycle");
  }
  else
  {
    printf("Doesn't have cycle");
  }

  free(head);
  free(node1);
  free(node2);
  free(node3);
  return 0;
}
