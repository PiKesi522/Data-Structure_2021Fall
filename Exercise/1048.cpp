#include <bits/stdc++.h>
using namespace std;
int a, b, c;

typedef struct TripleTuple{
    int col;
    int row;
    int data;
}T;

bool cmp(T A, T B){
    if(A.col != B.col){
        return A.col < B.col;
    }else{
        return A.row < B.row;
    }
}

int main(){
    cin >> a >> b >> c;
    vector<T> List;
    for (int i = 0; i < c; i++){
        T temp;
        cin >> temp.row >> temp.col >> temp.data;
        List.push_back(temp);
    }

    sort(List.begin(), List.end(), cmp);

    for(T v : List){
        cout << v.col << ' ' << v.row << ' ' << v.data << endl;
    }

    return 0;
}
