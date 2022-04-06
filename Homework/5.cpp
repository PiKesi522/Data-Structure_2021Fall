#include <bits/stdc++.h>
using namespace std;

struct LNODE{
    int data;
    LNODE *lchild;
    LNODE *rchild;

    LNODE(int data){
        this->data = data;
        this->lchild = NULL;
        this->rchild = NULL;
    }

};

void exchange(LNODE *p){
    if(p->lchild != NULL)   
        exchange(p->lchild);
    if(p->rchild != NULL)   
        exchange(p->rchild);

    LNODE *temp = p->lchild;
    p->lchild = p->rchild;
    p->rchild = temp;
}

bool Judge_Bina_Complete(LNODE *p){
    if(p->lchild != NULL && p->rchild != NULL)
        return (Judge_Bina_Complete(p->lchild) && Judge_Bina_Complete(p->rchild));
    
    if(p->lchild != NULL || p->rchild != NULL)
        return false;
    
    return true;
}

bool Judge_Similar(LNODE *p1, LNODE *p2){
    if(p1 == NULL && p2 == NULL)
        return true;
    
    if(p1 == NULL || p2 == NULL)
        return false;

    return (Judge_Similar(p1->lchild, p1->rchild) && Judge_Similar(p2->lchild, p2->rchild));
}

int main(){

}