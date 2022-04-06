#include <bits/stdc++.h>

using namespace std;
int SIZE;
string PWDLIST[20001];

bool isSubstring(string A, string B){
    if(A.size() > B.size()){
        return false;
    }

    for (int i = 0; i < B.size() - A.size() + 1; i++){
        for (int j = 0; j < A.size(); j++){
            if(A[j] != B[i+j]){
                break;
            }
            if(j == A.size() - 1){
                return true;
            }
        }
    }

    return false;
}

int main(){
    int cnt = 0;
    cin >> SIZE;
    for (int i = 0; i < SIZE; i++){
        cin >> PWDLIST[i];
    }
    for (int i = 0; i < SIZE; i++){
        for (int j = 0; j < SIZE; j++){
            if(i == j)
                continue;

            if(isSubstring(PWDLIST[i], PWDLIST[j]))
                cnt++;
        }
    }
    cout << cnt << endl;
    return 0;
}