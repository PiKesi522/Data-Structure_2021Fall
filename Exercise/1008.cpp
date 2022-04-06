#include <iostream>

using namespace std;

struct node{
    int data;
    node *next;
};

void Create_List(node *head){
    head->data = -1;
    head->next = NULL;
    return;
}

node* newNode(int num){
    node *temp = (node *)malloc(sizeof(node));
    temp->data = num;
    temp->next = NULL;
    return temp;
}


void Search_List(node *head, int num){
    node *p = head;
    while(p->next){
        if(p->next->data == num){
            return ;
        }else if(p->next->data > num){
            node *nextNode = newNode(num);
            nextNode->next = p->next;
            p->next = nextNode;
            return;
        }
        p = p->next;
    }
}

int main(){
    int N;
    cin >> N;

    node *head = (node *)malloc(sizeof(node));
    Create_List(head);
    node *tail = (node *)malloc(sizeof(node));
    tail->data = 101;
    tail->next = NULL;
    head->next = tail;

    for (int i = 0; i < N; i++){
        int num;
        cin >> num;
        Search_List(head, num);
    }

    node *p = head->next;
    while(p->next){
        cout << p->data << ' ';
        node *temp = p;
        p = p->next;
        free(temp);
    }
    cout << endl;
    return 0;
}