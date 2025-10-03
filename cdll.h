#ifndef CDLL_H
#define CDLL_H

typedef struct CDNode {
    int data;
    struct CDNode* prev;
    struct CDNode* next;
} CDNode;

/* Operations */
CDNode* createCDNode(int val);
void traverseCDLL(CDNode* head);
int countNodesCDLL(CDNode* head);
CDNode* insertBeginCDLL(CDNode* head, int val);
CDNode* insertEndCDLL(CDNode* head, int val);
CDNode* insertAtCDLL(CDNode* head, int val, int pos);
CDNode* insertAfterValueCDLL(CDNode* head, int key, int val);
CDNode* deleteFirstCDLL(CDNode* head);
CDNode* deleteLastCDLL(CDNode* head);
CDNode* deleteAtCDLL(CDNode* head, int pos);
CDNode* deleteAfterValueCDLL(CDNode* head, int key);
CDNode* reverseCDLL(CDNode* head);
CDNode* appendCDLL(CDNode* h1, CDNode* h2);
CDNode* findMiddleCDLL(CDNode* head);
int findMaxCDLL(CDNode* head);
int findMinCDLL(CDNode* head);
void sortCDLL(CDNode* head);

/* Menu */
void cdllMenu();

#endif
