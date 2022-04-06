#include <iostream>

using namespace std;

class Stack{
public:
    int elements[1000] = {0};
    int used_ele = 0;
    void push(int x){
        this->elements[this->used_ele++] = x;
    }
    void pop(){
        if(this->used_ele == 0){
            cout << "ERROR" << endl;
        }else{
            this->used_ele -= 1;
            this->elements[this->used_ele] = 0;
        }
    }
    int top(){
        if(this->used_ele == 0){
            cout << "ERROR" << endl;
            return -1;
        }else{
            return this->elements[this->used_ele - 1];
        }
    }
    int size(){
        return this->used_ele;
    }
    void clear(){
        while(this->used_ele){
            this->elements[this->used_ele--] = 0;
        }
    }
    bool empty(){
        return (this->used_ele == 0);
    }
};

void Trans(){
    Stack stack;
    int Dec, base;
    cin >> Dec >> base;
    while(Dec){
        stack.push(Dec % base);
        Dec = Dec / base;
    }

    while(!stack.empty()){
        int top = stack.top();
        stack.pop();
        cout << top;
    }

}

int main(){
    Trans();
    return 0;
}