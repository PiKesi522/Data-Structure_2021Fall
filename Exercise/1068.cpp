#include <bits/stdc++.h>

using namespace std;

struct Node{
    int data;
    Node *lchild;
    Node *rchild;

    Node(int i){
        this->data = i;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

int Find(int c, int *A){
    for (int i = 0;; i++){
        if(A[i] == c){
            return i;
        }
    }
    return -1;
}

int Mid[50] = {0}, Post[50] = {0};

Node *Reconstruct(int Ml, int Mr, int Pl, int Pr,int l){
    if(Pr < Pl)
        return NULL;

    int i = Post[Pr];
    int index = Find(i, Mid);
    int Left_Node_CNT = index - Ml;
    Node *root = new Node(i);
    root->lchild = Reconstruct(Ml, index - 1, Pl, Pl + Left_Node_CNT - 1, l + 1);
    root->rchild = Reconstruct(index + 1, Mr, Pl + Left_Node_CNT, Pr - 1, l + 1);

    return root;
}

int MIN_SUM = INT_MAX;
int MIN;
void dfs(Node *root, int sum){
    if(root != NULL){
        if(root ->lchild == NULL && root ->rchild == NULL){
            if(sum + root->data < MIN_SUM || (sum + root->data == MIN_SUM && root->data < MIN)){
                MIN = root->data;
                MIN_SUM = sum + root->data;
            }
        }
        dfs(root->lchild, sum + root->data);
        dfs(root->rchild, sum + root->data);
    }
}

int main(){
    int data, i;
    char ch;

    i = 0;
    while((cin >> data).get(ch)){
        Mid[i++] = data;

        if(ch == '\n')
            break;
    }

    i = 0;
    while((cin >> data).get(ch)){
        Post[i++] = data;

        if(ch == '\n')
            break;
    }

    Node *root = Reconstruct(0, i - 1, 0, i - 1, 0);
    dfs(root, 0);
    cout << MIN << endl;
    return 0;
}