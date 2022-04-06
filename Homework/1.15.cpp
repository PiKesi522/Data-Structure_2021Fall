#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *Merge(Node *A, Node *B){
    Node *pA = A;
    Node *pB = B;

    Node *head = (Node *)malloc(sizeof(Node));
    head->data = 0;
    head->next = NULL;
    Node *p = head;

    while(pA != NULL && pB != NULL){
        Node *nextA = pA;
        pA = pA->next;
        Node *nextB = pB;
        pB = pB->next;

        p->next = nextA;
        p = p->next;
        p->next = nextB;
        p = p->next;
    }

    if(pA == NULL && pB == NULL){
        return head;
    }

    if(pA == NULL){
        p->next = pB;
    }else if(pB == NULL){
        p->next = pA;
    }
    return head;
}

int main(){

}