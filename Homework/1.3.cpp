#include <iostream>
#include <algorithm>
#define MAXSIZE 100
using namespace std;

bool cmp(int a, int b){
    return a < b;
}

int List[MAXSIZE];

int main(){
    int size = sizeof(List) / sizeof(int);
    sort(List, List + size, cmp);

    int pre = List[0];
    for(int i = 1; i < size; i++){
        if(pre == List[i]){
            for(int j = i; j < size - 1; j++){
                List[j] = List[j + 1];
            }
            size -= 1;
            continue;
        }

        pre = List[i];
    }
}