#include <stdio.h>
#include <stdlib.h>

int main(){
    char c;
    int num;
    printf("4개의 문자입력 : ");
    
    if(scanf("%[^\n]c", &c)){
        printf("%c(%x) ", c, c);
    }
}
