#include <iostream>
#include <string>

using namespace std;

class Stack{
public:
    int elements[10000];
    int used_ele = 0;
    void push(int x){
        this->elements[this->used_ele++] = x;
    }
    void pop(){
        if(this->used_ele == 0){
            cout << "ERROR" << endl;
        }else{
            this->elements[this->used_ele--] = 0;
        }
    }
    void top(){
        if(this->used_ele == 0){
            cout << "ERROR" << endl;
        }else{
            cout << this->elements[this->used_ele - 1] << endl;
        }
    }
    void size(){
        cout << this->used_ele << endl;
    }
    void clear(){
        while(this->used_ele){
            this->elements[this->used_ele--] = 0;
        }
    }
    void empty(){
        if(this->used_ele == 0){
            cout << "YES" << endl;
        }else{
            cout << "NO" << endl;
        }
    }
};

int main(){
    int num;
    cin >> num;
    string moves;
    Stack s;
    while(num--){
        cin >> moves;
        if(moves == "pop"){
            s.pop();
        }else if(moves == "push"){
            int elem;
            cin >> elem;
            s.push(elem);
        }else if(moves == "top"){
            s.top();
        }else if(moves == "size"){
            s.size();
        }else if(moves == "clear"){
            s.clear();
        }else if(moves == "empty"){
            s.empty();
        }
    }
    return 0;
}