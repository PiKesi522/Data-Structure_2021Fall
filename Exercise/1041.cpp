#include <bits/stdc++.h>

using namespace std;

int BW(){
    string A, B;
    cin >> A >> B;
    for (int i = 0; i < A.size() - (B.size() - 1); i++){
        for (int j = 0; j < B.size(); j++){
            if(A[i + j] != B[j])
                break;
            if(j == B.size() - 1)
                return i;
        }
    }
    return -1;
}

int main(){
    cout << BW() << endl;
    return 0;
}