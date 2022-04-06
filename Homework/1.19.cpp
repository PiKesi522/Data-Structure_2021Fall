#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *Trans(Node *Head){
    Node *p = Head;
    Node *title = (Node *)malloc(sizeof(Node));
    title->data = 0;
    title->next = NULL;         
    Node *tp = title->next;
    while(p->next != NULL){
        title->data++;
        tp = p;
        p = p->next;
    }
    title->data++;
    tp = p;
    tp->next = title->next;
    return title;
}

int main(){

}