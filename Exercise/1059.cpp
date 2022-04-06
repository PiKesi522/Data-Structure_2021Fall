#include <bits/stdc++.h>
using namespace std;

struct Data{
    int Freq = 0;
    int Num;
};

bool cmp(Data A, Data B){
    if(A.Freq != B.Freq){
        return A.Freq > B.Freq;
    }else{
        return A.Num < B.Num;
    }
}

void Solve(){
    int size, num;
    Data List[501];
    cin >> size;
    
    for (int i = 0; i < size; i++){
        cin >> num;
        List[num].Freq += 1;
    }
    
    for (int i = 0; i < 501; i++){
        List[i].Num = i;
    }

    sort(List, List + 501, cmp);
    
    for (int i = 0; i < 501; i++){
        for (int j = 0; j < List[i].Freq; j++){
            cout << List[i].Num << " ";
        }
    }
    cout << endl;
}

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++){
        cout << "case #" << i << ":" << endl;
        Solve();
    }
    return 0;
}