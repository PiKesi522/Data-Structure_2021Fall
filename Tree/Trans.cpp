#include <bits/stdc++.h>
using namespace std;

struct LNode{
    LNode *parent;
    int data;
    LNode *child[4];
};

struct Node {
    int parent;
    int data;
};

LNode *addr[10];
Node Tree[10];

LNode *Trans(Node Tree[], int m, int cnt){ // m = 4, cnt = 10
    if(cnt < 1){
        return;
    }
    
    LNode *root = new LNode;
    root->parent = NULL;
    root->data = Tree[0].data;
    for(int i = 0; i < m; i ++){
        root->child[i] = NULL;
    }
    addr[0] = root;

    for (int i = 1; i < cnt; i++){
        LNode *q = new LNode;
        addr[i] = q;
        q->data = Tree[i].data;
        for (int j = 0; j < m; j++){
            q->child[j] = NULL;
        }

        LNode *p = addr[Tree[i].parent];
        int j = 0;
        while(p->child[j] != NULL){
            j += 1;
        }
        p->child[j] = q;
        q->parent = p;
    }

    return root;
}

int main(){

}