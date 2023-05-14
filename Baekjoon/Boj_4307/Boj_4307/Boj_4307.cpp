#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int t,l,n,a,b;
    cin >> t;
    while(t--){
        int fast = 0, late = 0;
        cin >> l >> n;
        while(n--){
            cin >> a;
            b = l-a;
            if(a>b)
                swap(a,b);
            fast = max(fast,a);
            late = max(late,b);
        }
        cout << fast << " " << late << '\n';
    }
}
