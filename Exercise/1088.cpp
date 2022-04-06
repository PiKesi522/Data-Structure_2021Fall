#include <bits/stdc++.h>
using namespace std;
#define MAXN 105
#define MAXM 1005

int N, M;
typedef int MAT[MAXN][MAXN];
MAT a, path, cost = {{0}};

void Dijkstra(MAT cost, int n, int v, int dist[], int pre[]){
    bool Record[MAXN] = {false};
    for (int i = 1; i <= n; i++){
        dist[i] = cost[v][i];
        pre[i] = (dist[i] < INT_MAX) ? v : 0;
    }
    Record[v] = true;
    pre[v] = 0;

    for (int i = 1; i <= n; i++){
        int min = INT_MAX;
        int k = 0;
        for (int j = 1; j <= n; j++)
            if(!Record[j])
                if(dist[j] != 0 && dist[j] < min){
                    min = dist[j];
                    k = j;
                }
        if(k == 0)
            continue;
        Record[k] = true;
        for (int j = 1; j <= n; j++){
            if(!Record[j] && cost[k][j] < INT_MAX){
                dist[j] = dist[k] + cost[k][j];
                pre[j] = k;
            }
        }
    }
}

int main(){
    cin >> N >> M;
    int l1, l2, c;
    for (int i = 1; i <= M; i++){
        cin >> l1 >> l2 >> c;
        cost[l1][l2] = c;
        cost[l2][l1] = c;
    }
    int dist[MAXN], pre[MAXN];
    Dijkstra(cost, N, 1, dist, pre);
    if(dist[N] == 0){
        cout << -1 << endl;
    }else{
        cout << dist[N] << endl;
    }

    
    
}