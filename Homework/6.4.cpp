#include <bits/stdc++.h>
using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

int LayerMax = 0;
int CountLayer(Node *root){
    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }

    if(root->lchild == NULL){
        return CountLayer(root->rchild);
    }

    if(root->rchild == NULL){
        return CountLayer(root->lchild);
    }

    int Left = CountLayer(root->lchild);
    int Right = CountLayer(root->rchild);
    return ((Left > Right) ? Left : Right) + 1;
}

int main(){

}