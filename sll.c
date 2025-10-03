#include <stdio.h>
#include <stdlib.h>
#include <limits.h>
#include "sll.h"

/* ---- Core helper ---- */
Node* createNode(int val) {
    Node* n = (Node*)malloc(sizeof(Node));
    if (!n) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    n->data = val;
    n->next = NULL;
    return n;
}

/* 1. Traverse */
void traverse(Node* head) {
    if (!head) { printf("List is empty\n"); return; }
    while (head) {
        printf("%d -> ", head->data);
        head = head->next;
    }
    printf("NULL\n");
}

/* 2. Count */
int countNodes(Node* head) {
    int c = 0;
    while (head) { c++; head = head->next; }
    return c;
}

/* 3. Insert at beginning */
Node* insertBegin(Node* head, int val) {
    Node* n = createNode(val);
    n->next = head;
    return n;
}

/* 4. Insert at end */
Node* insertEnd(Node* head, int val) {
    Node* n = createNode(val);
    if (!head) return n;
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = n;
    return head;
}

/* 5. Insert at position (1-based) */
Node* insertAt(Node* head, int val, int pos) {
    if (pos <= 1 || !head) return insertBegin(head,val);
    int idx = 1;
    Node* cur = head;
    while (cur->next && idx < pos-1) {
        cur = cur->next;
        idx++;
    }
    Node* n = createNode(val);
    n->next = cur->next;
    cur->next = n;
    return head;
}

/* 6. Insert after value */
Node* insertAfterValue(Node* head, int key, int val) {
    Node* cur = head;
    while (cur && cur->data != key) cur = cur->next;
    if (!cur) { printf("Value %d not found\n", key); return head; }
    Node* n = createNode(val);
    n->next = cur->next;
    cur->next = n;
    return head;
}

/* 7. Delete first */
Node* deleteFirst(Node* head) {
    if (!head) return NULL;
    Node* tmp = head;
    head = head->next;
    free(tmp);
    return head;
}

/* 8. Delete last */
Node* deleteLast(Node* head) {
    if (!head) return NULL;
    if (!head->next) { free(head); return NULL; }
    Node* cur = head;
    while (cur->next->next) cur = cur->next;
    free(cur->next);
    cur->next = NULL;
    return head;
}

/* 9. Delete at position */
Node* deleteAt(Node* head, int pos) {
    if (!head) return NULL;
    if (pos <= 1) return deleteFirst(head);
    int idx = 1;
    Node* cur = head;
    while (cur->next && idx < pos-1) {
        cur = cur->next;
        idx++;
    }
    if (!cur->next) return head; // pos too large
    Node* tmp = cur->next;
    cur->next = tmp->next;
    free(tmp);
    return head;
}

/* 10. Delete after value */
Node* deleteAfterValue(Node* head, int key) {
    Node* cur = head;
    while (cur && cur->data != key) cur = cur->next;
    if (cur && cur->next) {
        Node* tmp = cur->next;
        cur->next = tmp->next;
        free(tmp);
    } else {
        printf("No node after %d\n", key);
    }
    return head;
}

/* 11. Reverse */
Node* reverse(Node* head) {
    Node* prev = NULL, *cur = head, *next = NULL;
    while (cur) {
        next = cur->next;
        cur->next = prev;
        prev = cur;
        cur = next;
    }
    return prev;
}

/* 12. Append */
Node* append(Node* head1, Node* head2) {
    if (!head1) return head2;
    Node* cur = head1;
    while (cur->next) cur = cur->next;
    cur->next = head2;
    return head1;
}

/* 13. Find middle */
Node* findMiddle(Node* head) {
    if (!head) return NULL;
    Node* slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
    }
    return slow;
}

/* 14. Find max */
int findMax(Node* head) {
    if (!head) return INT_MIN;
    int maxVal = head->data;
    while (head) {
        if (head->data > maxVal) maxVal = head->data;
        head = head->next;
    }
    return maxVal;
}

/* 15. Find min */
int findMin(Node* head) {
    if (!head) return INT_MAX;
    int minVal = head->data;
    while (head) {
        if (head->data < minVal) minVal = head->data;
        head = head->next;
    }
    return minVal;
}

/* 16. Sort (bubble sort on data) */
void sortList(Node* head) {
    if (!head) return;
    int swapped;
    Node* cur;
    do {
        swapped = 0;
        cur = head;
        while (cur->next) {
            if (cur->data > cur->next->data) {
                int tmp = cur->data;
                cur->data = cur->next->data;
                cur->next->data = tmp;
                swapped = 1;
            }
            cur = cur->next;
        }
    } while (swapped);
}

/* ------------------- SLL Menu ------------------- */
void sllMenu() {
    Node* head = NULL;
    int choice, val, pos, key;
    Node* middle;

    while (1) {
        printf("\n--- SLL Menu ---\n");
        printf("1. Create New List\n2. Traverse\n3. Count\n4. Insert at Beginning\n5. Insert at End\n");
        printf("6. Insert at Position\n7. Insert After Value\n8. Delete First\n9. Delete Last\n");
        printf("10. Delete at Position\n11. Delete After Value\n12. Reverse\n13. Append Second List\n");
        printf("14. Find Middle\n15. Find Max\n16. Find Min\n17. Sort\n18. Exit to Main\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: // create new list
                while (head) { Node* tmp = head; head = head->next; free(tmp); }
                head = NULL;
                printf("Enter elements (-1 to stop): ");
                while (1) {
                    scanf("%d",&val);
                    if (val == -1) break;
                    head = insertEnd(head,val);
                }
                break;
            case 2: traverse(head); break;
            case 3: printf("Count = %d\n", countNodes(head)); break;
            case 4: printf("Value: "); scanf("%d",&val); head = insertBegin(head,val); break;
            case 5: printf("Value: "); scanf("%d",&val); head = insertEnd(head,val); break;
            case 6: printf("Value and Position: "); scanf("%d%d",&val,&pos); head = insertAt(head,val,pos); break;
            case 7: printf("After Value and New Value: "); scanf("%d%d",&key,&val); head = insertAfterValue(head,key,val); break;
            case 8: head = deleteFirst(head); break;
            case 9: head = deleteLast(head); break;
            case 10: printf("Position: "); scanf("%d",&pos); head = deleteAt(head,pos); break;
            case 11: printf("Delete after value: "); scanf("%d",&key); head = deleteAfterValue(head,key); break;
            case 12: head = reverse(head); break;
            case 13: {
                printf("Enter elements of 2nd list (-1 to stop): ");
                Node* h2 = NULL;
                while (1) {
                    scanf("%d",&val);
                    if (val == -1) break;
                    h2 = insertEnd(h2,val);
                }
                head = append(head,h2);
                break;
            }
            case 14: middle = findMiddle(head);
                     if (middle) printf("Middle = %d\n", middle->data);
                     else printf("List empty\n"); break;
            case 15: printf("Max = %d\n", findMax(head)); break;
            case 16: printf("Min = %d\n", findMin(head)); break;
            case 17: sortList(head); break;
            case 18: return;
            default: printf("Invalid choice!\n");
        }
    }
}
