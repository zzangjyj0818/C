#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* Num1 */
void check_str(){
    
    //입력 받을 문자 배열 선언
    char str[100];
    
    //문자열을 입력받음
    printf("문자열 입력 : ");
    scanf("%s", str);
    
    //문제에서 요구하는 조건을 판단하여 결과값을 저장할
    //flag[5] 정수 배열 선언
    int flag[5] = {0,}, i=0;
    
    //입력받은 문자열이 null에 도달할때까지
    //반복문이 동작함
    while(str[i] != '\0'){
        //대문자일 경우에 flag[0] = 1
        if(isupper(str[i]))
            flag[0] = 1;
        //소문자일 경우에 flag[1] = 1
        if(islower(str[i]))
            flag[1] = 1;
        //특수기호가 포함된 경우에 flag[2] = 1
        if(str[i] == '!' || str[i] == '?' || str[i] == '*' || str[i] == '#' || str[i] == '$')
            flag[2] = 1;
        //숫자가 포함된 경우에 flag[3] = 1
        if(str[i] > 47 && str[i] < 58)
            flag[3] = 1;
        //문자열의 길이가 10이상인 경우에 flag[4] = 1
        if(i+1 >= 10)
            flag[4] = 1;
        i++;
    }
    
    int result = 0;
    for(int i = 0; i<5; i++)
        result += flag[i];
    
    //result의 값이 5인 경우
    //모든 조건을 충족하는 문자열임
    if(result == 5)
        printf("올바른 문자열입니다.\n\n");
    else{
        if(flag[0] == 0){
            printf("대문자(x)\n");
        }
        if(flag[1] == 0){
            printf("소문자(x)\n");
        }
        if(flag[2] == 0){
            printf("특수문자(x)\n");
        }
        if(flag[3]==0){
            printf("숫자(x)\n");
        }
        if(flag[4] == 0){
            printf("길이(x)\n");
        }
        printf("올바르지 않은 문자열입니다.\n\n");
    }
}

/* Num2 */

//나이, 성별, 이름을 담은 구조체 선언
typedef struct information{
    int age;
    char gender;
    char name[101];
} information;

void check_age(){
    //구조체 배열 선언
    information inf[10];
    
    //20세 이상의 여성, 남성의 수를
    //담기 위한 정수형 변수 선언
    //0으로 초기화 해줌
    int f_age = 0, m_age = 0;
    
    for(int i = 0; i<10; i++){
        fflush(stdin);
        
        printf("== <%d> ==\n", i+1);
        
        printf("이름을 입력하세요 : ");
        scanf("%s", inf[i].name);
        
        fflush(stdin);
        
        printf("성별을 입력하세요 : ");
        scanf("%c", &inf[i].gender);
        
        fflush(stdin);
        
        printf("나이를 입력하세요 : ");
        scanf("%d", &inf[i].age);
        
        if((inf[i].gender == 'F' || inf[i].gender == 'f') && inf[i].age > 19)
            f_age++;
        if((inf[i].gender == 'M' || inf[i].gender == 'm') && inf[i].age > 19)
            m_age++;
        
        printf("\n");
    }
    printf("20세 이상의 여성 : %d\n", f_age);
    printf("20세 이상의 남성: %d\n", m_age);
}

/* Num3 */
int find_max(int arr[], int index){
    
    if(index==0)
        return arr[0];
    
    int result = find_max(arr, index-1);
    
    arr[index] = result < arr[index] ? arr[index] : result;
    
    return arr[index];
}

void check_num1(){
    int num[10];
    
    printf("정수 10개를 입력하세요 : ");
    for(int i = 0; i<10; i++){
        scanf("%d", &num[i]);
    }
    
    //함수 매개변수로
    //사용자가 입력한 배열과 배열의 크기를 함수로 보내줌
    printf("가장 큰 값 : %d\n", find_max(num, 9));
}


/* Num4 */
int cnt = 1;
int binary_search(int arr[], int start, int end, int cmp){
    int mid;
    mid = (start+end)/2;
    
    if(start > end)
        return -1;
    
    printf("<%d> 범위 [%d]..[%d]에서 중간 위치 [%d]의 값 %d와 찾는 값 %d를 비교\n", cnt++, start, end, mid, arr[mid], cmp);
    
    //우리가 찾는 값이 존재한다면
    //종료
    if(arr[mid] == cmp)
        return mid;
    //찾고자하는 값이 배열의 중간값보다 작다면
    //함수 호출
    else if(arr[mid] > cmp)
        return binary_search(arr, start, mid-1, cmp);
    //찾고자하는 값이 배열의 중간값보다 크다면
    //함수 호출
    else
        return binary_search(arr, mid+1, end, cmp);
}

void check_num2(){
    int arr[10], n;
    
    //이진탐색은 오름차순 입력
    printf("정수 10개를 입력하세요(오름차순) : ");
    for(int i = 0; i<10; i++)
        scanf("%d", &arr[i]);
    
    printf("찾으시려고 하는 값을 입력하세요 : ");
    scanf("%d", &n);
    
    int index = binary_search(arr, 0, 9, n);
    if(index == -1)
        printf("찾으시는 값이 없습니다.\n");
    else
        printf("찾으시는 값 %d(arr[%d])가 존재합니다.\n", n, index);
    
    cnt = 1;
    
}
/* Menu */
void print_menu(){
    int menu;
    
    while(1){
        fflush(stdin);
        printf("번호 입력(1-5): ");
        scanf("%d", &menu);
        
        switch(menu){
                
                //if(menu == 1)
            case 1:
                check_str();
                break;
            case 2:
                check_age();
                break;
            case 3:
                check_num1();
                break;
            case 4:
                check_num2();
                break;
            case 5:
                printf("프로그램을 종료합니다\n");
                return;
                break;
            default:
                printf("올바르지 않은 번호입니다.\n");
                break;
        }
    }
}

int main(){
    print_menu();
    return 0;
}
