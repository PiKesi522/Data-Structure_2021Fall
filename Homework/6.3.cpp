#include <bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node *lchild;
    Node *rchild;
};

int present = INT_MAX;

void InorderTraversal(Node *root){
    if(root->lchild != NULL){
        InorderTraversal(root->lchild);
    }

    if(present > root->data){
        cout << "No" << endl;
        return;
    }else{
        present = root->data;
    }

    if(root->rchild != NULL){
        InorderTraversal(root->rchild);
    }
} 

int main(){

}