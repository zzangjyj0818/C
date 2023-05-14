//선택정렬
//제일 작은 것을 골라서 앞으로 보내는 정렬
#include <stdio.h>

int main(){
    int i,j, min, index, temp;
    int array[10] = {1,10,5,8,7,6,4,3,2,9};
    for(i=0; i<10; i++){ß
        min = 9999;
        for(j = i; j<10; j++){
            if(min > array[j]){
                min = array[j];
                index = j;
            }
        }
        //Swaping
        temp = array[i];
        array[i] = array[index];
        array[index] = temp;
    }
    
    for(i = 0; i<10; i++)
        printf("%3d", array[i]);
}

//선택 정렬의 시간 복잡도
//2중 반복문이기때문에 복잡도는 O(n^2)
//비효율적인 정렬 알고리즘임.
