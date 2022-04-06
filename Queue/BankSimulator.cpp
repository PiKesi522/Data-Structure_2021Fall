#include <iostream>

using namespace std;

typedef struct Event{
    int OccurTime;
    int Ntype;
} ElemType;

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
        LinkedList CreatList_L(int i);
        LinkedList MergeList_L(Node *LA, Node *LB);
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
LinkedList LinkedList::CreatList_L(int size){
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
    LinkedList ll;
    ll.L = L;
    return ll;
}
LinkedList LinkedList::MergeList_L(Node *LA, Node *LB){
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
    LinkedList lc;
    lc.L = pc;
    return lc;
}


class Queue{
    public:
        Node *Head;
        Node *Rear;
        Queue &InitQueue(){
            Queue q;
            q.Head = q.Rear = (Node *)malloc(sizeof(Node));
            q.Head->next = NULL;
            return q;
        }
        void DestroyQueue(){
            while(this->Head){
                this->Rear = this->Head->next;
                free(this->Head);
                this->Head = this->Rear;
            }
        }  
        void ClearQueue(){
            this->Rear = this->Head;
            while(this->Rear->next != NULL){
                this->Rear->data = 0;
                this->Rear = this->Rear->next;
            }
        }
        bool QueueEmpty(){
            return (this->Head == this->Rear);
        }
        int QueueLength(){
            int cnt = 0;
            Node *temp = this->Head;
            while (temp != this->Rear){
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }
        int GetHead(){
            if(this->QueueEmpty()){
                cout << "ERROR" << endl;
                return 0;
            }else{
                cout << this->Head->data << endl;
            }
        }
        void EnQueue(int e){
            Node *p = (Node *)malloc(sizeof(Node));
            p->data = e;
            p->next = NULL;
            this->Rear->next = p;
            this->Rear = p;
        }
        void DeQueue(){
            if(this->QueueEmpty()){
                cout << "ERROR" << endl;
            }else{
                Node *p = this->Head->next;
                free(this->Head);
                this->Head = p;
            }
        }
};

typedef LinkedList EventList;
typedef Queue LinkQueue;

struct QElemType{
    int ArrvialTime;
    int DurationTime;
};

EventList   ev;
Event       en;
LinkQueue   q[5];
QElemType   customer;
int TotalTime, CustomerNum;

int cmp(Event a, Event b){
    if(a.OccurTime < b.OccurTime){
        return -1;
    }else if(a.OccurTime > b.OccurTime){
        return 0;
    }else{
        return 1;
    }
}

void OpenForDay(){
    TotalTime = 0;
    CustomerNum = 0;
    EventList ev = ev.CreatList_L(10);
}

int main(){
    OpenForDay();
    while(Movement){
        EventDrived(OccurTime, EventTime);
        switch(EventType){
            case 'A':
                CustomerArrived();
                break;
            case 'D':
                CustomerDeparture();
                break;
            default:
                break;
        }//switch
    }//while
    CloseForDay();
}// main