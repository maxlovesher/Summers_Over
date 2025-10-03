#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "dll.h"

/* Create node */
DNode* createDNode(int val) {
    DNode* n = (DNode*)malloc(sizeof(DNode));
    if (!n) { printf("Memory error\n"); exit(1); }
    n->data = val;
    n->prev = n->next = NULL;
    return n;
}

/* 1. Traverse */
void traverseDLL(DNode* head) {
    if (!head) { printf("List empty\n"); return; }
    DNode* cur = head;
    printf("DLL: ");
    while (cur) {
        printf("%d <-> ", cur->data);
        cur = cur->next;
    }
    printf("NULL\n");
}

/* 2. Count */
int countNodesDLL(DNode* head) {
    int c=0;
    while (head) { c++; head=head->next; }
    return c;
}

/* 3. Insert at begin */
DNode* insertBeginDLL(DNode* head, int val) {
    DNode* n = createDNode(val);
    if (head) {
        n->next = head;
        head->prev = n;
    }
    return n;
}

/* 4. Insert at end */
DNode* insertEndDLL(DNode* head, int val) {
    DNode* n = createDNode(val);
    if (!head) return n;
    DNode* cur=head;
    while (cur->next) cur=cur->next;
    cur->next=n;
    n->prev=cur;
    return head;
}

/* 5. Insert at pos */
DNode* insertAtDLL(DNode* head, int val, int pos) {
    if (pos<=1 || !head) return insertBeginDLL(head,val);
    int idx=1; DNode* cur=head;
    while (cur->next && idx<pos-1) { cur=cur->next; idx++; }
    DNode* n=createDNode(val);
    n->next=cur->next;
    n->prev=cur;
    if (cur->next) cur->next->prev=n;
    cur->next=n;
    return head;
}

/* 6. Insert after value */
DNode* insertAfterValueDLL(DNode* head, int key, int val) {
    DNode* cur=head;
    while(cur && cur->data!=key) cur=cur->next;
    if(!cur){ printf("Value %d not found\n",key); return head; }
    DNode* n=createDNode(val);
    n->next=cur->next; n->prev=cur;
    if(cur->next) cur->next->prev=n;
    cur->next=n;
    return head;
}

/* 7. Delete first */
DNode* deleteFirstDLL(DNode* head) {
    if(!head) return NULL;
    DNode* tmp=head;
    head=head->next;
    if(head) head->prev=NULL;
    free(tmp);
    return head;
}

/* 8. Delete last */
DNode* deleteLastDLL(DNode* head) {
    if(!head) return NULL;
    if(!head->next){ free(head); return NULL; }
    DNode* cur=head;
    while(cur->next) cur=cur->next;
    cur->prev->next=NULL;
    free(cur);
    return head;
}

/* 9. Delete at pos */
DNode* deleteAtDLL(DNode* head, int pos) {
    if(!head) return NULL;
    if(pos<=1) return deleteFirstDLL(head);
    int idx=1; DNode* cur=head;
    while(cur && idx<pos){ cur=cur->next; idx++; }
    if(!cur) return head;
    if(cur->prev) cur->prev->next=cur->next;
    if(cur->next) cur->next->prev=cur->prev;
    if(cur==head) head=cur->next;
    free(cur);
    return head;
}

/* 10. Delete after value */
DNode* deleteAfterValueDLL(DNode* head, int key) {
    DNode* cur=head;
    while(cur && cur->data!=key) cur=cur->next;
    if(cur && cur->next){
        DNode* tmp=cur->next;
        cur->next=tmp->next;
        if(tmp->next) tmp->next->prev=cur;
        free(tmp);
    } else printf("No node after %d\n",key);
    return head;
}

/* 11. Reverse */
DNode* reverseDLL(DNode* head) {
    DNode* cur=head; DNode* temp=NULL;
    while(cur){
        temp=cur->prev;
        cur->prev=cur->next;
        cur->next=temp;
        cur=cur->prev;
    }
    if(temp) head=temp->prev;
    return head;
}

