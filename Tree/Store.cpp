#include <bits/stdc++.h>
using namespace std;
#define M 4

int cnt = 0;

struct Node{
    int data;
    Node *child[M];
};

Node *Root;

void r_preorder(Node *t){
    if(t != NULL){
        cnt += 1;
        for (int i = 0; i < M; i++){
            r_preorder(t->child[i]);
        }
    }
}

Node* s_preorder(Node *t, int x){
    Node *s[100];
    int top = 1;
    if(t == NULL){
        return;
    }
    s[0] = t;
    while(top > 0){
        t = s[--top];
        if(t->data == x){
            return t;
        }
        for (int i = M - 1; i >= 0; i--){
            if(t->child[i] != NULL){
                s[top++] = t->child[i];
            }
        }
    }
    return NULL;
}

void FindX(Node *t, int x){
    if(t != NULL){
        if(t->data == x){
            cout << "True" << endl;
            return;
        }
        for (int i = 0; i < M; i++){
            FindX(t->child[i], x);
        }
    }
}

int MAXlayer = 0;
void CntLayer(int LayerCnt, Node *Layer[]){
    Node *preLayer[65];
    int preLayerCnt = 0;

    if(LayerCnt > 0){
        MAXlayer += 1;
    }else{
        cout << MAXlayer << endl;
        return;
    }

    for (int i = 0; i < LayerCnt; i++){
        for (int j = 0; j < M; j++){
            if(Layer[i]->child[j] != NULL){
                preLayer[preLayerCnt++] = Layer[i]->child[j];
            }
        }
    }

    CntLayer(preLayerCnt, preLayer);
    
}

int main(){
    
}