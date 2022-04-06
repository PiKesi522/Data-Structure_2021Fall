#include <iostream>
// 多项式乘法
#include <algorithm>

using namespace std;

#define AList_Length 10
#define BList_Length 8

struct Poly{
    int cof;
    int exp = -1;
};

Poly ListA[AList_Length];
Poly ListB[BList_Length];
Poly ListAns[AList_Length * BList_Length + 1];
int used_Elem = 0;

void Insert(Poly *C, int exp, int cof){
    int i = 0;
    for (i = 0; i < AList_Length * BList_Length + 1; i++){
        if(ListAns[i].exp == exp){
            ListAns[i].cof += cof;
            return;
        }

        if(ListAns[i].exp == -1){
            used_Elem += 1;
            ListAns[i].exp = exp;
            ListAns[i].cof = cof;
            return;
        }
    }
    return;
}

void Deal(Poly *A, Poly *B, Poly *C){
    int exp = A->exp + B->exp;
    int cof = A->cof * B->cof;

    if(cof == 0){
        return;
    }

    Insert(C, exp, cof);
}

bool cmp(Poly A, Poly B){
    return A.cof < B.cof;
}

int main(){
    
    Poly *Ans = &ListAns[0];
    Poly *A_head = &ListA[0];
    Poly *B_head = &ListB[0];

    for (int i = 0; i < AList_Length; i++){
        for (int j = 0; i < BList_Length; j++){
            Deal(A_head, B_head, Ans);
        }
    }

    sort(ListAns, ListAns + used_Elem, cmp);

}
