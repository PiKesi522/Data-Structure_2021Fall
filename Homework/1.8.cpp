#include <iostream>

using namespace std;

#define MAX_SIZE 100

int stack[MAX_SIZE];
int top_left  = 0;
int top_right = MAX_SIZE - 1;

void push(int elem, int which_one){

    if(top_left > top_right){
        cout << "FULL" << endl;
        return;
    }

    if(which_one == 1){
        stack[top_left++]  = elem;
    }else{
        stack[top_right--] = elem;
    }

}

void pop(int which_one){

    if(top_left > top_right){
        cout << "FULL" << endl;
        return;
    }

    if(which_one == 1){
        stack[--top_left] = 0;
    }else{
        stack[++top_right] = 0;
    }
}