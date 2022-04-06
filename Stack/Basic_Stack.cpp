#include<iostream>

using namespace std;

template<typename T>
class Stack{
public:
    Stack &InitStack(void){

    }
    void DestroyStack(void){

    }
    Stack &ClearStack(void){

    }
    bool StackEmpty(void){

    }
    size_t StackLength(void){

    }
    T &GetTop(void){

    }
    T &Push(T temp){

    }
    T &Pop(void){

    }
    void StackTraverse(bool visit(T)){

    }
priavte:
    bool visit(T temp){
        return true;
    };
    
    (T *)base = NULL;
    (T *)top = &base;
    const int STACKSIZE = 10;
};
