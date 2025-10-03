#ifndef DLL_H
#define DLL_H

typedef struct DNode {
    int data;
    struct DNode* prev;
    struct DNode* next;
} DNode;

/* Core operations */
DNode* createDNode(int val);
void traverseDLL(DNode* head);
int countNodesDLL(DNode* head);
DNode* insertBeginDLL(DNode* head, int val);
DNode* insertEndDLL(DNode* head, int val);
DNode* insertAtDLL(DNode* head, int val, int pos);
DNode* insertAfterValueDLL(DNode* head, int key, int val);
DNode* deleteFirstDLL(DNode* head);
DNode* deleteLastDLL(DNode* head);
DNode* deleteAtDLL(DNode* head, int pos);
DNode* deleteAfterValueDLL(DNode* head, int key);
DNode* reverseDLL(DNode* head);
DNode* appendDLL(DNode* h1, DNode* h2);
DNode* findMiddleDLL(DNode* head);
int findMaxDLL(DNode* head);
int findMinDLL(DNode* head);
void sortDLL(DNode* head);

/* Menu */
void dllMenu();

#endif
