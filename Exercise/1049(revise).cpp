#include <bits/stdc++.h>
using namespace std;

typedef struct TripleTuple{
    int col;
    int row;
    int data;
}T;

int m1, n1, c1, m2, n2, c2;
T A[100];
vector<T> B;

T *p = &A[0];

bool isSmallerThan(T t){
    if (p > &A[c1 - 1]){
        return false;
    }

    if(p->col != t.col){
        return p->col < t.col;
    }else{
        return p->row < t.row;
    }
}

int main(){
    T temp;
    int k;
    k = 0;
    cin >> m1 >> n1 >> c1;
    for (int i = 0; i < c1; i++){
        cin >> A[k].col >> A[k].row >> A[k++].data;
    }

    k = 0;
    cin >> m2 >> n2 >> c2;
    for (int i = 0; i < c2; i++){
        cin >> temp.col >> temp.row >> temp.data;

        while(isSmallerThan(temp)){
            B.push_back(*p);
            p += 1;
        }

        if(p->col == temp.col && p->row == temp.row){
            temp.data += p->data;
            p += 1;
        }

        B.push_back(temp);
    }

    while(p <= &A[c1 - 1]){
        B.push_back(*p);
        p += 1;
    }

    for (T v : B){
        printf("%d %d %d\n", v.col, v.row, v.data);
    }
    return 0;
}