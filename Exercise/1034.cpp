#include <iostream>
#include <string>
using namespace std;

void Solve(){
    int N;
    char S[500] = {'\0'};
    cin >> N >> S;
    int left = 0, right = N - 1;
    char ans[500] = {'\0'};
    int i = 0;
    while(left <= right){
        if(S[left] < S[right]){
            ans[i++] = S[left++];
        }else if(S[left] > S[right]){
            ans[i++] = S[right--];
        }if(S[left] == S[right]){
            int tleft = left, tright = right;
            while(S[tleft] == S[tright]){
                tleft++;
                tright--;

                if(tleft > tright){
                    for (int j = left; j <= right; j++){
                        ans[i++] = S[j];
                    }
                    cout << ans << endl;
                    return;
                }

                if(S[tleft] > S[tright]){
                    ans[i++] = S[right--];
                    break;
                }else if(S[tleft] < S[tright]){
                    ans[i++] = S[left++];
                    break;
                }
            }
        }
    }
    cout << ans << endl;
}

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "case #" << i << ":" << endl;
        Solve();
    }
}