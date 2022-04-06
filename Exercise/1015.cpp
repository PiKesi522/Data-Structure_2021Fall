#include <iostream>

using namespace std;

int m,n;

struct Node{
    int data;
    Node *next;
};

Node *head, *tail;
int used = 1;

Node *InitQueue(){
    Node *head = (Node *)malloc(sizeof(Node));
    head->data = -1;
    head->next = NULL;
    tail = head;
    return head;
}

void Dequeue(){
    Node *p = head;
    head = head->next;
    free(p);
}

void Enqueue(int num){
    Node *p = (Node *)malloc(sizeof(Node));
    p->data = num;
    p->next = NULL;
    tail->next = p;
    tail = p;
}

bool Find(int num){
    Node *p = head;
    while(p != NULL){
        if(p->data == num){
            return true;
        }
        p = p->next;
    }
    return false;
}

int main(){
    cin >> m >> n;
    int num, cnt = 0;
    int rec = -1;
    head = InitQueue();
    for (int i = 0; i < n; i++){
        cin >> num;
        if(!Find(num)){
            if(used >= m){
                Dequeue();
            }
            Enqueue(num);
            used += 1;
            cnt += 1;
        }
    }
    cout << cnt << endl;
    return 0;
}