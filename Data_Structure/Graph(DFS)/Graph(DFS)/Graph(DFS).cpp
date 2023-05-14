#include <iostream>
#include <vector>
using namespace std;

const int MAX = 1050;
int n,m;
vector<int> v[MAX];
bool check[MAX];

void DFS(int index){
    check[index] = true;
    cout << index << " ";
    
    for(int i = 0; i<v[index].size(); i++){
        int next = v[index][i];
        if(!check[next])
            DFS(next);
    }
}

int main(){
    cin >> n >> m;
    
    for(int i = 0; i<m; i++){
        int a,b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    DFS(0);
}
