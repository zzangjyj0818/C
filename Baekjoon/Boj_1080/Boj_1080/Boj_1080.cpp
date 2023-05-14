#include <iostream>
#include <algorithm>
using namespace std;

int main(){
    int input[51][51], cmp[51][51];
    int cnt = 0;
    int n,m;
    
    cin >> n >> m;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%1d",&input[i][j]);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            scanf("%1d", &cmp[i][j]);
        }
    }
    
    for(int i = 0; i<n-2; i++){
        for(int j = 0; j<m-2; j++){
            if(input[i][j] != cmp[i][j]){
                for(int k = i; k<=i+2; k++){
                    for(int o = j; o <= j+2; o++){
                        input[k][o] = 1 - input[k][o];
                    }
                }
                cnt++;
            }
            else
                continue;
        }
    }
    
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            if(input[i][j] != cmp[i][j]){
                cout << -1;
                return 0;
            }
        }
    }
    
    cout << cnt;
}
