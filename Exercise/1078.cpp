#include <bits/stdc++.h>
#define MAXN 1000
using namespace std;

struct Node{
    int data;
    Node* lchild;
    Node* rchild;

    Node(int i){
        this->data = i;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

int w[2*MAXN - 1];

Node *create_huffman_tree(int w[], int n){
    Node *addr[2 * MAXN - 1];
    for(int i = 0; i < n; i++){
        Node *temp = new Node(w[i]);
        addr[i] = temp;
        w[i] = -w[i];
    }
    
    for(int i = n; i < 2 * n - 1; i++){
        int n1 = -1, n2 = -1, min1 = INT_MAX, min2 = INT_MAX;
        for(int j = 0; j < i; j++){
            int v = w[j];
            int u = -v;
            if(u > 0){
                if(u < min1){
                    min2 = min1;
                    n2 = n1;
                    min1 = u;
                    n1 = j;
                }else if(u < min2){
                    min2 = u;
                    n2 = j;
                }
            }
        }
        Node *temp = new Node(-1);
        addr[i] = temp;
        addr[i]->lchild = addr[n1];
        addr[i]->rchild = addr[n2];
        w[i] = w[n1] + w[n2];
        w[n1] = -w[n1];
        w[n2] = -w[n2];
    }
    w[2*n-2] = -w[2*n-2];
    return addr[2*n-2];
}

int OutCount = 0;
void CountValue(int Layer, Node *root){
    if(root->data == -1){
        CountValue(Layer + 1, root->lchild);
        CountValue(Layer + 1, root->rchild);
    }else{
        OutCount += root->data * Layer;
    }
}

int main(){
    int N;
    cin >> N;
    for(int i = 0; i < N; i++)
        cin >> w[i];

    Node *List = create_huffman_tree(w, N);

    CountValue(0, List);
    cout << OutCount << endl;
    
    return 0;
}
