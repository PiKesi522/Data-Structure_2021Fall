#include <bits/stdc++.h>
#define MAXN 1001
using namespace std;

struct LNode{
    int data;
    int parent;
    vector<int> children;
};

LNode Tree[MAXN];

void InOrderTraversal(LNode Tree[], int root){
    cout << root << ' ';
    for(int i = 0; i < (int)Tree[root].children.size(); i++){
        InOrderTraversal(Tree, Tree[root].children[i]);
    }
}

void PostOrderTraversal(LNode Tree[], int root){
    for (int i = 0; i < (int)Tree[root].children.size(); i++){
        PostOrderTraversal(Tree, Tree[root].children[i]);
    }
    cout << root << ' ';
}

void LayerTraversal(LNode Tree[], int root, int index){
    LNode Queue[MAXN], p;
    int head = 1, tail = 2;
    if(Tree == NULL)    return;
    Queue[1] = Tree[root];
    while (head < tail){
        p = Queue[head++];
        cout << p.data << ' ';
        for (int i = 0; i < (int)p.children.size(); i++){
            Queue[tail++] = Tree[p.children[i]];
        }
    }
}

int Cntleaf = 0;
void CntLeave(LNode Tree[], int root){
    int i = 0;
    for (; i < (int)Tree[root].children.size(); i++){
        CntLeave(Tree, Tree[root].children[i]);
    }
    if(i == 0){
        cout << root << ' ';
        Cntleaf += 1;
    }
}

int Height = 0;
void CntHeight(LNode Tree[], int root, int THeight){
    int i = 0;
    for (; i < (int)Tree[root].children.size(); i++){
        CntHeight(Tree, Tree[root].children[i], THeight + 1);
    }
    if(THeight > Height)    Height = THeight;
}

int main(){
    int index, parent;
    while(cin >> index >> parent){
        Tree[index].data = index;
        Tree[index].parent = parent;
    }

    int root = 0;
    for (int i = 1; i <= index; i++){
        if(Tree[i].parent != -1){
            Tree[Tree[i].parent].children.push_back(i);
        }else{
            root = i;
        }
    }

    // 前序遍历
    InOrderTraversal(Tree, root);
    cout << endl;

    // 后序遍历
    PostOrderTraversal(Tree, root);
    cout << endl;

    // 层次遍历
    LayerTraversal(Tree, root, index);
    cout << endl;

    // 计算结点数
    cout << index << endl;

    // 计算叶子结点数，输出叶子结点
    CntLeave(Tree, root);
    cout << endl << Cntleaf << endl;

    // 计算树的高度
    CntHeight(Tree, root, 0);
    cout << Height << endl;

    return 0;
}