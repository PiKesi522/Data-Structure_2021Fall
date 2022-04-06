#include <iostream>
// 将结点A插入值为B的结点之前，若不存在，则插入到节点最后
using namespace std;

struct Node{
    int data;
    Node *next;
    Node *prev;
};

void Insert(Node *head, int A, int B){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = A;
    temp->next = NULL;
    temp->prev = NULL;

    Node *p = head;
    while(p->next != NULL){
        if(p->data == A){
            temp->next = p;
            p->prev->next = temp;
            temp->next->prev = temp;
            temp->prev = p->prev;
            return;
        }
        p = p->next;
    }
    
    if(p->data == A){
        temp->next = p;
        p->prev->next = temp;
        temp->next->prev = temp;
        temp->prev = p->prev;
        return;
    }else{
        p->next = temp;
        temp->prev = p;       
    }


}

int main(){

}