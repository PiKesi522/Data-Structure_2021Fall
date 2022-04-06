#include <bits/stdc++.h>
using namespace std;
#define MAXH 81
#define MAXW 1001

bool Record[MAXW][MAXH] = {{false}};
char Map[MAXW][MAXH];
int W, H;

int MOVE[4][2] = {{1, 0}, {-1, 0}, {0, -1}, {0, 1}};

void dfs(int x, int y, int &sum){
    if(x == 0 || y == 0 || x > H || y > W){
        return;
    }
    for (int i = 0; i < 4; i++){
        int tempx = x + MOVE[i][0];
        int tempy = y + MOVE[i][1];
        if(Map[tempx][tempy] == '*' && !Record[tempx][tempy]){
            sum++;
            Record[tempx][tempy] = true;
            dfs(tempx, tempy, sum);
        }
    }
}

int main(){
    cin >> W >> H;
    getchar();
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            Map[i][j] = getchar();
        }
        getchar();
    }

    int ans = 0;
    for (int i = 1; i <= H; i++){
        for (int j = 1; j <= W; j++){
            if(Map[i][j] == '*' && !Record[i][j]){
                int sum = 1;
                Record[i][j] = true;
                dfs(i, j, sum);
                if(sum > ans)
                    ans = sum;
            }
        }
    }

    cout << ans << endl;
    return 0;
}

