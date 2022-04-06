#include <iostream>
#define MAXSIZE 101 // 额外的一个空间用来分别队列空还是满 
using namespace std;

// 要求是顺序存储，所以我们使用数组
// 为了防止假满，使用循环队列

int head = 0, tail = 0;
int q[MAXSIZE];

void Enqueue(int elem){
    tail = (tail + 1) % MAXSIZE;
    // 通过取余来使得tail不会超过MAXSIZE并且可以正确移位
    
    if(tail == head){
        // tail后移与head相遇，只能是队满
        if(tail == 0){
            tail = MAXSIZE - 1;
        }else{
            tail -= 1;
        }
        cout << "Full" << endl;
        // 此条语句使得tail回到之前状态，不再进行进队
        return;
    }

    q[tail] = elem;
    return;
}

void Dequeue(){
    if(head == tail){
        cout << "Empty" << endl;
        // head在移动前就与tail相遇，只能是队空
        return;
    }

    head = (head + 1) % MAXSIZE;
    cout << q[head] << endl;
    return;
}

int main(){

}