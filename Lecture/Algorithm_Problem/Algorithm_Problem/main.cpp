#include <stdio.h>

int main(void)
{
    double num;
    int x, y;

    printf("실수:");
    scanf("%lf", &num);

    printf("소수자리수(1~3):");
    scanf("%d", &x);

    printf("(처리)1.반올림 2.버림 3.올림:");
    scanf("%d",&y);

    if(x==1)
    {
        num = ((int)(num*10))*0.1;

        if(y==1)
        {
            num = (int)num+1;
            printf("결과 : %lf", num);
        }
        else if(y==2)
        {
            num = num-(int)num;
            printf("결과 : %lf", num);
        }
        else if(y==3)
        {
            num = (int)num;
            printf("결과 : %lf", num);
        }
        else
    {
        printf("입력오류");
    }
    }
    else if(x==2)
    {
        num = ((int)(num*100))*0.01;

        if(y=='1')
        {
            num = (int)num+1;
            printf("결과 : %lf",num);
        }
        else if(y==2)
        {
            num = num-(int)num;
            printf("결과 : %lf", num);
        }
        else if(y==3)
        {
            num = (int)num;
            printf("결과 : %lf", num);
        }
        else
    {
        printf("입력오류");
    }
    }
    else if(x==3)
    {
        num = ((int)(num*1000))*0.001;

        if(y==1)
        {
            num = (int)num+1;
            printf("결과 : %lf", num);
        }
        else if(y==2)
        {
            num = num-(int)num;
            printf("결과 : %lf", num);
        }
        else if(y==3)
        {
            num = (int)num;
            printf("결과 : %lf",num);
        }
        else
    {
        printf("입력오류");
    }
    }

    return 0;
}
