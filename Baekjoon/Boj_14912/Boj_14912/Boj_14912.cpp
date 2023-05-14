#include <iostream>
#include <string>
using namespace std;

int main(){
    int n, d, cnt = 0;
    cin >> n >> d;
    for(int i = 1; i<n+1; i++){
        int p = i;
        while(p){
            if(p%10 == d)
                cnt++;
            p /= 10;
        }
    }
    cout << cnt;
}
