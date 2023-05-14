#include <stdio.h>
#include <stdlib.h>
#define MAX_STACK_SIZE 100

/* Stack Struct 선언 */
typedef char elementChar;
typedef int elementInt;

typedef struct StackType{
    elementChar dataChar[MAX_STACK_SIZE];
    elementInt dataInt[MAX_STACK_SIZE];
    int top;
}StackType;

char postfix[MAX_STACK_SIZE];
int count;

/* Init the Stack index */
void init_stack(StackType *s){
    s->top = -1;
}

/* Check Stack(Empty) */
int is_empty(StackType *s){
    return (s->top == -1);
}

/* Check Stack(Full) */
int is_full(StackType *s){
    return (s->top == (MAX_STACK_SIZE-1));
}

/* Push the character in Stack*/
void pushChar(StackType *s, elementChar item){
    if(is_full(s)){
        fprintf(stderr, "Stack is Full!\n");
        return;
    }
    else
        s->dataChar[++(s->top)] = item;
}

/* Push the Integer in Stack*/
void pushInt(StackType *s, elementInt item){
    if(is_full(s)){
        fprintf(stderr, "Stack is Full!\n");
        return;
    }
    else
        s->dataInt[++(s->top)] = item;
}

/* Pop the Character in Stack */
elementChar popChar(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "Stack is Empty!\n");
        exit(1);
    }else{
        return s->dataChar[(s->top)--];
    }
}

/* Pop the Integer in Stack */
elementInt popInt(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "Stack is Empty!\n");
        exit(1);
    }else{
        return s->dataInt[(s->top)--];
    }
}

/* Return the data of Stack on Top (Char) */
elementChar peekChar(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "Stack is Empty!\n");
        exit(1);
    }else{
        return s->dataChar[s->top];
    }
}

/* Return the data of Stack on Top (Int) */
elementInt peekInt(StackType *s){
    if(is_empty(s)){
        fprintf(stderr, "Stack is Empty!\n");
        exit(1);
    }else{
        return s->dataInt[s->top];
    }
}
/* ******************************************************************** */
/* Change Infix to Postfix Seqeunce */
/* Return number according to Operater */
int prec(char op){
    switch(op){
        case '(':case')': return 0;
        case '|':case'&': return 1;
        case '<':case'>':case '=': return 2;
        case '+':case'-': return 3;
        case '*':case'/':case'%':return 4;
        case '^': return 5;
    }
    return -1;
}

/* Change Infix to Postfix */
void infix_to_postfix(char exp[]){
    
    /* Reset the postfix */
    for(int i = 0; postfix[i] != NULL; i++)
        postfix[i] = NULL;
    
    count = 0;
    char ch,top_op;
    int i = 0;
    StackType s;
    
    /* Init the Stack */
    init_stack(&s);
    
    printf("\n[Infix] : %s\n", exp);
    printf("\n<Flow of Stack [ POP | PUSH ] >\n");
    
    //While Finishing String
    while(exp[i] != NULL){
        ch = exp[i];
        switch(ch){
            case'+':
            case'-':
            case'*':
            case'/':
            case'%':
            case'<':
            case'>':
            case'=':
            case'^':
            case'|':
            case'&':
                if(!is_empty(&s) && peekChar(&s) == '^' && ch == '^'){
                    printf("[PUSH]: %c\n", ch);
                    pushChar(&s, ch);
                }else{
                    while(!is_empty(&s) && (prec(ch) <= prec(peekChar(&s)))){
                        postfix[count++] = peekChar(&s);
                        printf("[POP]: %c\n", peekChar(&s));
                        popChar(&s);
                    }
                    printf("[PUSH] : %c\n", ch);
                    pushChar(&s,ch);
                }
                break;
            case '(':
                printf("[PUSH] : %c\n", ch);
                pushChar(&s, ch);
                break;
            case ')':
                printf("[POP]: %c\n", peekChar(&s));
                top_op = popChar(&s);
                while(top_op != '('){
                    postfix[count++] = top_op;
                    printf("[POP]: %c\n", peekChar(&s));
                    top_op = popChar(&s);
                }
                break;
            default:
                postfix[count++] = ch;
                break;
        }
        i++;
    }
    while(!is_empty(&s)){
        postfix[count++] = peekChar(&s);
        printf("[POP]: %c\n", peekChar(&s));
        popChar(&s);
    }
    printf("\nPostfix : %s\n", postfix);
}

