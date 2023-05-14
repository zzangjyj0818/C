#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#define MAX_STACK_SIZE 100

typedef char element; // 1번 3번 코드 시연할때 주석 제거
//typedef int element; // 2번 코드 시연할때 주석 제거

//스택을 정의하는 구조체 선언
typedef struct {
    element data[MAX_STACK_SIZE];
    int top;
} StackType;


// 스택 초기화 함수
void init_stack(StackType *s){
    s->top = -1;
}

// 공백 상태 검출 함수
int is_empty(StackType *s){
    return (s->top == -1);
}

// 포화 상태 검출 함수
int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE - 1));
}

// 삽입함수
void push(StackType *s, element item){
    if(is_full(s)){
        fprintf(stderr, "스택 포화 에러\n");
        return;
    }
    else s->data[++(s->top)] = item;
}

// 삭제함수
element pop(StackType *s){
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[(s->top)--];
}

// 피크함수
element peek(StackType *s){
    if(is_empty(s)) {
        fprintf(stderr, "스택 공백 에러\n");
        exit(1);
    }
    else return s->data[s->top];
}

/* Num1 */
//((())(()))
void number_print(){
    
    //구조체 변수 선언
    StackType s;
    
    //괄호를 입력받을 문자형 배열 선언
    char str[101];
    
    //구조체 초기화
    init_stack(&s);
    
    //괄호를 입력받음
    printf("괄호 입력 : ");
    scanf("%s", str);
    fflush(stdin);
    
    int i = 0, cnt = 1;
    
    //문자열의 끝에 도달할때까지 반복문이 동작함
    while (str[i] != NULL) {
        //만약, 문자가 열린 괄호라면
        if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
            push(&s, cnt);
            printf("%d ", cnt);
            cnt++;
        }
        else {
            printf("%d ", pop(&s));
        }
        i++;
    }
    printf("\n");
}
/* Num2 */

//n제곱을 계산해주는 함수
int square(int x, int y){
    int temp = 1, result;
    
    for(int i = 0; i<y; i++){
        
        result = x * temp;
        temp *= x;
    }
    
    return result;
    
}
int post_fix(){
    //구조체 변수 선언
    StackType s;
    
    //후위표기식을 입력받을 문자형 배열 선언
    char str[101];
    
    //스택 초기화
    init_stack(&s);
    
    printf("후위표기식 입력 : ");
    scanf("%s", str);
    
    
    int op1=0, op2=0, value, i=0, result=0;
    char ch;
    
    //문자열의 끝에 도달할때까지 반복문이 동작함
    while(str[i] != NULL){
        ch = str[i];
        //
        if(ch != '+' && ch != '-' && ch != '*'&& ch != '/' && ch != '^' && ch != '>' && ch != '<' && ch != '=' && ch != '&' && ch != '|'){
            value = ch - '0';
            push(&s, value);
        }
        else{
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){
                case '+':
                    push(&s, op1+op2);
                    break;
                case '-':
                    push(&s, op1-op2);
                    break;
                case '*':
                    push(&s, op1*op2);
                    break;
                case '/':
                    push(&s, op1/op2);
                    break;
                case '^':
                    result = square(op1, op2);
                    push(&s, result);
                    break;
                case '>':
                    result = op1 > op2;
                    push(&s, result);
                    break;
                case '<':
                    result = op1 > op2;
                    push(&s, result);
                    break;
                case '=':
                    result = (op1 == op2);
                    push(&s, result);
                    break;
                case '&':
                    result = (op1 && op2);
                    push(&s, result);
                    break;
                case '|':
                    result = (op1 || op2);
                    push(&s, result);
                    break;
            }
        }
        i++;
    }
    return pop(&s);
}


/* Num3 */
void string_zip(){
    char str[101];
    printf("문자열 입력 : ");
    scanf("%s", str);
    fflush(stdin);
    
    StackType s1, s2;
    init_stack(&s1);
    init_stack(&s2);
    
    int i = 0, cnt = 0;
    while(str[i] != NULL){
        cnt = 0;
        
        char ch = str[i++];
        cnt++;
        
        //ch와 str[i]가 대문자 소문자 상관없이 같을 경우 동안에 while문이 동작함
        while(ch == str[i] || (ch+('A'-'a')) == str[i] || (ch-('A'-'a')) == str[i]){
            cnt++;
            i++;
        }
        //정수형인 cnt를 문자형 cnt로 바꾸어서 넣음
        push(&s1, cnt + '0');
        //소문자일 경우 그냥 넣음
        if('a' <= ch && ch <= 'z')
            push(&s1, ch);
        //그렇지 않은 경우 대문자를 소문자로 바꾸어서 넣어줌
        else
            push(&s1, ch-('A'-'a'));
        
    }
    
    while(!is_empty(&s1)){
        push(&s2, pop(&s1));
    }
    printf("압축결과 : ");
    while(!is_empty(&s2)){
        printf("%c", pop(&s2));
    }
    printf("\n");
}



/* Menu Function */
void menu(){
    int menu;
    
    while(1){
        printf("메뉴 입력 : ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                number_print();
                break;
            case 2:
                printf("계산결과 :  %d\n", post_fix());
                break;
            case 3:
                string_zip();
                break;
            case 4:
                return;
                break;
            default:
                printf("유효하지 않은 번호\n");
                break;
        }
    }
}


/* Main */
int main(){
    menu();
    printf("프로그램을 종료합니다.\n");
    return 0;
}
