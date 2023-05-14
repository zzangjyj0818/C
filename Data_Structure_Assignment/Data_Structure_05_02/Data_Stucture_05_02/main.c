#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Define the Sturct about movie information */
typedef struct movie{
    char name[101];
    // A , C , F, R
    char genre;
    int year;
} movie;

/* Define the LinkedList */
typedef struct ListNode{
    movie data;
    struct ListNode *link;
}ListNode;

/* Get the length about LinkedList */
/* Recursion */
int get_length(ListNode *head){
    int cnt = 0;
    /* Recursive exit condition */
    if(head == NULL)
        return 0;
    cnt++;
    return cnt + get_length(head->link);
}

/* Search the Movie, using movie name*/
ListNode* search(ListNode *head){
    /* If head is NULL, return Value is NULL */
    if(head == NULL){
        printf("등록된 영화가 없습니다.\n");
        return NULL;
    }
    /* Input the movie name that you want to find */
    char str[101];
    printf("Input the Movie Name : ");
    scanf("%s", str);
    
    fflush(stdin);
    
    /* Loop for LinkedList */
    for(ListNode *p = head; p != NULL; p = p->link){
        if(strcmp(p->data.name, str) == 0){
            return p;
        }
    }
    /* If you don't find the movie, return Value is NULL */
    printf("찾으시는 영화가 존재하지 않습니다.\n");
    return NULL;
}

/* Print the LinkedList, using recursion*/
void display(ListNode *head){
    if(head == NULL){
        return;
    }
    printf("영화 제목 : %s | 장르 : %c | 개봉년도 : %d\n", head->data.name, head->data.genre, head->data.year);
    return display(head->link);
}
ListNode* insert_node(ListNode *head, movie inf){
    ListNode *p = (ListNode *)malloc(sizeof(ListNode));
    strcpy(p->data.name, inf.name);
    p->data.genre = inf.genre;
    p->data.year = inf.year;

    //if head is NULL, we make the first_Node.
    if(head == NULL){
        head = p;
        head->link = NULL;
        return head;
    }
    
    
    // pre is previous node, cur is current node
    ListNode *pre = NULL, *cur = head;
    // cnt is node counting
    int cnt = 0;
    // Loop for LinkedList
    while(cur != NULL){
        if(cnt == 0 && strcmp(p->data.name, cur->data.name) < 0){
            p->link = head;
            head = p;
            return head;
        }
        else if(strcmp(p->data.name, cur->data.name) < 0){
            p->link = pre->link;
            pre->link = p;
            return head;
    }
        cnt++;
        pre = cur;
        cur = cur->link;
    }
    p->link = pre->link;
    pre->link = p;
    return head;
}
int main(){
    ListNode *head = NULL;
    ListNode *find;
    int menu;
    
    while(1){
        movie information;
        
        printf("메뉴입력 [1. 영화 등록 2. 영화 검색 3. 영화 개수 4. 전체 영화 정보 출력 5. 종료] : ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                printf("영화 이름 입력 : ");
                scanf("%s", information.name);
                fflush(stdin);
                
                printf("영화 장르 입력 : ");
                scanf("%c", &(information.genre));
                fflush(stdin);
                
                printf("영화 개봉 연도 : ");
                scanf("%d", &(information.year));
                
                head = insert_node(head, information);
                printf("---------------------------------------------\n");
                display(head);
                printf("---------------------------------------------\n");
                break;
            case 2:
                find = search(head);
                if(find){
                    printf("영화 제목 : %s | 장르 : %c | 개봉년도 : %d\n", find->data.name, find->data.genre, find->data.year);
                }
                break;
            case 3:
                printf("등록된 영화의 개수 : %d\n", get_length(head));
                break;
            case 4:
                printf("---------------------------------------------\n");
                display(head);
                printf("---------------------------------------------\n");
                break;
            case 5:
                printf("Exit the Program\n");
                exit(1);
                break;
            default:
                printf("Wrong Menu\n");
                break;
        }
    }
    
}
