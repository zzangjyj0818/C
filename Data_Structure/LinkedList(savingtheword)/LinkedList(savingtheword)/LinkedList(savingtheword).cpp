#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    char name[100];
} element;

typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

ListNode *head = NULL;
element data;

ListNode *insert_first(ListNode *head, element value){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p!=NULL; p = p->link){
        printf("%s -> ", p->data.name);
    }
    printf("\nEND\n");
}

void menu(){
    int number;
    
    printf("1. Input 2. Print 3. exit : ");
    scanf("%d", &number);
    
    switch(number){
        case 1:{
            printf("Input the word : ");
            scanf("%s", data.name);
            head = insert_first(head, data);
            break;
        }
        case 2:{
            print_list(head);
            break;
        }
        case 3:{
            printf("\nExit the program!\n");
            exit(1);
        }
        default:{
            printf("\nError\n");
            break;
        }
    }
}

int main(){
    while(1)
        menu();
}
