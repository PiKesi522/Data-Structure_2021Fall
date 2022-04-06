#include <iostream>
#define MAX 1000
using namespace std;

typedef struct TripleTuple{
    int col;
    int row;
    int data;
} TT;

void Insert(TT A[], TT B[], int &A_loc, int &B_loc){
    A[A_loc].col = B[B_loc].col;
    A[A_loc].row = B[B_loc].row;
    A[A_loc++].data = B[B_loc++].data;
}

int main(){
    TT A[MAX];
    TT B[MAX];


    int Cnt_A_Elem = A[0].data, Cnt_B_Elem = B[0].data;
    int pre_A = 1, pre_B = 1, pre_C = 1;
    TT C[MAX+MAX];
    if(A[0].col != B[0].col || A[0].row != B[0].row){
        cout << "Different Size" << endl;
        return 0;
    }

    while(pre_A <= Cnt_A_Elem && pre_B <= Cnt_B_Elem){
        if(A[pre_A].row == B[pre_B].row){
            if(A[pre_A].col == B[pre_B].col){
                C[pre_C].col = A[pre_A].col;
                C[pre_C].row = A[pre_A].row;
                C[pre_C++].data = A[pre_A++].data + B[pre_B++].data;
            }else if(A[pre_A].col < B[pre_B].col){
                Insert(C, A, pre_C, pre_A);
            }else{
                Insert(C, B, pre_C, pre_B);
            }
        }else if(A[pre_A].row < B[pre_B].row){
            Insert(C, A, pre_C, pre_A);    
        }else{
            Insert(C, B, pre_C, pre_B);
        }
    }

    while(pre_A <= Cnt_A_Elem){
        Insert(C, A, pre_C, pre_A);
    }
    while(pre_B <= Cnt_B_Elem){
        Insert(C, B, pre_C, pre_B);
    }

    C[0].col = A[0].col;C[0].row = A[0].row;
    C[0].data = pre_C - 1;
}