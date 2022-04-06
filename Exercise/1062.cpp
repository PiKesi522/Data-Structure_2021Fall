#include <bits/stdc++.h>
using namespace std;

struct Loc{
    int x;
    int y;
};

int Table[5][5];

void Find(){
    vector<Loc> List;
    for (int i = 0; i < 5; i++){

        int big = -1;

        deque<Loc> T;

        for (int j = 0; j < 5; j++){
            
            cin >> Table[i][j];

            if(Table[i][j] > big){
                T.clear();

                Loc temp;
                temp.x = i;
                temp.y = j;
                T.push_back(temp);

                big = Table[i][j];
            }
            else if (Table[i][j] == big){

                Loc temp;
                temp.x = i;
                temp.y = j;
                T.push_back(temp);
                big = Table[i][j];
            }
        }

        while(!T.empty()){
            Loc temp = T[0];
            List.push_back(temp);
            T.pop_front();
        }
    }

    if(List.empty()){
        cout << "-1 -1" << endl;
        return;
    }

    bool flag = true;
    for(Loc v : List){
        for (int i = 0; i < 5; i++){
            if(Table[v.x][v.y] > Table[i][v.y])
                break;

            if(i == 4){
                flag = false;
                cout << v.x << ' ' << v.y << endl;
            }
        }
    }
    if(flag){
        cout << "-1 -1" << endl;
    }
} 

int main(){
    int T;
    cin >> T;
    for (int i = 0; i < T; i++){
        cout << "case #" << i << ":" << endl;
        Find();
    }
    return 0;
}