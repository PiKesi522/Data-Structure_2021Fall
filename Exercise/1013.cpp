#include <iostream>

using namespace std;

int times = 0;

// 这种队列最多的操作是出队（正常看病）和移动（紧急状况）
// 需要访问的情况较少，所以使用链式存储
// 循环链表表示队列

struct Node{
    int no;
    Node *next;
};

Node *head, *tail;

void DestroyList(){
    Node *p = head;
    while(head != tail){
        p = head->next;
        free(head);
        head = p;
    }
    free(head);
}

void Insert(int num){
    Node *p = (Node *)malloc(sizeof(Node));
    p->no = num;
    p->next = NULL;
    if(head != NULL){
        tail->next = p;
    }else{
        head = p;
    }
    tail = p;
}

void Search(int num){
    Node *p = head;
    if(head->no == num){
        return;
    }

    while(p->next->no != num){
        p = p->next;
    }

    Node *pp = p->next;
    p->next = pp->next;
    pp->next = head;
    head = pp;
}

void Deal(){
    cout << head->no << endl;
    head = head->next;
}

int main(){
    int P,C;
    while(cin >> P >> C){
        if(P == 0){
            return 0;
        }

        for (int i = 1; i <= P; i++){
            Insert(i);
        }
        tail->next = head;
        
        cout << "Case " << ++times << ":" << endl;

        char ope;
        int citizen;
        for (int i = 0; i < C; i++){
            cin >> ope;

            if(ope == 'E'){
                cin >> citizen;
                Search(citizen);
            }else{
                Deal();
            }
        }
        DestroyList();
    }
}