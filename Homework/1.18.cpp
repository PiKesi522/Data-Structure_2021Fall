#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node* Trans(Node *Head){
    Node *p = Head;
    while (p->next != NULL){
        p = p->next;
    }
    Node *tail = p;
    tail->next = Head;
    return tail;
}

int main(){

}