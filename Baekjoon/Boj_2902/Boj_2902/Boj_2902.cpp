#include <iostream>
#include <string>
using namespace std;

int main(){
    string s;
    getline(cin,s);
    
    cout<<s[0];
    for(int i = 1; i<s.length(); i++){
        if(s[i] == '-'){
            cout << s[i+1];
            i++;
        }
    }
}
