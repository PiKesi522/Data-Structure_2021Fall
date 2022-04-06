#include <iostream>

using namespace std;

char stack[8] = {'I', 'O', 'I', 'I', 'O', 'I', 'O', 'O'};

int main(){
    int size = sizeof(stack) / sizeof(char);
    if(size & 1 == 1){
        cout << "NO" << endl;
        return 0;
    }
    int cnt_I = 0, cnt_O = 0;
    for (int i = 0; i < size; i++){
        if(stack[i] == 'I'){
            cnt_I += 1;
        }else{
            cnt_O += 1;
        }

        if(cnt_O > cnt_I){
            cout << "NO" << endl;
            return 0;
        }
    }
    if(cnt_I == cnt_O){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
    return 0;
}