#include <bits/stdc++.h>

using namespace std;

struct Node{
    char data;
    Node *lchild;
    Node *rchild;
    Node(char c){
        this->data = c;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

char Pre[55] = {'\0'}, Mid[55] = {'\0'};

int Find(char c, char *A, int size){
    for (int i = 0; i < size; i++){
        if(A[i] == c){
            return i;
        }
    }
    return -1;
}

Node *Reconstrcut(int size, char *Pre, char *Mid){
    if(size == 0)
        return NULL;

    char c = Pre[0];
    // 先序的首元素必是根结点

    int index = Find(c, Mid, size);
    // 找到根结点相应的中序的位置

    Node *temp = new Node(c);

    temp->lchild = Reconstrcut(index, Pre + (1), Mid);
    // 根结点左边递归构造左子树

    temp->rchild = Reconstrcut(size - index - 1, Pre + (1 + index), Mid + (1 + index));
    // 根结点右边递归构造右子树

    return temp;
}

int CountLayer(Node *root){
    if(root == NULL)
        return 0;
    int Left_layer = CountLayer(root->lchild);
    int Right_layer = CountLayer(root->rchild);
    return max(Left_layer, Right_layer) + 1;
}

int main(){
    int size;
    cin >> size >> Pre >> Mid;
    Node *root = Reconstrcut(size, Pre, Mid);
    cout << CountLayer(root) << endl;
    return 0;
}