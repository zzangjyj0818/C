#include <iostream>
#include <math.h>
#include <cstring>
#include <vector>
#include <algorithm>
using namespace std;

struct number {
    int num,strike,ball;
    number() { }
    number(int n,int s,int b) : num(n),strike(s),ball(b) { }
};

int t,n,s,b,ans;
bool visited[11];

vector<number> question;

// 3자리 수와 질문의 수를 비교하여 스트라이크, 볼을 계산한 뒤 비교하는 함수
bool solve(string target){
    for(int i=0; i<question.size(); i++){
        string num = to_string(question[i].num);
        int strike = 0;
        int ball = 0;
        
        // 스트라이크 유효성
        for(int j=0; j<3; j++){
            if(num[j] == target[j]) strike++;
        }
        
        // 볼 유효성
        for(int j=0; j<3; j++){
            for(int k=0; k<3; k++){
                if(j==k) continue;
                
                if(num[k] == target[j]) ball++;
            }
        }
        
        // 스트라이크 또는 볼의 개수가 일치하지 않다면 false 리턴
        if(question[i].strike != strike || question[i].ball != ball)
            return false;
    }
    // 모든 질문에 대해 답이 일치하면 true 리턴
    return true;
}

// 순열 생성
void dfs(int cnt,string d){
    if(cnt == 3){
        if(solve(d)){
            ans++;
        }
        return;
    }
    
    for(int i=1; i<=9; i++){
        if(!visited[i]){
            visited[i] = true;
            dfs(cnt+1, d+to_string(i));
            visited[i] = false;
        }
    }
}

int main() {
    
    cin >> t;
    for(int i=0; i<t; i++){
        cin >> n >> s >> b;
        question.push_back(number(n,s,b));
    }
    
    ans = 0;
    dfs(0,"");
    cout << ans;
    
    return 0;
}
