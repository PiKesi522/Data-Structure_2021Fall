#include <iostream>

using namespace std;

int main(){
    char A[80] = {'\0'}, B[80] = {'\0'};
    cin >> A >> B;
    for (int i = 0; i < 80; i++){
        if(A[i] != '\0')
            cout << A[i];
        if(B[i] != '\0')
            cout << B[i];
        
    }
    return 0;
}