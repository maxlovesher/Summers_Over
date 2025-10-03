#ifndef CSLL_H
#define CSLL_H

typedef struct CSNode {
    int data;
    struct CSNode* next;
} CSNode;

/* Operations */
CSNode* createCSNode(int val);
void traverseCSLL(CSNode* head);
int countNodesCSLL(CSNode* head);
CSNode* insertBeginCSLL(CSNode* head, int val);
CSNode* insertEndCSLL(CSNode* head, int val);
CSNode* insertAtCSLL(CSNode* head, int val, int pos);
CSNode* insertAfterValueCSLL(CSNode* head, int key, int val);
CSNode* deleteFirstCSLL(CSNode* head);
CSNode* deleteLastCSLL(CSNode* head);
CSNode* deleteAtCSLL(CSNode* head, int pos);
CSNode* deleteAfterValueCSLL(CSNode* head, int key);
CSNode* reverseCSLL(CSNode* head);
CSNode* appendCSLL(CSNode* h1, CSNode* h2);
CSNode* findMiddleCSLL(CSNode* head);
int findMaxCSLL(CSNode* head);
int findMinCSLL(CSNode* head);
void sortCSLL(CSNode* head);

/* Menu */
void csllMenu();

#endif
