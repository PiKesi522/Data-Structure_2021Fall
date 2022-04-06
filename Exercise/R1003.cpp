#include <iostream>
#include <string>

using namespace std;

class Node {
    public:
        int data;
        Node *next;
};

class LinkedQueue{
    public:
        Node *Head;
        Node *Rear = this->Head->next;
        int length = 0;
        void pop(){
            if(this->empty()){
                cout << "ERROR" << endl;
                return;
            }
            Node *temp;
            temp = Head->next;
            free(Head);
            this->Head = temp;
            this->length -= 1;
        }
        void push(int x){
            Node temp;
            temp.data = x;
            temp.next = NULL;
            this->Rear->next = &temp;
            this->Rear = this->Rear->next;
            this->length += 1;
        }
        int front(){
            if(this->empty()){
                cout << "ERROR" << endl;
                return 0;
            }else{
                return this->Head->data;
            }
        }
        int size(){
            return this->length;
        }
        void clear(){
            if(this->empty()){
                cout << "ERROR" << endl;
                return;
            }
            Node *temp;
            do{
                temp = this->Head->next;
                free(this->Head);
                this->Head = temp;
            }while(this->Head != this->Rear);
        }
        bool empty(){
            return (this->length == 0);
        }
        void copyTo(LinkedQueue a){
            a.clear();
            Node *temp = this->Head;
            do{
                a.push(temp->data);
                temp = temp->next;
            } while (temp != this->Rear);
        }
        void swap(LinkedQueue a){
            Node *temp = a.Head;
            a.Head = this->Head;
            this->Head = temp;
        }
};

int main(){
    LinkedQueue a, b;
    int Q;
    cin >> Q;
    string method;
    char vec;
    for (int i = 0; i < Q; i++){
        cin >> method;
        if(method == "pop"){
            cin >> vec;
            if(vec == 'a'){
                a.pop();
            }else{
                b.pop();
            }
        }else if(method == "push"){
            cin >> vec;
            int num;
            cin >> num;
            if(vec == 'a'){
                a.push(num);
            }else{
                b.push(num);
            }
        }else if(method == "front"){
            cin >> vec;
            if(vec == 'a'){
                cout << a.front() << endl;
            }else{
                cout << b.front() << endl;
            }
        }else if(method == "size"){
            cin >> vec;
            if(vec == 'a'){
                cout << a.size() << endl;
            }else{
                cout << b.size() << endl;
            }
        }else if(method == "clear"){
            cin >> vec;
            if(vec == 'a'){
                a.clear();
            }else{
                b.clear();
            }
        }else if(method == "empty"){
            cin >> vec;
            if(vec == 'a'){
                cout << a.empty() << endl;
            }else{
                cout << b.empty() << endl;
            }
        }else if(method == "swap"){
            a.swap(b);
        }
    }
}