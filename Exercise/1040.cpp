/*  最长回文子串
 *  
 */
#include <bits/stdc++.h>
using namespace std;

string solve(){
    string A;
    string ans = "";
    cin >> A;
    int len = A.size();
    bool dp[200][200] = {false};
    for (int i = 0; i < len; i++){
        for (int j = i; j >= 0; j--){
            // 从 j 到 i 检测回文

            if(A[i] == A[j] && (i - j < 2 || dp[i-1][j+1])){
            // 当前位置相同    相邻或者同一格  内部一格也是回文
                dp[i][j] = true;
            }

            if(dp[i][j] && (i - j + 1 > (int)ans.size())){
                ans = A.substr(j, (i - j + 1));
            }
        }
    }
    return ans;
}


int main(){
    string ans;
    int time;
    cin >> time;
    for (int i = 0; i < time; i++){
        ans = solve();
        cout << "case #" << i << ":" << endl;
        cout << ans.size() << endl;
    }
    return 0;
}