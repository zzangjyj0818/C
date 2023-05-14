#include <stdio.h>

void a(int i){
    if(i>1){
        a(i/2);
        a(i/2);
    }
    printf("*");
}

int main(){
    a(5);
}
