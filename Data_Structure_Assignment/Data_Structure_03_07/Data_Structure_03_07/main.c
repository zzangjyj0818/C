#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

/* Num1 */
//가장 거리가 짧은 좌표와 먼 좌표의 배열 index를 저장할 변수 선언
int max_index = 0, min_index = 0;
double max_value, min_value;
double value[10] = {0,};

//구조체 선언
typedef struct location{
    double x;
    double y;
} location;

void input_location(){
    location inf[10];
    
    for(int i = 0; i<10; i++){
        //10개의 좌표를 입력받음
        printf("좌표 (x,y) : ");
        scanf("%lf%lf", &inf[i].x, &inf[i].y);
        // value에 원점부터 해당 점까지의 거리를 루트를 씌우지 않은 상태로 저장함
        value[i] = (inf[i].x)*(inf[i].x) + (inf[i].y)*(inf[i].y);
    }
    
    //거리의 최대 최소를 구하기 위해
    //value[0]으로 초기화 해줌
    min_value = value[0];
    max_value = min_value;
    
    for(int i=1; i<10; i++){
        if(min_value < value[i])
            min_index = i;
        if(max_value > value[i])
            max_index = i;
    }
    
    /* 가까운 좌표와 먼 좌표의 거리 계산 */
    double x_diff = inf[max_index].x - inf[min_index].x;
    double y_diff = inf[max_index].y - inf[min_index].y;
    double result = sqrt(x_diff*x_diff + y_diff*y_diff);
    
    printf("제일 가까운 좌표 : %.0lf %.0lf\n", inf[max_index].x, inf[max_index].y);
    printf("제일 먼 좌표 : %.0lf %.0lf\n", inf[min_index].x, inf[min_index].y);
    printf("제일 먼 좌표와 가장 가까운 좌표 사이의 거리 : %.1lf\n", result);
}

/* Num2 */
void birthday_1(){
    
    char birth[10][8]; // 10개의 생년월일이 담긴 2차원 배열
    char year[5], month[3], days[3]; // 년도, 월, 일을 담기위한 변수
    char t_year[5], t_month[3], t_days[3]; // 위에 있는 변수와 비교하기 위해 만든 임시변수
    
    for(int i = 0; i<10; i++){
        printf("생년월일 입력 : ");
        scanf("%s",birth[i]);
        
        //초기값을 정해주어야하기 때문에
        //i가 0일때 year,month,days의 값을 초기화해줌
        if(i == 0){
            for(int j = 0; j<8; j++){
                if(j<4){
                    year[j] = birth[i][j];
                }
                else if(j>3 && j<6){
                    month[j-4] = birth[i][j];
                }
                else{
                    days[j-6] = birth[i][j];
                }
            }
        }
        if(i > 0){
            for(int j = 0; j<8; j++){
                if(j<4)
                    t_year[j] = birth[i][j];
                else if(j>3 && j<6)
                    t_month[j-4] = birth[i][j];
                else
                    t_days[j-6] = birth[i][j];
            }
            
            if(strcmp(t_year, year) < 0){
                for(int k = 0; k<4; k++){
                    year[k] = t_year[k];
                    if(k>1){
                        month[k-2] = t_month[k-2];
                        days[k-2] = t_days[k-2];
                    }
                }
            }
            else if(strcmp(t_year, year) == 0){
                if(strcmp(t_month, month) < 0){
                    for(int k = 0; k<2; k++){
                        month[k] = t_month[k];
                        days[k] = t_days[k];
                    }
                }
                else if(strcmp(t_month, month) == 0){
                    if(strcmp(t_days, days) < 0){
                        for(int k = 0; k<2; k++){
                            days[k] = t_days[k];
                        }
                    }
                }
            }
        }

    }
    printf("%s %s %s\n", year, month, days);
}

/* Num3 */
void birthday_2(){
    int arr[10][3];
    int year=0,month=0,days=0;
    
    for(int i = 0; i<10; i++){
        printf("생년월일 입력 ( 년도 / 월/ 일 ) : ");
        scanf("%d%d%d", &arr[i][0],&arr[i][1],&arr[i][2]);
        //year, month, year를 다른 값과 비교하기 위해 초기화 해줌
        if(i==0){
            year = arr[i][0];
            month = arr[i][1];
            days = arr[i][2];
        }
        if(i>0){
            if(year > arr[i][0]){
                year = arr[i][0];
                month = arr[i][1];
                days = arr[i][2];
            }
            else if(year == arr[i][0]){
                if(month > arr[i][1]){
                    month = arr[i][1];
                    days = arr[i][2];
                }
                else if(month == arr[i][1]){
                    if(days > arr[i][2]){
                        days = arr[i][2];
                    }
                }
            }
        }
    }
    
    printf("가장 빠른 생년월일 : %d %d %d\n", year,month,days);
}
/* Num4 */
typedef struct information{
    int year;
    int month;
    int days;
}information;

void birthday_3(){
    information inf[10];
    int y=0,m=0,d=0;
    
    for(int i = 0; i<10; i++){
        printf("생년월일 입력 ( 년도 / 월 / 일 ) : ");
        scanf("%d%d%d", &inf[i].year, &inf[i].month, &inf[i].days);
        if(i==0){
            y = inf[i].year;
            m = inf[i].month;
            d = inf[i].days;
        }
        if(i>0){
            if(y < inf[i].year){
                y = inf[i].year;
                m = inf[i].month;
                d = inf[i].days;
            }
            else if(y == inf[i].year){
                if(m < inf[i].month){
                    m = inf[i].month;
                    d = inf[i].days;
                }
                else if(m == inf[i].month){
                    if(d < inf[i].days){
                        d = inf[i].days;
                    }
                }
            }
        }
    }
    printf("가장 늦은 생년월일 : %d %d %d\n", y,m,d);
}
/* Num 5 */
void find_prime_number(){
    int m,n, flag = 0;
    printf("m과 n 입력 : ");
    scanf("%d%d", &m, &n);
    
    for(int i = m; i<n+1; i++){
        for(int j = 2; j<i; j++){
            if(i%j == 0)
                flag = 1;
        }
        if(flag == 0){
            printf("%d\t", i);
        }
        flag = 0;
    }
    printf("\n");
}
/* Print Menu */
void print_menu(){
    int menu;
    while(1){
        fflush(stdin);
        printf("Menu ( 1~5번 / 6번 : 종료 ) : ");
        scanf("%d", &menu);
        
        switch(menu){
            case 1:
                input_location();
                break;
            case 2:
                birthday_1();
                break;
            case 3:
                birthday_2();
                break;
            case 4:
                birthday_3();
                break;
            case 5:
                find_prime_number();
                break;
            case 6:
                printf("종료합니다.\n");
                return;
                break;
            default:
                printf("다시 입력하세요\n");
                break;
        }
    }
}


/* Main Fuction */
int main(){
    print_menu();
    return 0;
}
