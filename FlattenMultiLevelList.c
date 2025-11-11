// Flatten multi level list and container_of, size_of, and offset_of

#include <stdio.h>
#include <stdlib.h>

/* Multilevel doubly linked list node */
typedef struct Node {
    int val;
    struct Node *prev, *next, *child;
} Node;

/* --- tiny helpers --- */
static Node* node_new(int v){ Node* n = calloc(1, sizeof *n); if(!n){perror("calloc"); exit(1);} n->val=v; return n; }
static void  link_after(Node* a, Node* b){
    if(!a || !b) return;
    b->prev = a; b->next = a->next;
    if(a->next) a->next->prev = b;
    a->next = b;
}
static void  print_list(Node* h){
    for(Node* p=h; p; p=p->next) { printf("%d%s", p->val, p->next ? " <-> " : "\n"); }
}

/* --- FLATTEN (iterative with explicit stack) ---
   Splices each child list between node and node->next.
   Complexity: O(n) time, O(h) space (h = max child depth).
*/
Node* flatten_multilevel(Node* head){
    if(!head) return NULL;

    /* simple growable pointer stack */
    size_t cap = 16, sp = 0;
    Node **stack = malloc(cap * sizeof *stack);
    if(!stack){ perror("malloc"); exit(1); }
    #define PUSH(x) do{ if(sp==cap){ cap*=2; stack = realloc(stack, cap*sizeof*stack); if(!stack){perror("realloc"); exit(1);} } stack[sp++]=(x);}while(0)
    #define POP()   (stack[--sp])
    #define ANY()   (sp>0)

    PUSH(head);
    Node dummy = {0};
    Node *prev = &dummy;

    while(ANY()){
        Node *cur = POP();

        /* link prev <-> cur */
        prev->next = cur;
        cur->prev = (prev == &dummy) ? NULL : prev;

        /* next gets processed after child */
        if(cur->next) PUSH(cur->next);

        /* dive into child first (depth-first order) */
        if(cur->child){
            PUSH(cur->child);
            cur->child = NULL;      /* spec: child becomes NULL after flatten */
            cur->next  = NULL;      /* will be set by subsequent links */
        }

        prev = cur;
    }

    free(stack);
    return dummy.next;
}

/* demo graph:
   top: 1-2-3-4-5-6 ; 3->child: 7-8-9 ; 8->child: 11-12
*/
static Node* build_sample(void){
    Node *n1=node_new(1), *n2=node_new(2), *n3=node_new(3),
         *n4=node_new(4), *n5=node_new(5), *n6=node_new(6);
    link_after(n1,n2); link_after(n2,n3); link_after(n3,n4); link_after(n4,n5); link_after(n5,n6);

    Node *n7=node_new(7), *n8=node_new(8), *n9=node_new(9);
    link_after(n7,n8); link_after(n8,n9);

    Node *n11=node_new(11), *n12=node_new(12);
    link_after(n11,n12);

    n3->child = n7;
    n8->child = n11;

    return n1;
}

/* free a FLATTENED list from head forward */
static void free_flat(Node* head){
    while(head){ Node* nxt = head->next; free(head); head = nxt; }
}

int main(void){
    Node* head = build_sample();

    printf("Before flatten (level 0 only):\n");
    print_list(head);

    head = flatten_multilevel(head);

    printf("\nAfter flatten:\n");
    print_list(head);

    free_flat(head);
    return 0;
}
