#include <iostream>
#include <string>

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

void question(){
    int num;
    cin >> num;
    Stack stack;

    int Out[1000] = {0};

    for (int i = 0; i < num; i++){
        cin >> Out[i];
    }

    int TrainNo = 0;
    for (int In = 1; In <= num; In++){
        if(In != Out[TrainNo]){ // 不是尾部车辆
            while(!stack.empty() && stack.top() == Out[TrainNo]){ // 站内是否有尾部,多次比较
                stack.pop();
                TrainNo += 1;
            }
            stack.push(In);
        }else{
            TrainNo += 1;
        }
    }

    while (!stack.empty()){ // 清空栈
        if (stack.top() == Out[TrainNo]){
            stack.pop();
            TrainNo += 1;
        }else{
            break;
        }
    }

    if(TrainNo == num){
        cout << "YES" << endl;
    }else{
        cout << "NO" << endl;
    }
}

int main(){
    int num;
    cin >> num;
    while(num--){
        question();
    }
    return 0;
}