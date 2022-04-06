#include <bits/stdc++.h>
using namespace std;
#define MAXN 1005
#define MAXM 3005

int N, M, S;
bool Record[MAXN] = {false};
bool Martix[MAXN][MAXN] = {{false}};

void dfs(int u){
    Record[u] = true;
    cout << u << ' ';
    for (int i = 1; i <= N; i++){
        if(Martix[u][i] && !Record[i]){
            dfs(i);
            cout << u << ' ';
        }
    }
}

int main(){
    cin >> N >> M >> S;
    int e1, e2;
    for (int i = 0; i < M; i++){
        cin >> e1 >> e2;
        Martix[e1][e2] = true;
        Martix[e2][e1] = true;
    }

    dfs(S);

    for (int i = 1; i <= N; i++){
        if(!Record[i]){
            cout << 0 << endl;
            return 0;
        }
    }
    cout << endl;
    return 0;
}