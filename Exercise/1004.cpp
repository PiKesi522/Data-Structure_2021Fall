#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
    Node(int num){
        this->data = num;
        this->next = NULL;
    }
};

void Create_Linked_List(Node *Head, int n){
    // 此节点为头节点，不会被改变和使用，因而增删改查的时候不需要考虑此节点是否会被改动
    Head->data = -1;
    Head->next = NULL;
    Node *p = Head;
    int temp;
    for (int i = 0; i < n;i++){
        cin >> temp;
        Node *pp = new Node(temp);
        p->next = pp;
        p = p->next;
    }
}

void addNode(Node *Head, int loc, int elem){
    // 插入元素到指定位置之后
    Node *p = Head;
    for(int i = 0; i < loc; i++){
        if(!(p->next)){
            cout << "ERROR" << endl;
            return;
        }
        p = p->next;
    }

    Node *nextNode = new Node(elem);
    Node *temp = p->next;
    p->next = nextNode;
    if(temp){
        nextNode->next = temp;
    }
}

void delNode(Node *Head, int loc){
    Node *p = Head;
    for(int i = 1; i < loc; i++){
        if(!(p->next)){
            cout << "-1" << endl;
            return;
        }
        p = p->next;
    }

    Node *temp = p->next;
    if(!temp){
        cout << "-1" << endl;
        return;
    }
    cout << temp->data << endl;
    p->next = temp->next;
    free(temp);
}

int main(){
    int n;
    cin >> n;
    Node *Head = (Node *)malloc(sizeof(Node));
    Create_Linked_List(Head,n);

    int q;
    cin >> q;

    int ope,loc,num;
    for(int i = 0; i < q; i++){
        cin >> ope;
        if(ope == 1){
            cin >> loc >> num;
            addNode(Head,loc,num);
        }else{
            cin >> loc;
            delNode(Head,loc);
        }
    }
}