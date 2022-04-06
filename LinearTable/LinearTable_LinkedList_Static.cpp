#include <iostream>
using namespace std;
#define MAXSIZE 1000

int main(){
    SLinkList L = L.InitSpace_SL();
    return 0;
}

class Mytype{
    public:
        string name;
        int age;
};
class component{
    public:
        Mytype data;
        // 存储内容
        int cur;
        // 存储游标，表示相对位置
};

class SLinkList{
public:
    component SArray[MAXSIZE];
    SLinkList InitSpace_SL(void);
    int Malloc_SL(SLinkList s);
    void Free_SL(SLinkList s, int k);
    int LocateElem(SLinkList s, Mytype mt);
    SLinkList difference(SLinkList s);
};
SLinkList SLinkList::InitSpace_SL(void){
    SLinkList s;
    for (int i = 0; i < MAXSIZE - 1; i++){
        s.SArray[i].cur = i + 1;
    }
    s.SArray[MAXSIZE - 1].cur = 0;
    return s;
}
int SLinkList::Malloc_SL(SLinkList s){
    // 返回备用链表的空余位置，若无则返回0
    int i = s.SArray[0].cur;
    if(s.SArray[0].cur){
        s.SArray[0].cur = s.SArray[i].cur;
        // 标准删除链表元素
    }
    return i;
}
void SLinkList::Free_SL(SLinkList s, int k){
    // 标准插入链表
    s.SArray[k].cur = s.SArray[0].cur;
    s.SArray[0].cur = k;
}
int SLinkList::LocateElem(SLinkList s,Mytype mt){
    int i = s.SArray[0].cur;
    while(i && s.SArray[i].data.name != mt.name){
        i = s.SArray[i].cur;
    }
    if(i == 0){
        cout << "Cannot find such Element!" << endl;
        return 0;
    }
    return i;
}
SLinkList SLinkList::difference(SLinkList s){
    SLinkList SL = SL.InitSpace_SL();
    int S = Malloc_SL(SL);
    int r = S;
    int m,n;
    cin >> m >> n;
    for(int j = 1; j <= m; j++){
        int i = Malloc_SL(s);
        Mytype tmt;
        cin >> tmt.name >> tmt.age;
        s.SArray[r].cur = i;
        r = i;
    }
    s.SArray[r].cur = 0;
    for (int j = 1; j <= n; j++){
        
    }
}