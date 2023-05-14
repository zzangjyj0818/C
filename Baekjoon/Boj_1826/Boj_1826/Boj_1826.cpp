#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;

int main(){
    
    priority_queue<int, vector<int>, less<int>> q;
    pair<int, int> a[10001];
    
    int n, l, p;
    
    cin >> n;
    for(int i = 0; i<n; i++)
        cin >> a[i].first >> a[i].second;
    
    cin >> l >> p;
    
    sort(a,a+n); //정렬
    
    int cnt = 0, index = 0;
    
    while(l>p){
        while(a[index].first <= p && index < n){
            q.push(a[index++].second);
            
        }
            
        if(!q.empty()){
                p += q.top();
                q.pop();
                cnt++;
            }
        else if(index == n || a[index].first > p){
                cnt = -1;
                break;
        }
    }
    cout << cnt;
}
