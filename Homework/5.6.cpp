#include <bits/stdc++.h>
using namespace std;
#define MAX 128

struct Node{
    char data;
    Node *lchild;
    Node *rchild;
    Node(char c){
        this->data = c;
        this->lchild = NULL;
        this->rchild = NULL;
    }
    Node(){
        this->data = '\0';
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

char Pre[MAX], Mid[MAX];

void TransToTree(Node *root, int i, int j, int len){
    if(len <= 0)
        return;
    root = new Node(Pre[i]);
    int m = strchr(Mid, Pre[i]) - Mid;
    TransToTree(root->lchild, i + 1, j, m - j);
    TransToTree(root->rchild, i + (m - j) + 1, m + 1, len - 1 - (m - j));
}

void Ctree(Node* t,char A[],int i)
{
    if(t!=NULL){
        A[i]=t->data;
        Ctree(t->lchild,A,i*2);
        Ctree(t->rchild,A,i*2+1);
    }else{
        A[i]=' ';
    }
}


int main(){

}