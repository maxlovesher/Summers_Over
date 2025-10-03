#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "cdll.h"

/* Create node */
CDNode* createCDNode(int val){
    CDNode* n=(CDNode*)malloc(sizeof(CDNode));
    if(!n){ printf("Memory error\n"); exit(1); }
    n->data=val;
    n->next=n->prev=n; // circular
    return n;
}

/* 1. Traverse */
void traverseCDLL(CDNode* head){
    if(!head){ printf("List empty\n"); return; }
    CDNode* cur=head;
    printf("CDLL: ");
    do{
        printf("%d <-> ",cur->data);
        cur=cur->next;
    }while(cur!=head);
    printf("(back to head)\n");
}

/* 2. Count */
int countNodesCDLL(CDNode* head){
    if(!head) return 0;
    int c=0; CDNode* cur=head;
    do{ c++; cur=cur->next; }while(cur!=head);
    return c;
}

/* 3. Insert at begin */
CDNode* insertBeginCDLL(CDNode* head,int val){
    CDNode* n=createCDNode(val);
    if(!head) return n;
    CDNode* tail=head->prev;
    n->next=head; n->prev=tail;
    tail->next=n; head->prev=n;
    return n;
}

/* 4. Insert at end */
CDNode* insertEndCDLL(CDNode* head,int val){
    CDNode* n=createCDNode(val);
    if(!head) return n;
    CDNode* tail=head->prev;
    n->next=head; n->prev=tail;
    tail->next=n; head->prev=n;
    return head;
}

/* 5. Insert at pos */
CDNode* insertAtCDLL(CDNode* head,int val,int pos){
    if(pos<=1||!head) return insertBeginCDLL(head,val);
    int idx=1; CDNode* cur=head;
    while(cur->next!=head && idx<pos-1){ cur=cur->next; idx++; }
    CDNode* n=createCDNode(val);
    n->next=cur->next; n->prev=cur;
    cur->next->prev=n; cur->next=n;
    return head;
}

/* 6. Insert after value */
CDNode* insertAfterValueCDLL(CDNode* head,int key,int val){
    if(!head) return head;
    CDNode* cur=head;
    do{
        if(cur->data==key){
            CDNode* n=createCDNode(val);
            n->next=cur->next; n->prev=cur;
            cur->next->prev=n; cur->next=n;
            return head;
        }
        cur=cur->next;
    }while(cur!=head);
    printf("Value %d not found\n",key);
    return head;
}

/* 7. Delete first */
CDNode* deleteFirstCDLL(CDNode* head){
    if(!head) return NULL;
    if(head->next==head){ free(head); return NULL; }
    CDNode* tail=head->prev;
    CDNode* newHead=head->next;
    tail->next=newHead; newHead->prev=tail;
    free(head);
    return newHead;
}

/* 8. Delete last */
CDNode* deleteLastCDLL(CDNode* head){
    if(!head) return NULL;
    if(head->next==head){ free(head); return NULL; }
    CDNode* tail=head->prev;
    tail->prev->next=head;
    head->prev=tail->prev;
    free(tail);
    return head;
}

/* 9. Delete at pos */
CDNode* deleteAtCDLL(CDNode* head,int pos){
    if(!head) return NULL;
    if(pos<=1) return deleteFirstCDLL(head);
    int idx=1; CDNode* cur=head;
    while(cur->next!=head && idx<pos){ cur=cur->next; idx++; }
    if(cur==head) return head;
    cur->prev->next=cur->next;
    cur->next->prev=cur->prev;
    if(cur==head) head=cur->next;
    free(cur);
    return head;
}

/* 10. Delete after value */
CDNode* deleteAfterValueCDLL(CDNode* head,int key){
    if(!head) return NULL;
    CDNode* cur=head;
    do{
        if(cur->data==key){
            CDNode* target=cur->next;
            if(target==head){ printf("No node after %d\n",key); return head; }
            cur->next=target->next;
            target->next->prev=cur;
            free(target);
            return head;
        }
        cur=cur->next;
    }while(cur!=head);
    printf("Value %d not found\n",key);
    return head;
}

/* 11. Reverse */
CDNode* reverseCDLL(CDNode* head){
    if(!head) return NULL;
    CDNode* cur=head;
    do{
        CDNode* tmp=cur->next;
        cur->next=cur->prev;
        cur->prev=tmp;
        cur=tmp;
    }while(cur!=head);
    return head->prev; // new head
}

