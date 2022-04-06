#include <iostream>
// 将一个给定的线性链表逆转，不允许移动节点值，只能改变结点值
using namespace std;

struct Node{
    int data;
    Node *next;
};

Node *head, *tail;

int main(){
    Node *temp = (Node *)malloc(sizeof(Node));
    while(head < tail){
        *temp = *head;
        *head = *tail;
        *tail = *temp;
        head += sizeof(Node);
        tail -= sizeof(Node);
    }
    free(temp);
}