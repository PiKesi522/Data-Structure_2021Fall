#include <iostream>

using namespace std;

int List[10] = {0, 2, 3, 5, 7, 10, 15, 22, 35, 75};

void Bina(int start, int end, int target){
    int mid = (start + end) / 2;

    if(List[mid] > target){
        if(mid == 9){
            cout << "Not Found" << endl;
            return;
        }

        Bina(start, mid, target);
    }else if(List[mid] < target){
        if(mid == 0){
            cout << "Not Found" << endl;
            return;
        }

        Bina(mid, end, target);
    }else{
        cout << "Found in: " << mid << endl;
    }
}

int main(){
    int start = 0;
    int end = 10;
    Bina(start, end, 5);
}