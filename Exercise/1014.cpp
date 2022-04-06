#include <iostream>

using namespace std;

struct Node{
    int no;
    Node *next;
};

Node *tail, *head;

int Size, Step;

Node *InitList(int num){
    Node *head = (Node *)malloc(sizeof(Node));
    head->no = 1;
    head->next = NULL;
    tail = head;

    for (int i = 2; i <= num; i++){
        Node *p = (Node *)malloc(sizeof(Node));
        p->no = i;
        p->next = NULL;
        tail->next = p;
        tail = p;
    }

    tail->next = head;
    return head;
}

void DelList(){
    for (int i = 1; i <= Step - 1; i++){
        head = head->next;
        tail = tail->next;
    }

    Node *p = head;
    tail->next = head->next;
    head = head->next;
    cout << p->no << " ";
    free(p);
}

int main(){
    int Start;
    cin >> Size >> Start >> Step;
    head = InitList(Size);
    while(--Start){
        head = head->next;
        tail = tail->next;
    }

    while(head != head->next){
        DelList();
    }

    cout << head->no << endl;
    free(head);
    return 0;

}