/* 12. Append list2 */
DNode* appendDLL(DNode* h1, DNode* h2) {
    if(!h1) return h2;
    DNode* cur=h1;
    while(cur->next) cur=cur->next;
    cur->next=h2;
    if(h2) h2->prev=cur;
    return h1;
}

/* 13. Find middle */
DNode* findMiddleDLL(DNode* head) {
    if(!head) return NULL;
    DNode* slow=head, *fast=head;
    while(fast && fast->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    return slow;
}

/* 14. Max */
int findMaxDLL(DNode* head){
    if(!head) return INT_MIN;
    int maxv=head->data;
    while(head){ if(head->data>maxv) maxv=head->data; head=head->next; }
    return maxv;
}

/* 15. Min */
int findMinDLL(DNode* head){
    if(!head) return INT_MAX;
    int minv=head->data;
    while(head){ if(head->data<minv) minv=head->data; head=head->next; }
    return minv;
}

/* 16. Sort */
void sortDLL(DNode* head){
    if(!head) return;
    int swapped;
    do{
        swapped=0;
        DNode* cur=head;
        while(cur->next){
            if(cur->data>cur->next->data){
                int t=cur->data; cur->data=cur->next->data; cur->next->data=t;
                swapped=1;
            }
            cur=cur->next;
        }
    }while(swapped);
}

/* ------------------- DLL Menu ------------------- */
void dllMenu(){
    DNode* head=NULL;
    int choice,val,pos,key;
    DNode* mid;

    while(1){
        printf("\n--- DLL Menu ---\n");
        printf("1. Create New List\n2. Traverse\n3. Count\n4. Insert at Beginning\n5. Insert at End\n");
        printf("6. Insert at Position\n7. Insert After Value\n8. Delete First\n9. Delete Last\n");
        printf("10. Delete at Position\n11. Delete After Value\n12. Reverse\n13. Append Second List\n");
        printf("14. Find Middle\n15. Find Max\n16. Find Min\n17. Sort\n18. Exit to Main\n");
        printf("Enter choice: "); scanf("%d",&choice);

        switch(choice){
            case 1: // create
                while(head){ DNode* tmp=head; head=head->next; free(tmp); }
                head=NULL;
                printf("Enter elements (-1 stop): ");
                while(1){
                    scanf("%d",&val); if(val==-1) break;
                    head=insertEndDLL(head,val);
                }
                break;
            case 2: traverseDLL(head); break;
            case 3: printf("Count = %d\n",countNodesDLL(head)); break;
            case 4: printf("Value: "); scanf("%d",&val); head=insertBeginDLL(head,val); break;
            case 5: printf("Value: "); scanf("%d",&val); head=insertEndDLL(head,val); break;
            case 6: printf("Val Pos: "); scanf("%d%d",&val,&pos); head=insertAtDLL(head,val,pos); break;
            case 7: printf("AfterVal NewVal: "); scanf("%d%d",&key,&val); head=insertAfterValueDLL(head,key,val); break;
            case 8: head=deleteFirstDLL(head); break;
            case 9: head=deleteLastDLL(head); break;
            case 10: printf("Pos: "); scanf("%d",&pos); head=deleteAtDLL(head,pos); break;
            case 11: printf("Delete after val: "); scanf("%d",&key); head=deleteAfterValueDLL(head,key); break;
            case 12: head=reverseDLL(head); break;
            case 13:{
                printf("Enter 2nd list (-1 stop): "); DNode* h2=NULL;
                while(1){ scanf("%d",&val); if(val==-1) break; h2=insertEndDLL(h2,val); }
                head=appendDLL(head,h2); break;
            }
            case 14: mid=findMiddleDLL(head); if(mid) printf("Middle=%d\n",mid->data); else printf("Empty\n"); break;
            case 15: printf("Max=%d\n",findMaxDLL(head)); break;
            case 16: printf("Min=%d\n",findMinDLL(head)); break;
            case 17: sortDLL(head); break;
            case 18: return;
        }
    }
}