/* 12. Append */
CDNode* appendCDLL(CDNode* h1,CDNode* h2){
    if(!h1) return h2;
    if(!h2) return h1;
    CDNode* tail1=h1->prev;
    CDNode* tail2=h2->prev;
    tail1->next=h2; h2->prev=tail1;
    tail2->next=h1; h1->prev=tail2;
    return h1;
}

/* 13. Find middle */
CDNode* findMiddleCDLL(CDNode* head){
    if(!head) return NULL;
    CDNode* slow=head,*fast=head;
    do{
        fast=fast->next; 
        if(fast!=head) fast=fast->next;
        if(fast!=head) slow=slow->next;
    }while(fast!=head && fast->next!=head);
    return slow;
}

/* 14. Max */
int findMaxCDLL(CDNode* head){
    if(!head) return INT_MIN;
    int maxv=head->data;
    CDNode* cur=head->next;
    while(cur!=head){ if(cur->data>maxv) maxv=cur->data; cur=cur->next; }
    return maxv;
}

/* 15. Min */
int findMinCDLL(CDNode* head){
    if(!head) return INT_MAX;
    int minv=head->data;
    CDNode* cur=head->next;
    while(cur!=head){ if(cur->data<minv) minv=cur->data; cur=cur->next; }
    return minv;
}

/* 16. Sort */
void sortCDLL(CDNode* head){
    if(!head) return;
    int swapped;
    do{
        swapped=0;
        CDNode* cur=head;
        do{
            CDNode* nxt=cur->next;
            if(nxt!=head && cur->data>nxt->data){
                int t=cur->data; cur->data=nxt->data; nxt->data=t;
                swapped=1;
            }
            cur=cur->next;
        }while(cur->next!=head);
    }while(swapped);
}

/* ------------------- CDLL Menu ------------------- */
void cdllMenu(){
    CDNode* head=NULL;
    int choice,val,pos,key;
    CDNode* mid;

    while(1){
        printf("\n--- CDLL Menu ---\n");
        printf("1. Create New List\n2. Traverse\n3. Count\n4. Insert at Beginning\n5. Insert at End\n");
        printf("6. Insert at Position\n7. Insert After Value\n8. Delete First\n9. Delete Last\n");
        printf("10. Delete at Position\n11. Delete After Value\n12. Reverse\n13. Append Second List\n");
        printf("14. Find Middle\n15. Find Max\n16. Find Min\n17. Sort\n18. Exit to Main\n");
        printf("Enter choice: "); scanf("%d",&choice);

        switch(choice){
            case 1:
                while(head){ 
                    if(head->next==head){ free(head); head=NULL; break; }
                    CDNode* tail=head->prev;
                    tail->next=head->next;
                    head->next->prev=tail;
                    free(head);
                    head=tail->next;
                }
                head=NULL;
                printf("Enter elements (-1 stop): ");
                while(1){ scanf("%d",&val); if(val==-1) break; head=insertEndCDLL(head,val); }
                break;
            case 2: traverseCDLL(head); break;
            case 3: printf("Count=%d\n",countNodesCDLL(head)); break;
            case 4: printf("Val: "); scanf("%d",&val); head=insertBeginCDLL(head,val); break;
            case 5: printf("Val: "); scanf("%d",&val); head=insertEndCDLL(head,val); break;
            case 6: printf("Val Pos: "); scanf("%d%d",&val,&pos); head=insertAtCDLL(head,val,pos); break;
            case 7: printf("AfterVal NewVal: "); scanf("%d%d",&key,&val); head=insertAfterValueCDLL(head,key,val); break;
            case 8: head=deleteFirstCDLL(head); break;
            case 9: head=deleteLastCDLL(head); break;
            case 10: printf("Pos: "); scanf("%d",&pos); head=deleteAtCDLL(head,pos); break;
            case 11: printf("Delete after val: "); scanf("%d",&key); head=deleteAfterValueCDLL(head,key); break;
            case 12: head=reverseCDLL(head); break;
            case 13:{
                printf("Enter 2nd list (-1 stop): "); CDNode* h2=NULL;
                while(1){ scanf("%d",&val); if(val==-1) break; h2=insertEndCDLL(h2,val); }
                head=appendCDLL(head,h2); break;
            }
            case 14: mid=findMiddleCDLL(head); if(mid) printf("Middle=%d\n",mid->data); else printf("Empty\n"); break;
            case 15: printf("Max=%d\n",findMaxCDLL(head)); break;
            case 16: printf("Min=%d\n",findMinCDLL(head)); break;
            case 17: sortCDLL(head); break;
            case 18: return;
        }
    }
}
