#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
} ListNode;

ListNode *insert(ListNode *head, element key){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    p->data = key;
    p->link = head;
    head = p;
    return head;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("NULL\n");
}

ListNode *concat_list(ListNode *head1, ListNode *head2){
    if(head1 == NULL)
        return head2;
    else if(head2 == NULL)
        return head1;
    else{
        ListNode *p = head1;
        while(p->link != NULL)
            p = p->link;
        p->link = head2;
        return head1;
    }
}

int main(void){
    ListNode *head1 = NULL, *head2 = NULL, *head3 = NULL;
    
    for(int i = 0; i<4; i++){
        head1 = insert(head1, i);
    }
    print_list(head1);
    for(int i = 4; i<8; i++){
        head2 = insert(head2, i);
    }
    print_list(head2);
    
    head3 = concat_list(head1, head2);
    print_list(head3);
    
}
