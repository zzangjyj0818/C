#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
using namespace std;

int testcase;
int main(){
    cin >> testcase;
    
    for(int i = 0; i<testcase; i++){
        int n;
        vector<int> v;
        cin >> n;
        for(int i = 0; i<n; i++){
            int input;
            cin >> input;
            v.push_back(input);
        }
        sort(v.begin(),v.end());
        
        int gap = 0;
        for(int i = 0; i<v.size()-1; i++){
            gap = max(gap, abs(v[i]-v[i+1]));
        }
        printf("Class %d\n", i+1);
        printf("Max %d, Min %d, Largest gap %d\n", v[v.size()-1], v[0], gap);
    }
}
