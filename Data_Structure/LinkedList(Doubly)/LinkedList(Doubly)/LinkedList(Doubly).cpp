#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *llink, *rlink;
}ListNode;

void init(ListNode *head){
    head->llink = head;
    head->rlink = head;
}

void print_list(ListNode *head){
    for(ListNode *p = head->rlink; p != head; p = p->rlink)
        printf("<-| %d |-> ", p->data);
    printf("\n");
}
void insert(ListNode *before,element data){
    ListNode *newnode = (ListNode*)malloc(sizeof(ListNode));
    newnode->data = data;
    newnode->llink = before;
    newnode->rlink = before->rlink;
    before->rlink->llink = newnode;
    before->rlink = newnode;
}

void del(ListNode *head, ListNode *removed){
    if(removed == head)
        return;
    removed->rlink->llink = removed->llink;
    removed->llink->rlink = removed->rlink;
    free(removed);
}
int main(){
    ListNode *head = (ListNode*)malloc(sizeof(ListNode));
    init(head);
    for(int i = 0; i<5; i++){
        insert(head, i+1);
        print_list(head);
    }
    for(int i = 0; i<5; i++){
        del(head, head -> rlink);
        print_list(head);
    }
    free(head);
}
