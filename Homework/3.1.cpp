#include <iostream>
#define MAXSIZE 100
using namespace std;

int List[MAXSIZE] = {0};
int used = 0;

int Bina(int start, int end, int x){
    int mid = 0;
    while(start < end){
        mid = (start + end) / 2;
        if(List[mid] < x){
            start = mid + 1;
        }else{
            end = mid;
        }
    }
    return end;
}

int main(){
    int num;
    while (cin >> num){
        if(used == MAXSIZE - 1){
            cout << "Full" << endl;
            return 0;
        }

        if(used == 0 || List[used - 1] <= num){
            List[used++] = num;
        }else if(List[0] >= num){
            for (int i = used - 1; i >= 0; i--){
                List[i + 1] = List[i];
            }
            List[0] = num;
            used += 1;
        }else{
            int loc = Bina(0, used, num);
            for (int i = used - 1; i >= loc; i--){
                List[i + 1] = List[i];
            }
            List[loc] = num;
            used += 1;
        }

        for (int i = 0; i < used; i++){
            cout << List[i] << ' ';
        }
        cout << endl;
    }
    return 0;
}