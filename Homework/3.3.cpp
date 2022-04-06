#include <iostream>

using namespace std;

void Selection_Sort(int *List, int n){
    for (int i = 0; i < n - 1; i++){
        int small = i;
        for (int j = i + 1; j < n; j++){
            if(List[small] > List[j])
                small = j;
        }
        int temp = List[i];
        List[i] = List[small];
        List[small] = temp;

        cout << "i=" << i << ": ";
        for (int j = 0; j < n; j++){
            cout << List[j] << ' ';
        }
        cout << endl;
    }
}

int main(){
    int List[9] = {46, 22, 26, 68, 48, 42, 36, 84, 66};
    Selection_Sort(List, 9);
}