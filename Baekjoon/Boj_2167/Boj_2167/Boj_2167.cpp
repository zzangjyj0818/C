#include <iostream>
using namespace std;

int main(){
    int n,m;
    int arr[301][301];
    cin >> n >> m;
    for(int i = 0; i<n; i++)
        for(int j = 0; j<m; j++)
            cin >> arr[i][j];
    
    int testcase;
    cin >> testcase;
    for(int t = 0; t<testcase; t++){
        int a,b,c,d, sum = 0;
        cin >> a >> b >> c >> d;
        for(int i = a-1; i<c; i++){
            for(int j = b-1; j<d; j++){
                sum += arr[i][j];
            }
        }
        cout << sum << endl;
    }
}
