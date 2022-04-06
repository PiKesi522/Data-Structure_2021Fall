#include <bits/stdc++.h>
#define MAX 100000
char T[MAX], P[MAX];
int flink[MAX];
int M, N;
using namespace std;

void faillink(string P){
    int j = 1, k;
    flink[0] = -1;
    while(j < M){
        k = flink[j - 1];
        while((k != -1) && P[k] != P[j-1]){
            k = flink[k];
        }
        flink[j] = k + 1;
        j++;
    }
}

int KMP_Match(string T, string P){
    int i = 0, j = 0;
    while(i < N){
        while(j != -1 && P[j] != T[i]){
            j = flink[j];
        }
        if(j == M-1){
            return (i - M + 1);
        }
        i++;
        j++;
    }
    return -1;
}

int main(){
    string T, P;
    cin >> T >> P;
    N = T.size();
    M = P.size();
    faillink(P);
    cout << KMP_Match(T, P) << endl;
    for (int i = 0; i < (int)P.size(); i++){
        cout << flink[i] << " ";
    }
    cout << endl;
    return 0;
}