/* Square Implement */
int square(int x, int y){
    int temp = 1, result;
    
    for(int i = 0; i<y; i++){
        result = x*temp;
        temp *= x;
    }
    return result;
}

/* Calculate the Postfix */
int post_fix(char str[]){
    StackType s;
    
    //Init Stack
    init_stack(&s);
    
    int op1, op2, value, i=0, result;
    char ch;
    
    printf("\n<Flow of Stack>\n");
    while(str[i] != NULL){
        ch = str[i];
        if(ch != '+' && ch != '-' && ch != '*'&& ch != '/' && ch != '^' && ch != '>' && ch != '<' && ch != '=' && ch != '&' && ch != '|' && ch != '%'){
                   value = ch-'0';
                   printf("[Push] %d\n", value);
                   pushInt(&s, value);
        }else{
            printf("op2 : %d\t", peekInt(&s));
            op2 = popInt(&s);
            printf("op1 : %d\t\n", peekInt(&s));
            op1 = popInt(&s);
            switch(ch){
                case '+':
                    printf("[PUSH] %d\n", op1+op2);
                    pushInt(&s, op1+op2);
                    break;
                case '-':
                    printf("[PUSH] %d\n", op1-op2);
                    pushInt(&s, op1-op2);
                    break;
                case '*':
                    printf("[PUSH] %d\n", op1*op2);
                    pushInt(&s, op1*op2);
                    break;
                case '/':
                    printf("[PUSH] %d\n", op1/op2);
                    pushInt(&s, op1/op2);
                    break;
                case '%':
                    printf("[PUSH] %d\n", op1%op2);
                    pushInt(&s, op1%op2);
                    break;
                case '^':
                    result = square(op1, op2);
                    printf("[PUSH] %d\n", result);
                    pushInt(&s, result);
                    break;
                case '>':
                    result = op1 > op2;
                    printf("[PUSH] %d\n", result);
                    pushInt(&s, result);
                    break;
                case '<':
                    result = op1 > op2;
                    printf("[PUSH] %d\n", result);
                    pushInt(&s, result);
                    break;
                case '=':
                    result = (op1 == op2);
                    printf("[PUSH] %d\n", result);
                    pushInt(&s, result);
                    break;
                case '&':
                    result = (op1 && op2);
                    printf("[PUSH] %d\n", result);
                    pushInt(&s, result);
                    break;
                case '|':
                    result = (op1 || op2);
                    printf("[PUSH] %d\n", result);
                    pushInt(&s, result);
                    break;
            }
        }
        i++;
    }
    printf("\n[POP] %d\n", peekInt(&s));
    return popInt(&s);
}

/* Print Menu */
void print_menu(){
    int menu;
    char str[100];
    
    while(1){
        printf("\nInput the Menu [1 2 3(exit)] : ");
        scanf("%d", &menu);
        fflush(stdin);
        
        switch(menu){
            case 1:
                printf("Input the String : ");
                scanf("%s", str);
                fflush(stdin);
                infix_to_postfix(str);
                break;
            case 2:
                printf("\n\nPostfix : %s\n", postfix);
                printf("Post_fix_Result : %d\n", post_fix(postfix));
                break;
            case 3:
                printf("\nExit the Program\n");
                return;
                break;
            default:
                printf("\nWrong Input\n");
                break;
        }
    }
}

int main(void){
    print_menu();
    return 0;
}
