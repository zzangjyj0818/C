#include <iostream>
using namespace std;

int main(){
    int n;
    cin >> n;
    int current = 2;
    int cnt = 0;
    for (int i = 0; i < n; ++i) {
        int in; cin >> in;
        if (current == 0 && in == 1) {
            ++cnt;
            current = 1;
        }
        else if (current == 1 && in == 2) {
            ++cnt;
            current = 2;
        }
        else if (current == 2 && in == 0) {
            ++cnt;
            current = 0;
        }
    }
    
    cout << cnt << '\n';

    return 0;
}
