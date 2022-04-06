#include <bits/stdc++.h>

using namespace std;

struct Node{
    int PRIOR_KEY;
    char MESSAGE[10] = {'\0'};
    Node* lchild;
    Node* rchild;

    Node(int i){
        this->PRIOR_KEY = i;
        this->lchild = NULL;
        this->rchild = NULL;
    }
};

Node* Put(Node *root){
    char MES[10] = {'\0'};
    int PRI;
    cin >> MES >> PRI;
    Node *ATARASHI = new Node(PRI);
    strcpy(ATARASHI->MESSAGE, MES);

    if(root->rchild == NULL){
        root->rchild = ATARASHI;
    }else{
        Node *temp = root->rchild;
        while(1){
            if(PRI > temp->PRIOR_KEY){
                if(temp->rchild == NULL){
                    temp->rchild = ATARASHI;
                    break;
                }else{
                    temp = temp->rchild;
                }
            }else{
                if(temp->lchild == NULL){
                    temp->lchild = ATARASHI;
                    break;
                }else{
                    temp = temp->lchild;
                }
            }
        }
    }
    return root;
}

Node* Get(Node *root){
    if(root->rchild == NULL){
        cout << "EMPTY QUEUE!" << endl;
        return root;
    }

    Node *head = root->rchild;

    if(head->lchild == NULL){
        cout << head->MESSAGE << endl;
        root->rchild = head->rchild;
        free(head);
    }else{
        Node *Parent = head;
        head = head->lchild;
        while(head->lchild != NULL){
            Parent = head;
            head = head->lchild;
        }
        cout << head->MESSAGE << endl;
        Parent->lchild = head->rchild;
        free(head);
    }
    return root;
}

int main(){
    Node *Root = new Node(-1);
    int MESSAGE_CNT;
    char OPERATE[3];
    cin >> MESSAGE_CNT;
    for(int i = 0; i < MESSAGE_CNT; i++){
        cin >> OPERATE;
        if(OPERATE[0] == 'P'){
            Root = Put(Root);
        }else{
            Root = Get(Root);
        }
    }
    return 0;
}
