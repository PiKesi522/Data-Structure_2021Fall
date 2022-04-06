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

int Pre[50];

Node *Reconstruct(int head, int tail){
    if(tail < head){
        return NULL;
    }
    
    int d = Pre[head];
    Node *root = new Node(d);
    
    int left = head + 1, right = tail;
    while(d > Pre[left])
        left += 1;
    while(d < Pre[right])
        right -= 1;
        
    root->lchild = Reconstruct(head + 1, right);
    root->rchild = Reconstruct(left, tail);
    
    return root;
}

void TransToPost(Node *root){
    if(root->lchild != NULL)
        TransToPost(root->lchild);
    if(root->rchild != NULL)
        TransToPost(root->rchild);
    cout << root->data << endl;
}

int main()
{
    int num, i = 0;
    while(cin >> num) {
        Pre[i++] = num;
    }
    cout << "end" << endl;
    // cin >> num;
    Node *root = Reconstruct(0, i-1);
    TransToPost(root);
    return 0;
}
