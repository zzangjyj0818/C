#include <stdio.h>
#include <stdlib.h>

typedef int elemnet;
typedef struct ListNode{
    elemnet data;
    struct ListNode *link;
}ListNode;

ListNode *head = NULL;
elemnet number;

ListNode* insert(ListNode *head, elemnet value){
    ListNode *p = (ListNode*)malloc(sizeof(ListNode));
    p->data = value;
    p->link = head;
    head = p;
    return head;
}

int search(ListNode *head, elemnet num){
    for(ListNode *p = head; p!=NULL; p = p->link){
        if(p->data == num){
            printf("\n Find the %d\n", p->data);
            return 1;
        }
    }
    printf("\nNot Found!\n");
    return 0;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p->link){
        printf("%d\t", p->data);
    }
    printf("\n");
}

void menu(){
    int num;
    printf("1. insert 2. print 3. search 4. exit : ");
    scanf("%d", &num);
    
    switch(num){
        case 1:{
            int input;
            printf("Input the number : ");
            scanf("%d", &input);
            head = insert(head, input);
            break;
        }
        case 2:{
            print_list(head);
            break;
        }
        case 3:{
            printf("Input the number you want find : ");
            scanf("%d", &number);
            if(search(head, number))
                printf("");
            else
                printf("");
            break;
        }
        case 4:{
            printf("\nExit the Program\n");
            exit(1);
            break;
        }
        default:{
            printf("\nError\n");
            break;
        }
    }
}

int main(){
    while(1){
        menu();
    }
}
