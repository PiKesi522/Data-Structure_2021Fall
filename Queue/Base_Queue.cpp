#include <iostream>

using namespace std;

class Queue{
    public:
        int element[1000];
        int use_elem = 0;
        void ClearQueue(){
            for (int i = 0; i < this->use_elem; i++){
                this->element[i] = 0;
            }
        }
        bool QueueEmpty(){
            return (this->use_elem == 0);
        }
        int QueueLength(){
            return this->use_elem;
        }
        int GetHead(){
            if(this->QueueEmpty()){
                cout << "ERROR" << endl;
                return 0;
            }else{
                cout << this->element[this->use_elem - 1] << endl;
            }
        }
        void EnQueue(int e){
            this->element[this->use_elem++] = e;
        }
        void DeQueue(){
            if(this->QueueEmpty()){
                cout << "ERROR" << endl;
            }else{
                this->element[--this->use_elem] = 0;
            }
        }
};