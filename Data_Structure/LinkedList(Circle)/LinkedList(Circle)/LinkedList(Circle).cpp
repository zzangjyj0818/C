#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

void print_list(ListNode *head){
    ListNode *p;
    if(head == NULL)
        return;
    p = head->link;
    do{
        printf("%d-> ", p->data);
        p = p->link;
    }while(p != head);
    printf("%d-> ", p->data);
}

ListNode *insert_first(ListNode *head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node -> data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
    }
    return head;
}
ListNode *insert_last(ListNode *head, element data){
    ListNode *node = (ListNode*)malloc(sizeof(ListNode));
    node -> data = data;
    if(head == NULL){
        head = node;
        node->link = head;
    }
    else{
        node->link = head->link;
        head->link = node;
        head = node;
    }
    return head;
}

int main(){
    ListNode *head = NULL;
    
    for(int i = 0; i<5; i++){
        head = insert_first(head, i+1);
        print_list(head);
        printf("\n");
    }
    for(int i = 0; i<5; i++){
        head = insert_last(head, i+6);
        print_list(head);
        printf("\n");
    }
}
