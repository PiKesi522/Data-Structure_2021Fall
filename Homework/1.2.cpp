#include <iostream>
// 倒置线性表

using namespace std;

#define List_size 7

int List[List_size] = {1, 2, 3, 4, 5, 6, 7};

bool reverse_Elem(int *head, int *tail, int *Space){
    if(head >= tail){
        return false;
    }

    *Space = *head;
    *head = *tail;
    *tail = *Space;

    return true;
}

int main(){
    int *Space = (int *)malloc(sizeof(int));

    int *head = &List[0];
    int *tail = &List[List_size - 1];

    while(true){
        if(!reverse_Elem(head, tail, Space)){
            break;
        }
        head = head + 1;
        tail = tail - 1;
    }
    free(Space);

    for(int v : List){
        cout << v << ' ';
    }
    cout << endl;
    return 0;
}