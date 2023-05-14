#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main(){
    int testcase;
    cin >> testcase;
    stack<char> st;
    
    cin.ignore();
    
    for(int i = 0; i<testcase; i++){
        string s;
        getline(cin,s);
        s += ' ';
        for(int j = 0; j<s.length(); j++){
            if(s[j] == ' '){
                while(!st.empty()){
                    cout << st.top();
                    st.pop();
                }
                cout << ' ';
            }
            else
                st.push(s[j]);
        }
    }
    cout << '\n';
}
