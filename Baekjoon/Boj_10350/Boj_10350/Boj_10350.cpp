#include <iostream>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);

    int n, tmp;
    int arr[10001]={0};
    long long sum=0;
    
    cin >> n;
    for(int i=1; i<=n; i++)
        cin >> arr[i];
    
    for(int i=2; i<=n; i++)
        arr[i] += arr[i-1];
    
    for(int i=1; i<=n; i++)
        arr[i+n]+=arr[i]+arr[n];

    for(int i=0; i<n; i++){
        for(int j=i+1; j<=i+n; j++){
            tmp = arr[j] - arr[i];
            if(tmp < 0){
                sum+=((tmp*(-1))-1)/arr[n] + 1;
            }
        }
    }
    cout << sum;
}
/*
 #include <iostream>

 using namespace std;
 typedef long long int ll;

 int main() {
     ll n, banks[2000000];

     cin >> n;

     ll sum = 0;
     for (ll i = 1; i <= n; i++) {
         cin >> banks[i];
         sum += banks[i];
         banks[i + n] = banks[i];
     }
     
     ll result = 0;
     for (ll i = 1; i <= n; i++) {
         ll value = 0;
         
         for (ll j = i; j < i + n; j++) {
             value += banks[j];
             
             if (value < 0) {
                 ll minus = -value;
                 result += (minus - 1) / sum + 1;
             }
         }
     }

     cout << result;

     return 0;
 }
 */
