#include <stdio.h>
#include <stdlib.h>

typedef int element;
typedef struct ListNode{
    element data;
    struct ListNode *link;
}ListNode;

ListNode *insert_first(ListNode *head, element data){
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->link = head;
    head = temp;
    return head;
}

ListNode *insert(ListNode *head, ListNode *pre, element data){
    ListNode *temp = (ListNode*)malloc(sizeof(ListNode));
    temp->data = data;
    temp->link = pre->link;
    pre->link = temp;
    return head;
}

ListNode *delete_first(ListNode *head){
    ListNode *removed = head;
    
    if(head == NULL) return NULL;
    head = removed->link;
    free(removed);
    return head;
}

ListNode *delete(ListNode *head, ListNode *pre){
    ListNode *removed = pre->link;
    pre->link = removed->link;
    free(removed);
    return head;
}

ListNode *search(ListNode *head, element key){
    if(head == NULL) return NULL;
    
    for(ListNode *p = head; p != NULL; p = p->link){
        if(p->data == key)
            return p;
    }
    return NULL;
}

void print_list(ListNode *head){
    for(ListNode *p = head; p != NULL; p = p->link)
        printf("%d -> ", p->data);
    printf("\n");
}

int main(void){
    ListNode *head = NULL;
    int key;
    
    for(int i = 0; i<5; i++){
        head = insert_first(head, i);
        print_list(head);
    }
    
    printf("Input the key you want to find : ");
    scanf("%d", &key);
    
    if(search(head, key) != NULL){
        printf("Success : %d\n", search(head, key)->data);
    }else{
        printf("Fail\n");
    }
    for(int i = 0; i<5; i++){
        head = delete_first(head);
        print_list(head);
    }
    
}
