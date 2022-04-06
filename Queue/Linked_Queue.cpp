#include <iostream>

using namespace std;

struct Node{
    int data;
    Node *next;
};

class Queue{
    public:
        Node *Head;
        Node *Rear;
        Queue &InitQueue(){
            Queue q;
            q.Head = q.Rear = (Node *)malloc(sizeof(Node));
            q.Head->next = NULL;
            return q;
        }

        void DestroyQueue(){
            while(this->Head){
                this->Rear = this->Head->next;
                free(this->Head);
                this->Head = this->Rear;
            }
        }
    
        void ClearQueue(){
            this->Rear = this->Head;
            while(this->Rear->next != NULL){
                this->Rear->data = 0;
                this->Rear = this->Rear->next;
            }
        }
        bool QueueEmpty(){
            return (this->Head == this->Rear);
        }

        int QueueLength(){
            int cnt = 0;
            Node *temp = this->Head;
            while (temp != this->Rear){
                cnt++;
                temp = temp->next;
            }
            return cnt;
        }

        int GetHead(){
            if(this->QueueEmpty()){
                cout << "ERROR" << endl;
                return 0;
            }else{
                cout << this->Head->data << endl;
            }
        }
        void EnQueue(int e){
            Node *p = (Node *)malloc(sizeof(Node));
            p->data = e;
            p->next = NULL;
            this->Rear->next = p;
            this->Rear = p;
        }
        void DeQueue(){
            if(this->QueueEmpty()){
                cout << "ERROR" << endl;
            }else{
                Node *p = this->Head->next;
                free(this->Head);
                this->Head = p;
            }
        }
};