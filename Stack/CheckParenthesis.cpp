#include <iostream>

using namespace std;

class Stack{
public:
    char elements[1000] = {'\0'};
    int used_ele = 0;
    void push(char x){
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
    char top(){
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

void CheckParenthesis(){
    char ch;
    Stack stack;
    while(cin >> ch){
        if(ch == '(' || ch == '['){
            stack.push(ch);
            continue;
        }else if(ch == ')'){
            if(stack.top() == '('){
                stack.pop();
            }else{
                cout << "No" << endl;
                return;
            }
        }else if(ch == ']'){
            if(stack.top() == '['){
                stack.pop();
            }else{
                cout << "No" << endl;
                return;
            }
        }
    }

    if(stack.empty()){
        cout << "YES" << endl;
    }else{
        cout << "No" << endl;
    }
}

int main(){
    CheckParenthesis();
    return 0;
}