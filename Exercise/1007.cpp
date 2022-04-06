#include <iostream>
#include <string>

using namespace std;

typedef struct Node{
    string elem;
    struct Node* next;
    struct Node* pre;
    Node(Node *head,string data){
        this->elem = data;
        this->next = head->next;
        this->pre = NULL;
    }
    
    Node(){
        this->elem = "";
        this->next = this;
        this->pre = this;
    }
};

Node* createLinkedlist(Node* head){
    Node* p = head;
    while(1){
        string tmp;
        cin>>tmp;
        if(!tmp.compare("-1"))
            return head;
        Node* pp = new Node(head, tmp);
        p->next = pp;
        pp->pre = p;
        head->next->pre = pp;
        p = p->next;
    }
    return head;
}

Node* deleteNode(Node* head, string s){
    Node* p = head->next;
    Node* pp = p;
    int flag = 0;
    int state;
    do{
        state = 0;
        if(!pp->elem.compare(s)){
            Node* tmp = pp;
            pp = pp->next;
            tmp->next->pre = tmp->pre;
            tmp->pre->next = tmp->next;
            free(tmp);
            if(head->next == tmp){
                head->next = pp;
                p = pp;
                state = 1;
            }
            flag = 1;
        }
        else
            pp = pp->next;
    }while(pp != p || state);

    if(!flag)
        cout<<-1<<endl;

    return head;
}

void myPrint(Node* head){
    Node* p = head->next;
    cout<<p->elem<<" ";
    Node* pp = p->next;
    while(pp != p){
        cout<<pp->elem<<" ";
        pp = pp->next;
    }
    cout<<endl;
}

int main(){
    Node* head = new Node();
    head = createLinkedlist(head);
    while(1){
        string tmp;
        cin>>tmp;
        if(!tmp.compare("-1"))
            break;
        head = deleteNode(head, tmp);
    }
    myPrint(head);
    return 0;
}