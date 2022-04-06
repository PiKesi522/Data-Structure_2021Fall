#include <iostream>
#include <algorithm>
using namespace std;

int n;
int cnt;
int List[14];
int Copy[14];
bool flag = true;

bool Check(int row, int col){
    for (int i = 0; i < row; i++){
        if(col == List[i] || abs(row - i) == abs(col - List[i]))
            return false;
    }
    return true;
}

void FindQueen(int k){
    if(k == n){
        cnt++;
        if(flag){
            for (int i = 0; i < n; i++){
                Copy[i] = List[i];
            }
            flag = false;
        }
        return;
    }

    for (int i = 0; i < n; i++){
        if(Check(k, i)){
            List[k] = i;
            FindQueen(k + 1);
        }
    }
}

int main(){
    cin >> n;
    FindQueen(0);
    cout << cnt << endl;
    if(cnt != 0){
        for (int i = 0; i < n; i++){
            cout << Copy[i] << " ";
        }
    }
    cout << endl;
    return 0;
}