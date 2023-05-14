#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

int main(){
    string a,b;
    cin >> a >> b;
    
    reverse(a.begin(),a.end());
    reverse(b.begin(),b.end());
    int sum = stoi(a) + stoi(b);
    string result = to_string(sum);
    reverse(result.begin(), result.end());
    cout << stoi(result);
    
}
