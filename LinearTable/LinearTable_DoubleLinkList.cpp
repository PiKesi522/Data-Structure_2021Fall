#include <iostream>
using namespace std;
class Mytype{
public:
    string name;
    int age;
};
class DuLNode{
    public:
        Mytype data;
        DuLNode *prior;
        DuLNode *next;
};
class DoubleLinkList{
    public:
        DuLNode *Head;
        // 线性链表的头节点
        DuLNode *Tail;
        // 线性链表的尾结点
        DuLNode *p;
        // 当前指向的位置
        DuLNode MakeNode(Mytype mt);
        // 分配由p指向值为e的结点
        void FreeNode(void);
        // 释放p所指的结点
        
        void InitList(int size);
        // 构造一个空的线性链表
        void DestroyList(void);
        // 销毁一个线性链表
        void ClearList(void);
        // 将线性链表重置为空链表
        void InsFirst(DuLNode s);
        // 将s所指向结点插入头结点之前
        DuLNode DelFirst(void);
        // 删除第一个结点,并将其返回
        DuLNode DelTail(void);
        // 删除最后一个结点,并将其返回
        void Append(DoubleLinkList L);
        // 将另一串结点连在此线性链表最后
        void InsBefore(DuLNode s);
        // 在p所指的结点前插入，并将p指向新结点
        void InsAfter(DuLNode s);
        // 在p所指的结点后插入，并将p指向新结点
        void SetCurElem(Mytype mt);
        // 在p所指的结点上，改变结点内容
        Mytype GetCurElem(void);
        // 在p所指的结点上，获取结点内容

        bool ListEmpty(void);
        // 链表是否为空

        DuLNode GetHead(void);
        // 获取头部结点
        DuLNode GetLast(void);
        // 获取尾部结点
        DuLNode PriorPos(void);
        // 获取当前结点的前趋结点
        DuLNode NextPos(void);
        // 获取当前结点的后继结点
        DuLNode LocatePos(int i);
        // 返回线性表中第i个结点
        DuLNode LocateElem(int i, Mytype mt, bool (*compare)(Mytype, Mytype));
        // 返回线性表中第i个与mt满足compare的结点
        void ListTraverse(bool (*visit)(Mytype));
        // 对线性表内所有元素采用visit()方法
};

DuLNode DoubleLinkList::MakeNode(Mytype mt){
    DuLNode *dl = (DuLNode *)malloc(sizeof(DuLNode));
    dl->data = mt;

    DuLNode *p = this->p;
    DuLNode *temp = this->Head;
    while(temp->next != NULL){
        temp = temp->next;
        if(temp == p){
            dl->prior = p->prior;
            dl->next = p->next;
            p->prior->next = dl;
            p->prior = dl;
            return;
        }
    }
    cout << "Cannot find such positon!" << endl;
}
void DoubleLinkList::FreeNode(void){
    if(this->p == this->Head){
        this->DelFirst();
    }else if(this->p == this->Tail){
        this->DelTail();
    }else{
        this->p->next->prior = this->p->prior;
        this->p->prior->next = this->p->next;
        this->p = NULL;
    }
}
void DoubleLinkList::InitList(int size){
    DuLNode *Head = (DuLNode *)malloc(sizeof(DuLNode));
    DuLNode *Tail = (DuLNode *)malloc(sizeof(DuLNode));
    Head->next = NULL;
    Head->prior = NULL;
    for (int i = 1; i < size; i++){
        DuLNode *p = (DuLNode *)malloc(sizeof(DuLNode));
        Mytype tmt;
        cin >> tmt.name >> tmt.age;
        p->data = tmt;

        p->prior = Head;        // 前趋指针
        p->next = Head->next;   // 后继指针
        Head->next->prior = p;  // 前趋元素重定向
        Head->next = p;         // 后继元素重定向
        if(i == 0){
            Tail = p;
        }
    }
    this->Head = Head;
    this->Tail = Tail;
}
void DoubleLinkList::DestroyList(void){
    DuLNode *temp;
    while(this->Head != NULL){
        temp = this->Head;
        this->Head = this->Head->next;
        free(temp);
    }
}
void DoubleLinkList::ClearList(void){
    DuLNode *temp;
    Mytype nullMT;
    nullMT.age = 0;
    nullMT.name = "NULL";
    while(this->Head != NULL){
        temp = this->Head;
        this->Head = this->Head->next;
        temp->data = nullMT;
    }
}
void DoubleLinkList::InsFirst(DuLNode s){
    s.prior = NULL;
    s.next = this->Head->next;
    this->Head->next = &s;
}
DuLNode DoubleLinkList::DelFirst(void){
    this->Head->next->prior = NULL;
    DuLNode *temp = this->Head;
    this->Head = this->Head->next;
    free(temp);
}
DuLNode DoubleLinkList::DelTail(void){
    this->Tail->prior->next = NULL;
    DuLNode *temp = this->Tail;
    this->Tail = this->Tail->prior;
    free(temp);
}
void DoubleLinkList::Append(DoubleLinkList L){
    this->Tail->next = L.Head;
}
void DoubleLinkList::InsBefore(DuLNode s){
    this->p->prior->next = &s;
    s.prior = this->p->prior;
    this->p->prior = &s;
    s.next = this->p;
    this->p = &s;
}
void DoubleLinkList::InsAfter(DuLNode s){
    this->p->next->prior = &s;
    s.next = this->p->next;
    this->p->next = &s;
    s.prior = this->p;
    this->p = &s;
}
void DoubleLinkList::SetCurElem(Mytype mt){
    this->p->data = mt;
}
Mytype DoubleLinkList::GetCurElem(void){
    return this->p->data;
}
bool DoubleLinkList::ListEmpty(void){
    return (this->Head == NULL);
}
DuLNode DoubleLinkList::GetHead(void){
    return *(this->Head);
}
DuLNode DoubleLinkList::GetLast(void){
    return *(this->Tail);
}
DuLNode DoubleLinkList::PriorPos(void){
    return *(this->p->prior);
}
DuLNode DoubleLinkList::NextPos(void){
    return *(this->p->next);
}
DuLNode DoubleLinkList::LocatePos(int i){
    DuLNode *temp = this->Head;
    while(i--){
        if(temp->next == NULL){
            cout << "OutReach!" << endl;
            return;
        }
        temp = temp->next;
    }
    return *temp;
}
bool compare(Mytype A, Mytype B){
    return ((A.age == B.age) && (A.name == B.name));
}
DuLNode DoubleLinkList::LocateElem(int i, Mytype mt, bool (*compare)(Mytype, Mytype)){
    DuLNode *temp = this->Head;
    while((temp->next != NULL) && (i != 0)){
        if(compare(mt, temp->data)){
            i -= 1;
        }
    }
    if(i == 0){
        return *temp;
    }else{
        cout << "OutReach" << endl;
        return *(this->Tail);
    }
}
bool visit(Mytype A){
    return (A.age >= 10);
}
void DoubleLinkList::ListTraverse(bool (*visit)(Mytype)){
    DuLNode *temp = this->Head;
    while(temp->next != NULL){
        if(!visit(temp->data)){
            cout << "Cannot Visit " << temp->data.name << endl;
            return;
        }
    }
    cout << "All Visit " << endl;
}
