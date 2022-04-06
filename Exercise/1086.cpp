#include <iostream>
using namespace std;
struct NODE{
    int num;
    int cnt;
    NODE() : num(0), cnt(0){};
};
int main(){
    int N, M;
    cin >> N >> M;
    NODE Bank[1001];
    for (int i = 1; i < N; i++){
        Bank[i].num = i;
        Bank[i].cnt = 0;
    }
    int num1, num2;
    bool Martix[1001][1001] = {{false}};

    for (int i = 0; i < M; i++){
        cin >> num1 >> num2;
        Martix[num1][num2] = true;
        Martix[num2][num1] = true;
        Bank[num1].cnt++;
        Bank[num2].cnt++;
    }

    for (int i = 1; i <= N; i++)
        for (int j = i + 1; j <= N; j++)
            for(int k = 1 ; k <= N; k++)
                if(!Martix[i][j])
                    if(Martix[i][k] && Martix[k][j]){
                        Martix[i][j] = true;
                        Martix[j][i] = true;
                    }

    for (int i = 1; i <= N; i++){
        for (int j = i + 1; j <= N; j++){
            if(!Martix[i][j]){
                cout << '0' << endl;
                return 0;
            }
        }
        if(Bank[i].cnt & 1){
            cout << '0' << endl;
            return 0;
        }
    }

    cout << '1' << endl;
    return 0;
}