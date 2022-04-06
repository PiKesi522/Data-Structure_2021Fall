#include <iostream>

using namespace std;

int n;

struct node{
    int data;
    node *next;
};

void Create_List(node *head){
    head->next = NULL;
    head->data = -1;
    return;
}

node *newNode(int num){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    return temp;
}

void Insert_List(node *head, int num){
    node *nextNode = newNode(num);
    nextNode->next = head->next;
    head->next = nextNode;
    return;
}

void Search_List(node *head, int num){
    node *p = head->next;
    int cnt = 0;
    while(p){
        if(p->data == num){
            cout << (n-cnt-1) << endl;
            return;
        }

        p = p->next;
        cnt += 1;
    }
    cout << -1 << endl;
}

int main(){

    cin >> n;

    node *head = (node *)malloc(sizeof(node));
    Create_List(head);

    int num;
    for (int i = 0; i < n; i++){
        cin >> num;
        Insert_List(head, num);
    }

    int v;
    cin >> v;
    Search_List(head, v);

    return 0;
}
