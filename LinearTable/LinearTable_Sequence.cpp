#include <iostream>
#include <String>
#define LIST_INIT_SIZE 100
#define LIST_INCREASMENT 10
using namespace std;
class Mytype{
    public:
        string name;
        int age;
};

class LinearTable{
    public:
        Mytype *elem;       // 动态分配内存
        Mytype ELEM[1000];  // 静态分配内存
        int length;
        int listsize;
        LinearTable Init_Sq(void);
        LinearTable ListInsert_Sq(LinearTable L, int i, Mytype mt);
        LinearTable ListDele_Sq(LinearTable L, int i, Mytype mt);
        int LocateElem_Sq(LinearTable L, Mytype mt, bool(* compare)(Mytype, Mytype));
        LinearTable MergeList_Sq(LinearTable LA, LinearTable LB);
};

LinearTable LinearTable::Init_Sq(void){
    LinearTable L;
    L.elem = (Mytype *)malloc(LIST_INIT_SIZE * sizeof(Mytype));
    // malloc返回void*类型的指针，所以需要(Mytype*)进行强制转换
    if(!L.elem){
        exit(OVERFLOW);
    }
    L.length = 0;
    L.listsize = LIST_INIT_SIZE;
    return L;
}

LinearTable LinearTable::ListInsert_Sq(LinearTable L, int i, Mytype mt){
    if(i < 0 || i > L.length){ // 判断是否访问越界
        cout << "OverReach" << endl;
        return L;
    }
    if(L.length >= L.listsize){ // 判断是否超过预留内存
        Mytype *newbase = (Mytype *)realloc(L.elem, (L.listsize + LIST_INCREASMENT) * sizeof(Mytype));
        if(!newbase){
            exit(OVERFLOW);
        }
        L.elem = newbase;
        L.listsize += LIST_INCREASMENT;
    }

    Mytype *q = &(L.elem[i - 1]); // 插入操作
    for (Mytype *p = &(L.elem[L.length - 1]); p >= q; --p){
        *(p + 1) = *p;
    }
    *q = mt;
    L.length += 1;
}

LinearTable LinearTable::ListDele_Sq(LinearTable L, int i, Mytype mt){
    if(i < 0 || i > L.length){ // 判断是否访问越界
        cout << "OverReach" << endl;
        return L;
    }
    Mytype *p = &(L.elem[i - 1]);           // 被删除元素地址
    Mytype *q = &(L.elem[L.length - 1]);    // 末端元素地址
    for (++p; p <= q; ++p){
        *(p - 1) = *p;
    }
    L.length--;
    return L;
}

bool compare(Mytype A, Mytype B){
    if(A.name == B.name){
        if(A.age == B.age){
            return true;
        }
    }
    return false;
}
int LinearTable::LocateElem_Sq(LinearTable L, Mytype mt, bool(* compare)(Mytype, Mytype)){
    int i = 1;
    Mytype *p = L.elem; // L的首元素存储位置
    while(i <= L.length && !compare(*p++, mt)){
        i++;
    }
    if(i <= L.length){
        return i;
    }else{
        return -1;
    }
}

LinearTable LinearTable::MergeList_Sq(LinearTable LA, LinearTable LB){
    LinearTable LC = LC.Init_Sq();
    LC.listsize = LC.length = LA.length + LB.length;
    Mytype *pc = LC.elem = (Mytype *)malloc(LC.listsize * sizeof(Mytype));
    if(!LC.elem){
        exit(OVERFLOW);
    }
    
    Mytype *pa = LA.elem;
    Mytype *pb = LB.elem;
    Mytype *pa_last = &(LA.elem[LA.length - 1]);
    Mytype *pb_last = &(LB.elem[LB.length - 1]);
    while(pa <= pa_last && pb <= pb_last){
        if((*pa).age <= (*pb).age){
            *pc++ = *pa++;
        }else{
            *pc++ = *pb++;
        }
    }    
    while(pa <= pa_last){
        *pc++ = *pa++;
    }
    while(pb <= pb_last){
        *pc++ = *pb_last;
    }
}