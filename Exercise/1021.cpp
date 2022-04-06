#include <iostream>
#define MAXSIZE 300
#define ULL unsigned long long
using namespace std;

int top = 0;

void Push(int num, ULL Stack[]){
    Stack[top] = num;
    cout << Stack[top] << endl;
    top += 1;
}

void Pop(ULL Stack[]){
    top -= 1;
    if(top == 0){
        cout << -1 << endl;
    }else{
        cout << Stack[top-1] << endl;
    }
}

void Reverse(ULL Stack[]){
    if(top == 0){
        cout << -1 << endl;
        return;
    }
    cout << Stack[0] << endl;
    ULL *left = Stack;
    ULL *right = &Stack[top - 1];
    ULL *temp = (ULL *)malloc(sizeof(ULL));
    while(left < right){
        *temp = *left;
        *left = *right;
        *right = *temp;
        left += 1;
        right -= 1;
    }
    free(temp);
}

int main(){
    int q;
    cin >> q;
    int ope;
    ULL num;
    ULL Stack[MAXSIZE];
    while(q--){
        cin >> ope;
        if(ope == 1){
            cin >> num;
            Stack[top] = num;
            cout << Stack[top] << endl;
            top += 1;
        }else if(ope == 2){
            top -= 1;
            if(top == 0){
                cout << -1 << endl;
            }else{
                cout << Stack[top-1] << endl;
            }
        }else{
            if(top == 0){
                cout << -1 << endl;
                return;
            }
            cout << Stack[0] << endl;
            ULL *left = Stack;
            ULL *right = &Stack[top - 1];
            ULL *temp = (ULL *)malloc(sizeof(ULL));
            while(left < right){
                *temp = *left;
                *left = *right;
                *right = *temp;
                left += 1;
                right -= 1;
            }
            free(temp);
        }
    }
    return 0;
}