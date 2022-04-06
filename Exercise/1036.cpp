#include <iostream>

using namespace std;

void replace(char A[], char B[], char C[]){
    char ans[240] = {'\0'};
    int len = 0;
    int la = 0, lb = 0, lc = 0;
    for (int i = 0; i < 80; i++){
        if(A[i] != '\0'){
            la += 1;
        }
        if(B[i] != '\0'){
            lb += 1;
        }
        if(C[i] != '\0'){
            lc += 1;
        }
        if(A[i] == '\0' && B[i] == '\0' && C[i] == '\0'){
            break;
        }
    }

    for (int i = 0; i < la; i++){
        for (int j = 0; j < lb; j++){
            if(A[i + j] != B[j] || i + j > la){
                // 匹配失败
                ans[len++] = A[i];
                break;
            }

            if(j == lb - 1){
                // 匹配成功
                for (int k = 0; k < lc; k++){
                    ans[len++] = C[k];
                }
                i += lb - 1;
                break;
            }
        }
    }

    cout << ans << endl;
}

int main(){
    char A[80] = {'\0'}, B[80] = {'\0'}, C[80] = {'\0'};
    cin >> A >> B >> C;
    replace(A, B, C);
    return 0;
}