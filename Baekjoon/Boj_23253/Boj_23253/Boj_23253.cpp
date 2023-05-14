#include <iostream>
using namespace std;

int N,M,k,cur,pre;
bool flag = true;
int main(void){
    cin>>N>>M;
    for(int i=0;i<M;++i){
        cin>>k; pre=N+1;
        for(int j=0;j<k;++j){
            cin>>cur;
            if(cur>pre){
                flag=false;
                break;
            }
            pre=cur;
        }
        if(!pre) break;
    }

    if(flag) cout<<"Yes";
    else cout<<"No";
    return 0;
}
