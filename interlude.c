#include <stdio.h>
#include <stdlib.h>
#include "sll.h"
#include "dll.h"
#include "csll.h"
#include "cdll.h"  

int main(){
    int choice;
    while(1){
        printf("\n==== Main Menu ====\n");
        printf("1. Singly Linked List (SLL)\n");
        printf("2. Doubly Linked List (DLL)\n");
        printf("3. Circular SLL (CSLL)\n");
        printf("4. Circular DLL (CDLL)\n");
        printf("5. Exit\n");
        printf("Enter choice: "); scanf("%d",&choice);
        switch(choice){
            case 1: sllMenu(); break;
            case 2: dllMenu(); break;
            case 3: csllMenu(); break;
            case 4: cdllMenu(); break;
            case 5: exit(0);
        }
    }
}
