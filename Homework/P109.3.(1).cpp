#include <iostream>
#include <string>
using namespace std;

int Hash(char ch){
    return ch - 48;
}


int main(){
    char ch;
    int Freq[50] = {0};
    while((ch = getchar()) != '\n'){
        Freq[Hash(ch)] += 1;
    }
    for (int i = 0; i < 50; i++){
        if(Freq[i] != 0){
            cout << (char)(i + 48) << ":" << Freq[i] << endl;
        }
    }
}