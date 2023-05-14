#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int n;
    cin >> n;
    
    int arr[10] = {0,};
    
    while(1){
        arr[n%10]++;
        if(n/10 == 0)
            break;
        n/=10;
    }
    int tmp = 0;
    for(int i = 0; i< 10; i++){
        if(i != 6 && i != 9)
            tmp = max(tmp, arr[i]);
    }
    cout << max(tmp, (arr[6]+arr[9]+1)/2);
}
