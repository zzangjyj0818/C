#include <stdio.h>
int find_max_fibo(int n)
{
    int a1 = 0, a2 = 1;
    int fibo = 1;
    while (a1 + a2 <= n) {
        fibo = a1 + a2;
        a1 = a2;
        a2 = fibo;
    }
    return fibo;
}

void find_fibos(int n)
{
    if (n == 1) {
        printf("1 ");
        return;
    }
    else {
        int f = find_max_fibo(n);
        if (f == n) {
            printf("%d ", f);
            return;
        }
        else if (n - f > 0) {
            find_fibos(n - f);
        }
        printf("%d ", f);
    }
}

int main()
{
    int n_tests;
    int n, max_fibo;
    scanf("%d", &n_tests);
    while (n_tests--) {
        scanf("%d", &n);
        find_fibos(n);
        printf("\n");
    }
}
