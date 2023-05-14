#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main(){
    srand(time(NULL));
    char str[10][100] = {"이용우", "이현제", "박준혁", "최재우", "길하늘", "박서연", "조서현", "이원재", "황윤미", "박건호"};
    
    
    int arr[10] = {0,};
    int flag = 0;
    
    for(int i = 0; i<100; i++){
        int n = rand() % 10;
        if(arr[n] != 1){
            printf("당첨 : %s\n", str[n]);
            arr[n] = 1;
        }else continue;
    }
    
}
