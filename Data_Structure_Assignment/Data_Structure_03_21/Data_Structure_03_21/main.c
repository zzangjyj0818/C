#include <stdio.h>
#define MAX_DEGREE 100

/* Global */
/* Struct */
typedef struct poly {
    int degree; //최고차항을 담을 변수
    float coef[MAX_DEGREE]; //계수를 담을 배열
}poly;

poly A,B,C; //구조체 변수 선언

/* Print Function */
void print_poly(poly p){
    for(int i = p.degree; i>0; i--){
        if(p.coef[p.degree-i] != 0)
            printf("(%3.1fx^%d) + ", p.coef[p.degree-i], i);
        else
            continue;
    }
    printf("(%3.1f)\n", p.coef[p.degree]);
}

/* Input Function */
void input_poly(){
    printf("A의 최고차항 : ");
    scanf("%d", &A.degree);
    
    printf("계수를 입력하세요 : ");
    for(int i = 0; i<A.degree+1; i++)
        scanf("%f", &A.coef[i]);
    
    printf("B의 최고차항 : ");
    scanf("%d", &B.degree);
    
    printf("계수를 입력하세요 : ");
    for(int i = 0; i<B.degree+1; i++)
        scanf("%f", &B.coef[i]);
    
    printf("A(x) = ");
    print_poly(A);
    
    printf("B(x) = ");
    print_poly(B);
}

/* insert x */
int poly_eval(int x){
    int sum = 0, value = 1, select;
    
    //A다항식 또는 B다항식
    printf("1[A(x)] or 2[B(x)] : ");
    scanf("%d", &select);
    
    //switch문을 통하여
    //A나 B 둘 중 하나를 출력하게 됨
    switch(select){
            case 1:
                for(int i = A.degree; i>0; i--){
                    if(A.coef[A.degree-i] == 0)
                        continue;
                    else{
                        //x의 차수만큼 곱해줌
                        for(int j = 0; j<i; j++){
                            value *= x;
                        }
                    }
                    sum += (A.coef[A.degree-i]*value);
                    value = 1;
                }
                sum += A.coef[A.degree];
                printf("A(x) = ");
                print_poly(A);
                break;
            case 2:
                for(int i = B.degree; i>0; i--){
                    if(B.coef[B.degree-i] == 0)
                        continue;
                    else{
                        for(int j = 0; j<i; j++){
                            value *= x;
                        }
                    }
                    sum += (B.coef[B.degree-i]*value);
                    value = 1;
                }
                sum += B.coef[B.degree];
                printf("B(x) = ");
                print_poly(B);
                break;
            default:
                printf("오류\n");
                break;
        }
        return sum;
}

/* mul Function */
void mul_poly(){
    for(int i = 0; i<A.degree+B.degree+1; i++)
        C.coef[i] = 0;
    
    for(int i = 0; i<A.degree+1; i++)
        for(int j = 0; j<B.degree+1; j++){
            C.coef[i+j] += (A.coef[i]*B.coef[j]);
        }
    
    printf("A(x) = ");
    print_poly(A);
    
    printf("B(x) = ");
    print_poly(B);
    
    C.degree = A.degree+B.degree;
    
    printf("C(x) = ");
    print_poly(C);
}

/* Print menu */
void print_menu(){
    int menu, x;
    input_poly();
    
    while (1) {
        printf("1 2 3 4: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                mul_poly();
                break;
            case 2:
                printf("< 새로운 다항식 입력 >\n");
                input_poly();
                break;
            case 3:
                printf("x를 입력하세요 : ");
                scanf("%d", &x);
                printf("\nf(%d) : %d\n", x, poly_eval(x));
                break;
            case 4:
                printf("프로그램을 종료합니다.\n");
                return;
                break;
            default:
                printf("1-4 사이의 번호를 입력하세요\n");
                break;
        }
    }
}


/* main Function*/
int main(){
    print_menu();
    return 0;
}
