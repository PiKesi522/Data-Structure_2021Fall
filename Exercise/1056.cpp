#include <iostream>
using namespace std;

struct Bituple{
    int Sign;
    int Cnt = 0;
};

int main(){
    Bituple List[51];
    for (int i = 0; i <= 50; i++){
        List[i].Sign = i;
    }

    int people, temp;
    cin >> people;
    for (int i = 0; i < people; i++){
        cin >> temp;
        List[temp].Cnt += 1;
    }

    for (int i = 0; i <= 50; i++){
        if (List[i].Cnt != 0){
            cout << List[i].Sign << ":" << List[i].Cnt << endl;
        }
    }

    return 0;
}