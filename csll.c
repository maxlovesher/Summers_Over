#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "csll.h"

/* Create node */
CSNode* createCSNode(int val){
    CSNode* n=(CSNode*)malloc(sizeof(CSNode));
    if(!n){ printf("Memory error\n"); exit(1); }
    n->data=val;
    n->next=n; // circular self-link
    return n;
}

/* Helper: check if empty */
int isEmpty(CSNode* head){ return head==NULL; }

/* 1. Traverse */
void traverseCSLL(CSNode* head){
    if(!head){ printf("List empty\n"); return; }
    CSNode* cur=head;
    printf("CSLL: ");
    do{
        printf("%d -> ",cur->data);
        cur=cur->next;
    }while(cur!=head);
    printf("(back to head)\n");
}

/* 2. Count */
int countNodesCSLL(CSNode* head){
    if(!head) return 0;
    int c=0; CSNode* cur=head;
    do{ c++; cur=cur->next; }while(cur!=head);
    return c;
}

/* 3. Insert at begin */
CSNode* insertBeginCSLL(CSNode* head,int val){
    CSNode* n=createCSNode(val);
    if(!head) return n;
    CSNode* tail=head;
    while(tail->next!=head) tail=tail->next;
    n->next=head;
    tail->next=n;
    return n; // new head
}

/* 4. Insert at end */
CSNode* insertEndCSLL(CSNode* head,int val){
    CSNode* n=createCSNode(val);
    if(!head) return n;
    CSNode* tail=head;
    while(tail->next!=head) tail=tail->next;
    tail->next=n;
    n->next=head;
    return head;
}

/* 5. Insert at pos */
CSNode* insertAtCSLL(CSNode* head,int val,int pos){
    if(pos<=1||!head) return insertBeginCSLL(head,val);
    int idx=1; CSNode* cur=head;
    while(cur->next!=head && idx<pos-1){ cur=cur->next; idx++; }
    CSNode* n=createCSNode(val);
    n->next=cur->next;
    cur->next=n;
    return head;
}

/* 6. Insert after value */
CSNode* insertAfterValueCSLL(CSNode* head,int key,int val){
    if(!head) return head;
    CSNode* cur=head;
    do{
        if(cur->data==key){
            CSNode* n=createCSNode(val);
            n->next=cur->next;
            cur->next=n;
            return head;
        }
        cur=cur->next;
    }while(cur!=head);
    printf("Value %d not found\n",key);
    return head;
}

/* 7. Delete first */
CSNode* deleteFirstCSLL(CSNode* head){
    if(!head) return NULL;
    if(head->next==head){ free(head); return NULL; }
    CSNode* tail=head;
    while(tail->next!=head) tail=tail->next;
    CSNode* tmp=head;
    head=head->next;
    tail->next=head;
    free(tmp);
    return head;
}

/* 8. Delete last */
CSNode* deleteLastCSLL(CSNode* head){
    if(!head) return NULL;
    if(head->next==head){ free(head); return NULL; }
    CSNode* cur=head;
    while(cur->next->next!=head) cur=cur->next;
    CSNode* tmp=cur->next;
    cur->next=head;
    free(tmp);
    return head;
}

/* 9. Delete at pos */
CSNode* deleteAtCSLL(CSNode* head,int pos){
    if(!head) return NULL;
    if(pos<=1) return deleteFirstCSLL(head);
    int idx=1; CSNode* cur=head;
    while(cur->next!=head && idx<pos-1){ cur=cur->next; idx++; }
    if(cur->next==head) return head; // too big
    CSNode* tmp=cur->next;
    cur->next=tmp->next;
    free(tmp);
    return head;
}

/* 10. Delete after value */
CSNode* deleteAfterValueCSLL(CSNode* head,int key){
    if(!head) return NULL;
    CSNode* cur=head;
    do{
        if(cur->data==key){
            if(cur->next==head){ printf("No node after %d\n",key); return head; }
            CSNode* tmp=cur->next;
            cur->next=tmp->next;
            free(tmp);
            return head;
        }
        cur=cur->next;
    }while(cur!=head);
    printf("Value %d not found\n",key);
    return head;
}

/* 11. Reverse */
CSNode* reverseCSLL(CSNode* head){
    if(!head || head->next==head) return head;
    CSNode* prev=head, *cur=head->next, *nxt=NULL;
    while(cur!=head){
        nxt=cur->next;
        cur->next=prev;
        prev=cur;
        cur=nxt;
    }
    head->next=prev;
    return prev; // new head
}

