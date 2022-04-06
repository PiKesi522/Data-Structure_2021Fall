#include<iostream>

using namespace std;

#define STACK_INIT_SIZE 100
#define STACK_INCREMENT 10

class Mytype{
public:
    string name;
    int age;
};

class T{
public:
    Mytype data;
};

class SqStack{
public:
    SqStack &InitStack(void){
        SqStack s;
        s.base = (T *)malloc((STACK_INIT_SIZE) * sizeof(T));
        if(!s.base){
            exit(OVERFLOW);
        }
        s.top = s.base;
        s.stacksize = STACK_INIT_SIZE;
        return s;
    }
    void DestroyStack(void){
        for (T *i = this->top; i != this->base; i -= sizeof(T)){
            free(i);
        }
        free(this->base);
    }
    void ClearStack(void){
        this->top = this->base;
    }
    bool StackEmpty(void){
        return (this->top == this->base);
    }
    int StackLength(void){
        return this->stacksize;
    }
    T &GetTop(void){
        if(this->top == this->base){
            cout << "ERROR" << endl;
            return *(this->base);
        }else{
            T e = *(this->top - sizeof(T));
            return e;
        }
    }
    void Push(T temp){
        if(this->top - this->base >= this->stacksize){
            this->base = (T *)realloc(this->base, (this->stacksize + STACK_INCREMENT) * sizeof(T));
            if(this->base){
                exit(OVERFLOW);
            }
            this->top = this->base + this->stacksize;
            this->stacksize += STACK_INCREMENT;
        }
        *this->top++ = temp;
    }
    T &Pop(void){
        if(this->StackEmpty()){
            return *this->base;
        }else{
            T e = *(--this->top);
            return e;
        }
    }
    void StackTraverse(bool visit(T)){
        
    }
private:
    bool visit(T temp){
        return true;
    };
    
    (T *)base;
    (T *)top;
    int stacksize;
};
