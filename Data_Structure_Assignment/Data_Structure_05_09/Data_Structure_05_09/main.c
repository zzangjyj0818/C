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

ListNode *early;

/* Get the length about LinkedList */
/* Recursion */
int get_length(ListNode *head){
    
    /* Recursive exit condition */
    if(head == NULL)
        return 0;
    
    return 1 + get_length(head->link);
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
    if(head == NULL) return;
    else{
        printf("영화 제목 : %s | 장르 : %c | 개봉년도 : %d\n", head->data.name, head->data.genre, head->data.year);
        display(head->link);
    }
}

/* Print the revesed LinkedList, using recursion */
void display_reverse(ListNode *head){
    if(head == NULL) return;
    else{
        display_reverse(head->link);
    }
    printf("영화 제목 : %s | 장르 : %c | 개봉년도 : %d\n", head->data.name, head->data.genre, head->data.year);
}

/* Print the LiskedList according to genre */
void display_genre(ListNode *head, char genre){
    for(ListNode *p = head; p != NULL; p = p->link){
        if(p->data.genre == genre)
            printf("영화 제목 : %s | 장르 : %c | 개봉년도 : %d\n", p->data.name, p->data.genre, p->data.year);
        }
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

/* Delete Node */
ListNode *delete(ListNode *head){
    ListNode *delete, *pre = NULL, *cur = head;
    char str[101];
    if(head == NULL){
        printf("등록된 영화가 없습니다.\n");
        return NULL;
    }
    
    printf("삭제하고자 하는 영화 제목 입력 : ");
    scanf("%s", str);
    
    while(cur != NULL){
        if(strcmp(cur->data.name, str) == 0){
            break;
        }
        pre = cur;
        cur = cur->link;
    }
    
    if(cur == NULL){
        printf("삭제하고자 하는 영화가 없습니다.\n");
        return head;
    }
    
    if(pre == NULL){
        delete = head;
        head = delete->link;
        free(delete);
        return head;
    }else{
        delete = pre->link;
        pre->link = delete->link;
        free(delete);
        return head;
    }
}

ListNode *find_early(ListNode *head){
    if(head == NULL){
        printf("등록된 영화가 없습니다.\n");
        return NULL;
    }
    early = head;
    for(ListNode *p = head->link; p != NULL; p = p->link){
        if(p->data.year > early->data.year)
            early = p;
    }
    return early;
}
/* Taxidriver A 2018
 Beginagain R 2017
 Jaws C 2018
 28weekslater R 2015 */

int main(void){
    ListNode *head = NULL;
    ListNode *find;
    int menu, print;
    
    while(1){
        movie information;
        
        printf("메뉴입력 [1. 영화 등록 2. 영화 검색 3. 영화 개수 4. 전체 영화 정보 출력 5. 특정 영화 삭제 6. 최근 개봉 영화 7. 원하는 장르별 영화 출력 8.종료] : ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                printf("영화 이름 입력 : ");
                scanf("%s", information.name);
                fflush(stdin);
                
                while(1){
                    printf("영화 장르 입력 (A | C | F | R): ");
                    scanf("%c", &(information.genre));
                    if(information.genre == 'A' || information.genre == 'C' ||information.genre == 'F' ||information.genre == 'R')
                        break;
                    else{
                        fflush(stdin);
                        printf("장르를 다시 입력하세요.\n");
                    }
                }
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
                printf("(1) 일반 출력 (2) 역순 출력 : ");
                scanf("%d", &print);
                switch(print){
                    case 1:
                        printf("---------------------------------------------\n");
                        display(head);
                        printf("---------------------------------------------\n");
                        break;
                    case 2:
                        printf("---------------------------------------------\n");
                        display_reverse(head);
                        printf("---------------------------------------------\n");
                        break;
                    default:
                        printf("잘못된 번호입니다.\n");
                        break;
                }
                break;
            case 5:
                head = delete(head);
                printf("---------------------------------------------\n");
                display(head);
                printf("---------------------------------------------\n");
                break;
            case 6:
                printf("---------------------------------------------\n");
                early = find_early(head);
                for(ListNode *p = head; p != NULL; p = p->link){
                    if(early->data.year == p->data.year)
                        printf("영화 제목 : %s | 장르 : %c | 개봉년도 : %d\n", p->data.name, p->data.genre, p->data.year);
                }
                printf("---------------------------------------------\n");
                break;
            case 7:
                printf("---------------------------------------------\n");
                fflush(stdin);
                char genre;
                while(1){
                    
                    printf("출력하고자 하는 장르 입력 ( A | C | F | R ): ");
                    scanf("%c", &genre);
                    if(genre == 'A'|| genre == 'C' || genre == 'F' || genre == 'R'){
                        break;
                    }
                    else{
                        fflush(stdin);
                        printf("장르를 다시 입력하세요.\n");
                    }
                }
                printf("---------------------------------------------\n");
                display_genre(head, genre);
                printf("---------------------------------------------\n");
                break;
            case 8:
                printf("Exit the Program\n");
                exit(1);
                break;
            default:
                printf("Wrong Menu\n");
                break;
        }
    }
    
}
