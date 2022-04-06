#include <iostream>
using namespace std;

// 删除值为A的节点的前趋节点

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void DeleNode(Node *head, int A){
    if(head == NULL){
        cout << "Empty" << endl;
    }
    Node *p = head;
    while(p->next != NULL){
        if(p->data == A){
            Node *pre = p->prev->prev;
            free(p->prev);
            pre->next = p;
            p->prev = pre;
        }
        p = p->next;
    }
    if(p->data == A){
        Node *pre = p->prev->prev;
        free(p->prev);
        pre->next = p;
        p->prev = pre;
    }else{
        cout << "NotFound" << endl;
    }

}

int main(){

}