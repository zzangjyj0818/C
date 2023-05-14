#include <iostream>
#include <algorithm>
using namespace std;

int arr[500001];
int n;

int main(){
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> arr[i];
    
    sort(arr, arr+n);
    for(int i = 0; i<n; i++)
        cout << arr[i] << " ";
}
