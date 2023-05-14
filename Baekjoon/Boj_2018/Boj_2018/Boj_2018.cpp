#include <iostream>
using namespace std;

int main(){
    int n, cnt = 0;
    
    cin >> n;
    
    int l=1,r=1,sum = 0;
    
    while(l <= r && r <= n+1){
        if(sum > n){
            sum -= l;
            l++;
        }
        else if(sum < n){
            sum += r;
            r++;
        }
        else if(sum == n){
            cnt++;
            
            sum += r;
            r++;
        }
    }
    cout << cnt;
}
