#include <bits/stdc++.h>
using namespace std;

typedef struct TripleTuple{
    int col;
    int row;
    int data;
}T;

int m1, n1, c1, m2, n2, c2;

int main(){
    deque<T> A, B, C;
    T temp;

    cin >> m1 >> n1 >> c1;
    for (int i = 0; i < c1; i++){
        cin >> temp.col >> temp.row >> temp.data;
        A.push_back(temp);
    }

    cin >> m2 >> n2 >> c2;
    for (int i = 0; i < c2; i++){
        cin >> temp.col >> temp.row >> temp.data;
        B.push_back(temp);
    }

    while(!A.empty() && !B.empty()){
        if(A[0].col < B[0].col){
            C.push_back(A[0]);
            A.pop_front();
        }else if(A[0].col > B[0].col){
            C.push_back(B[0]);
            B.pop_front();
        }else{
            if(A[0].row < B[0].row){
                C.push_back(A[0]);
                A.pop_front();
            }else if(A[0].row > B[0].row){
                C.push_back(B[0]);
                B.pop_front();
            }else{
                temp.col = A[0].col;
                temp.row = A[0].row;
                temp.data = A[0].data + B[0].data;
                C.push_back(temp);
                A.pop_front();
                B.pop_front();
            }
        }
    }
    while(!A.empty()){
        // C.push_back(*(A.end() - 1));
        C.push_back(A.back());
        A.pop_back();
    }
    while(!B.empty()){
        C.push_back(B.back());
        B.pop_back();
    }
    for(T v : C){
        cout << v.col << ' ' << v.row << ' ' << v.data << endl;
    }
    return 0;
}