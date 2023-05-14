#include <stdio.h>
#include <stdlib.h>

//Implement the Factorial using Recursion
int factorial(int n){
    if(n <= 1)
        return 1;
    else
        return n*factorial(n-1);
}

int power(int x, int n){
    //If n == 0, return 1
    if(n==0)
        return 1;
    //If n is Odd, return power(x*x, n/2)
    else if(n % 2 == 0)
        return power(x*x, n/2);
    //If n is Even, return x*power(x*x, (n-1)/2)
    else
        return x*power(x*x, (n-1)/2);
}

int recursive_fib(int n){
    if(n == 0)
        return 0;
    if(n == 1)
        return 1;
    return recursive_fib(n-1)+recursive_fib(n-2);
}

int loop_fib(int n){
    if(n==0) return 0;
    if(n==1) return 1;
    int pp = 0;
    int p = 1;
    int result = 0;
    
    for(int i = 2; i<=n; i++){
        result = pp + p;
        pp = p;
        p = result;
    }
    return result;
}

void hanoi_tower(int n, char from, char tmp, char to){
    if(n == 1)
        printf("원판 1을 %c 에서 %c로 옯긴다.\n", from, to);
    else{
        hanoi_tower(n-1, from, to, tmp);
        printf("원판 %d를 %c에서 %c로 옮긴다.\n", n, from, to);
        hanoi_tower(n-1, tmp, from, to);
    }
}

int sum1(int n){
    if(n == 1)
        return 1;
    return n+sum1(n-1);
}

double sum2(double n){
    if(n == 1)
        return 1;
    return (1/n)+sum2(n-1);
}

int nCk(int n, int k){
    if(n == k || k == 0)
        return 1;
    else if(0 < k && k < n){
        return nCk(n, k-1) + nCk(n-1, k);
    }
    else
        return 0;
}

int find_max(int arr[], int index){
    if(index == 0)
        return arr[index];
    
    int result = find_max(arr, index-1);
    arr[index] = arr[index] < result ? result : arr[index];
    
    return arr[index];
}

int Binary_Search(int arr[], int find, int start, int end){
    int mid = (start+end)/2;
    if(start > end)
        return -1;
    
    if(arr[mid] == find){
        return mid;
    }else if(arr[mid] > find){
        return Binary_Search(arr, find, start, mid-1);
    }else
        return Binary_Search(arr, find, mid+1, end);
}

int stringlen(char *str){
    if(!(*str)) return 0;
    return (stringlen(str+1)+1);
}
void menu(){
    int select;
    int arr[5] = {3,7,2,9,4};
    int binary[10] = {1, 3, 5, 7, 9, 11, 13, 15, 17, 19};
    
    while(1){
        printf("Input the Menu [1. Factorial 2. Power 3.Fibonacci 4.hanoi_tower 5. sum 6. Combination 7. Max 8. Binary_Search 9. Strlen] : ");
        scanf("%d", &select);
        switch(select){
            case 1:
                printf("%d! = %d\n", 5, factorial(5));
                break;
            case 2:
                printf("%d^%d = %d\n", 2, 10, power(2, 10));
                break;
            case 3:
                printf("[Recursive] fib(%d) : %d\n", 5, recursive_fib(5));
                printf("[Loop] fib(%d) : %d\n", 5, loop_fib(5));
                break;
            case 4:
                hanoi_tower(3, 'A', 'B', 'C');
                break;
            case 5:
                printf("1 + ... + 5 = %d\n", sum1(5));
                printf("1 + ... + 1/5 = %.2lf\n", sum2(5));
                break;
            case 6:
                printf("6C1 : %d\n", nCk(6, 1));
                break;
            case 7:
                printf("Max_Num : %d\n", find_max(arr, 5));
                break;
            case 8:
                printf("Result : binary[%d] : %d\n", Binary_Search(binary, 5, 0, 9), binary[Binary_Search(binary, 5, 0, 9)]);
                break;
            case 9:
                printf("HelloWorld : (strlen)%d\n", stringlen("HelloWorld"));
                break;
        }
    }
}

int main(){
    menu();
}
