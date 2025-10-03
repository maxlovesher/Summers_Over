#ifndef SLL_H
#define SLL_H

/* ---- Node structure ---- */
typedef struct Node {
    int data;
    struct Node* next;
} Node;

/* ---- Prototypes ---- */
Node* createNode(int val);
void traverse(Node* head);
int countNodes(Node* head);
Node* insertBegin(Node* head, int val);
Node* insertEnd(Node* head, int val);
Node* insertAt(Node* head, int val, int pos);
Node* insertAfterValue(Node* head, int key, int val);
Node* deleteFirst(Node* head);
Node* deleteLast(Node* head);
Node* deleteAt(Node* head, int pos);
Node* deleteAfterValue(Node* head, int key);
Node* reverse(Node* head);
Node* append(Node* head1, Node* head2);
Node* findMiddle(Node* head);
int findMax(Node* head);
int findMin(Node* head);
void sortList(Node* head);

void sllMenu();   // the submenu

#endif
