#include <iostream>
#define MAXSIZE 200
using namespace std;

int Stack[MAXSIZE];
int top = 0;

void Push(int num){
    Stack[top++] = num;
}

void Pop(){
    if(top == 0){
        return;
    }
    Stack[--top] = 0;
}

void Travesal(){    
    if(top == 0){
        cout << 0 << endl;
        return;
    }
    int p = 0;
    int big = -1;
    while(p != top){
        if(Stack[p] > big){
            big = Stack[p];
        }
        p += 1;
    }

    cout << big << endl;
}

int main(){
    int N;
    cin >> N;
    int ope, hard;
    while (N--){
        cin >> ope;
        if(ope == 0){
            cin >> hard;
            Push(hard);
        }else if(ope == 1){
            Pop();
        }else{
            Travesal();
        }
    }
    return 0;
}