/* 12. Append */
CSNode* appendCSLL(CSNode* h1,CSNode* h2){
    if(!h1) return h2;
    if(!h2) return h1;
    CSNode* tail1=h1, *tail2=h2;
    while(tail1->next!=h1) tail1=tail1->next;
    while(tail2->next!=h2) tail2=tail2->next;
    tail1->next=h2;
    tail2->next=h1;
    return h1;
}

/* 13. Find middle */
CSNode* findMiddleCSLL(CSNode* head){
    if(!head) return NULL;
    CSNode* slow=head,*fast=head;
    do{
        fast=fast->next; 
        if(fast!=head) fast=fast->next;
        if(fast!=head) slow=slow->next;
    }while(fast!=head && fast->next!=head);
    return slow;
}

/* 14. Max */
int findMaxCSLL(CSNode* head){
    if(!head) return INT_MIN;
    int maxv=head->data;
    CSNode* cur=head->next;
    while(cur!=head){
        if(cur->data>maxv) maxv=cur->data;
        cur=cur->next;
    }
    return maxv;
}

/* 15. Min */
int findMinCSLL(CSNode* head){
    if(!head) return INT_MAX;
    int minv=head->data;
    CSNode* cur=head->next;
    while(cur!=head){
        if(cur->data<minv) minv=cur->data;
        cur=cur->next;
    }
    return minv;
}

/* 16. Sort */
void sortCSLL(CSNode* head){
    if(!head) return;
    int swapped;
    do{
        swapped=0;
        CSNode* cur=head;
        do{
            CSNode* nxt=cur->next;
            if(nxt!=head && cur->data>nxt->data){
                int t=cur->data; cur->data=nxt->data; nxt->data=t;
                swapped=1;
            }
            cur=cur->next;
        }while(cur->next!=head);
    }while(swapped);
}

/* ------------------- CSLL Menu ------------------- */
void csllMenu(){
    CSNode* head=NULL;
    int choice,val,pos,key;
    CSNode* mid;

    while(1){
        printf("\n--- CSLL Menu ---\n");
        printf("1. Create New List\n2. Traverse\n3. Count\n4. Insert at Beginning\n5. Insert at End\n");
        printf("6. Insert at Position\n7. Insert After Value\n8. Delete First\n9. Delete Last\n");
        printf("10. Delete at Position\n11. Delete After Value\n12. Reverse\n13. Append Second List\n");
        printf("14. Find Middle\n15. Find Max\n16. Find Min\n17. Sort\n18. Exit to Main\n");
        printf("Enter choice: "); scanf("%d",&choice);

        switch(choice){
            case 1:
                while(head){ // free all nodes
                    if(head->next==head){ free(head); head=NULL; break; }
                    CSNode* tail=head;
                    while(tail->next!=head) tail=tail->next;
                    tail->next=head->next;
                    free(head);
                    head=tail->next;
                }
                head=NULL;
                printf("Enter elements (-1 stop): ");
                while(1){ scanf("%d",&val); if(val==-1) break; head=insertEndCSLL(head,val); }
                break;
            case 2: traverseCSLL(head); break;
            case 3: printf("Count=%d\n",countNodesCSLL(head)); break;
            case 4: printf("Val: "); scanf("%d",&val); head=insertBeginCSLL(head,val); break;
            case 5: printf("Val: "); scanf("%d",&val); head=insertEndCSLL(head,val); break;
            case 6: printf("Val Pos: "); scanf("%d%d",&val,&pos); head=insertAtCSLL(head,val,pos); break;
            case 7: printf("AfterVal NewVal: "); scanf("%d%d",&key,&val); head=insertAfterValueCSLL(head,key,val); break;
            case 8: head=deleteFirstCSLL(head); break;
            case 9: head=deleteLastCSLL(head); break;
            case 10: printf("Pos: "); scanf("%d",&pos); head=deleteAtCSLL(head,pos); break;
            case 11: printf("Delete after val: "); scanf("%d",&key); head=deleteAfterValueCSLL(head,key); break;
            case 12: head=reverseCSLL(head); break;
            case 13:{
                printf("Enter 2nd list (-1 stop): "); CSNode* h2=NULL;
                while(1){ scanf("%d",&val); if(val==-1) break; h2=insertEndCSLL(h2,val); }
                head=appendCSLL(head,h2); break;
            }
            case 14: mid=findMiddleCSLL(head); if(mid) printf("Middle=%d\n",mid->data); else printf("Empty\n"); break;
            case 15: printf("Max=%d\n",findMaxCSLL(head)); break;
            case 16: printf("Min=%d\n",findMinCSLL(head)); break;
            case 17: sortCSLL(head); break;
            case 18: return;
        }
    }
}
