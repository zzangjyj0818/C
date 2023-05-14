#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main(){
    int t;
    cin >> t;
    set<string> s_set;
    
    for(int i = 0; i<t; i++){
        string name, condition;
        cin >> name >> condition;
        
        if(condition == "enter")
            s_set.insert(name);
        else
            s_set.erase(name);
    }
    
    for(auto iter = s_set.rbegin(); iter != s_set.rend(); iter++)
        cout << *iter << "\n";
}
