#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main(){
    cin.tie(NULL);
    cout.tie(NULL);
    ios::sync_with_stdio(false);
    
    string s;
    getline(cin, s);
    
    int sum = 0, cnt = 0;
    while(s.length() != 1){
        for(int i = 0; i<s.size(); i++)
            sum += s[i]-48;
        s = to_string(sum);
        cnt++;
        sum = 0;
    }
    cout << cnt << "\n";
    if(s == "3" || s == "6" || s == "9")
        cout << "YES";
    else
        cout << "NO";
}
