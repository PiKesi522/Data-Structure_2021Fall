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

struct print{
    int data;
    int layer;
    int index;
};

print NodeLayer[50];

Node *Reconstruct(int Ml, int Mr, int Pl, int Pr, int l){
    if(Pr < Pl)
        return NULL;

    int i = Post[Pr];
    int index = Find(i, Mid);
    int Left_Node_CNT = index - Ml;
    Node *root = new Node(i);
    root->lchild = Reconstruct(Ml, index - 1, Pl, Pl + Left_Node_CNT - 1, l + 1);
    root->rchild = Reconstruct(index + 1, Mr, Pl + Left_Node_CNT, Pr - 1, l + 1);

    // 用于显示二叉树
    NodeLayer[index].layer = l;
    NodeLayer[index].data = i;
    NodeLayer[index].index = index;
    return root;
}

bool cmp(print A, print B){
    if(A.layer != B.layer)
        return A.layer < B.layer;
    else
        return A.index < B.index;
}

void CalcuNodeLayer(int *Mid, int size){
    for (int i = 0; i < size; i++){
        NodeLayer[i].index = i;
        NodeLayer[i].data = Mid[i];
    }
}

void Print(int size){
    sort(NodeLayer, NodeLayer + size, cmp);

    for (int i = 0; i < NodeLayer[0].index; i++)
        cout << ' ';

    cout << NodeLayer[0].data << ' ';

    for (int i = 1; i < size; i++){
        int blank = NodeLayer[i].index;

        if(NodeLayer[i].layer == NodeLayer[i-1].layer)
            blank -= (NodeLayer[i - 1].index + 1);
        else
            cout << endl;

        for (int j = 0; j < blank; j++)
            cout << ' ';

        cout << NodeLayer[i].data << ' ';
    }
    cout << endl;
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
    // CalcuNodeLayer(Mid, i);
    Print(i);
    return 0;
}