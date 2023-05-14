#include <iostream>
using namespace std;

char arr[9][9];

int main(){
    int cnt = 0;
    for(int i = 1; i<=8; i++){
        for(int j = 1; j<=8; j++){
            cin >> arr[i][j];
            if(i%2 == 1 && j%2 == 1 && arr[i][j] == 'F')
                cnt++;
            else if(i%2 == 0 && j%2==0 && arr[i][j] == 'F')
                cnt++;
        }
    }
    cout << cnt;
}
