#include <iostream>

using namespace std;

int main(){
    return 0;
}

class Node{
    public:
        int data;
        Node *next;
};

class LinkedList{
    public:
        Node *L; // L为链表的头指针，并非是链表的内容
        int GetElem_L(int i);
        Node ListInsert_L(int i, int mt);
        Node ListDele_L(int i);
        Node CreatList_L(int i);
        Node MergeList_L(Node *LA, Node *LB);
};
int LinkedList::GetElem_L(int i){
    Node *p = this->L->next;
    int j = 1;
    while(p && j < i){
        p = p->next; // 直到p不再有后继指针
        j++;         // 或者找到该元素
    }
    if(!p || j > i){
        cout << "Cannot find such element!" << endl;
        int t;
        return t;
    }

    int e = p->data;
    return e;
}
Node LinkedList::ListInsert_L(int i, int mt){
    Node *p = this->L;
    int j = 0;
    while(p && j < i - 1){
        p = p->next;
        j++;
    }
    if(!p || j > i){
        cout << "Cannot find such element!" << endl;
        return *(this->L);
    }

    Node *s;
    s->data = mt;
    s->next = p->next;
    p->next = s;
    return *L;
}
Node LinkedList::ListDele_L(int i){
    Node *p = this->L;
    int j = 0;
    while(p->next && j < i - 1){
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i){
        cout << "Cannot find such element!" << endl;
        return *(this->L);
    }

    Node *q = p->next;
    p->next = q->next;
    free(q);
    return *(this->L);
}
Node LinkedList::CreatList_L(int size){
    Node *L = (Node *)malloc(sizeof(Node));
    L->next = NULL;
    for (int i = 0; i < size; i++){
        Node *p = (Node *)malloc(sizeof(Node));
        int nmt;
        cin >> nmt;
        p->data = nmt;
        p->next = L->next; // 插入到表头
        L->next = p;
    }
    return *L;
}
Node LinkedList::MergeList_L(Node *LA, Node *LB){
    Node *L = (Node *)malloc(sizeof(Node));
    Node *pa = LA->next;
    Node *pb = LB->next;
    Node *pc = LA;
    Node *LC = pc;
    while(pa && pb){
        if((*pa).data <= (*pb).data){
            pc->next = pa;
            pc = pa;
            pa = pa->next;
        }else{
            pc->next = pb;
            pc = pb;
            pb = pb->next;
        }
    }
    pc->next = pa ? pa : pb;
    free(LB);
    return *pc;
}
