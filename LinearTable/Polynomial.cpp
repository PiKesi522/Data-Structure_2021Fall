#include <iostream>
using namespace std;
class term{
    public:
        int Freq;
        float Coef;
}Mytype;

class Node{
    public:
        term data;
        Node *next;
};

class Polynomial{
    public:
        Node *Head;
        void CreatePoly(int m);
        void DestroyPoly(void);
        void PrintPoly(void);
        int PolyLength(void);
        void AddPoly(Polynomial *A, Polynomial *B);
        void SubtractPoly(Polynomial *A, Polynomial *B);
        void MultiplyPoly(Polynomial *A, Polynomial *B);
};
void Polynomial::CreatePoly(int m){
    Node *Head = (Node *)malloc(sizeof(Head));
    for (int i = 0; i < m; i++){
        term T;
        scanf("(%d, %f)", &T.Freq, &T.Coef);
        Node *temp;
        temp->data = T;

        temp->next = Head->next;
        Head->next = temp;
    }
    this->Head = Head;
}
void Polynomial::DestroyPoly(void){
    Node *temp = this->Head;
    while(this->Head != NULL){
        temp = this->Head;
        this->Head = this->Head->next;
        free(temp);
    }
}
void Polynomial::PrintPoly(void){
    if(this->Head != NULL){
        cout << this->Head->data.Coef << "x^" << this->Head->data.Freq << endl;
    }
    while(this->Head != NULL){
        if(this->Head->data.Coef < 0){
            cout << this->Head->data.Coef << "x^" << this->Head->data.Freq << endl;
        }else{
            cout << "+" << this->Head->data.Coef << "x^" << this->Head->data.Freq << endl;
        }
    }
}
int Polynomial::PolyLength(void){
    int i = 0;
    while(this->Head != NULL){
        i += 1;
    }
    return i;
}
int cmp(term A, term B){
    if(A.Freq > B.Freq){
        return 1;
    }else if(A.Freq == B.Freq){
        return 0;
    }else{
        return -1;
    }
}
void Polynomial::AddPoly(Polynomial *A, Polynomial *B){
    Node *qa = A->Head->next;
    Node *qb = B->Head->next;
    while(qa != NULL && qb != NULL){
        term ta = qa->data;
        term tb = qb->data;
        switch (cmp(ta,tb))
        {
        case 1:
            break;
        case 0:

            break;
        case -1:

            break;

        default:
            break;
        }
    }
}
void Polynomial::SubtractPoly(Polynomial *A, Polynomial *B){

}
void Polynomial::MultiplyPoly(Polynomial *A, Polynomial *B){

}
