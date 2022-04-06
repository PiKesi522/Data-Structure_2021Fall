#include<bits/stdc++.h>
using namespace std;

int main(){
    char A[4], B[4];
    cin >> A >> B;
    int ALLSame = 0, SameColor = 0;
    for (int i = 0; i < 4; i++){
        if(A[i] == B[i]){
            A[i] = 'N';
            B[i] = 'N';
            ALLSame += 1;
        }
    }

    for(int i = 0; i < 4; i++){
        if(B[i] == 'N'){
            continue;
        }

        for(int j = 0; j < 4; j++){
            if(B[i] == A[j] && A[j] != 'N'){
                B[i] = 'N';
                A[j] = 'N';
                SameColor += 1;
                continue;
            }
        }
    }

    cout << ALLSame << " " << SameColor << endl;
    return 0;
}