#include <iostream>

using namespace std;

class Mytype{
    public:
        string name;
        int age;
};

class ReNode{
    public:
        Mytype data;
        ReNode *next;
};

class RELinkList{
    ReNode *Head;
    RELinkList Init_RL(int size);
};
RELinkList RELinkList::Init_RL(int size){
    ReNode *RL = (ReNode *)malloc(sizeof(Mytype));
    RL->next = NULL;
    for (int i = 0; i < size; i++){
        ReNode *p = (ReNode *)malloc(sizeof(ReNode));
        Mytype nmt;
        cin >> nmt.name >> nmt.age;
        p->data = nmt;
        p->next = RL->next; // 插入到表头
        RL->next = p;
        if(i == 0){
            p->next = RL; // 末尾元素指向表头
        };
    }

}