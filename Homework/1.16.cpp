#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

bool isEmpty(Node *pA, Node *A){
    return pA->next == A;
}   

void Move(Node *pA, Node *p){
    Node *temp = (Node *)malloc(sizeof(Node));
    temp->data = pA->data;
    temp->next = NULL;

    p->next = temp;
    p = p->next;

    pA = pA->next;
}

Node *Merge(Node *A, Node *B){
    Node *pA = A;
    Node *pB = B;

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    Node *p = head;

    while(!isEmpty(pA, A) && !isEmpty(pB, B)){
        if(pA->data > pB->data){
            Move(pA, p);
        }else{
            Move(pB, p);
        }
    }

    if(isEmpty(pA, A) && isEmpty(pB, B)){
        return head;
    }

    if(isEmpty(pA, A)){
        p->next = pB;
    }else{
        p->next = pA;
    }
    return head;
}

int main(){

}