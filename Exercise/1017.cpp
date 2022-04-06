#include <iostream>

using namespace std;

int Place[105][105] = {0};
int seat = 1;

struct School{
    int Seq;
    int Team;
};

int main(){
    int size;
    int nextStart = 0;
    cin >> size;
    // 还有一种情况，一共只有一支队伍参加
    int last = size;
    if(size == 1){
        int num;
        cin >> num;
        cout << "#1" << endl;
        for (int i = 0; i < num; i++){
            for (int j = 0; j < 9; j++){
                cout << seat << " ";
                seat += 2;
            }
            cout << seat << endl;
            seat += 2;
        }
        return 0;
    }
    
    School Q[100] = {0};    
    for (int i = 0; i < size; i++){
        Q[i].Seq = i;
        cin >> Q[i].Team;
    }

    while(size != 0){
        if(size == 1){
            if(Place[Q[0].Seq][nextStart - 1] == (seat - 1)){
                // 如果最后剩下的一组是之前的最后一组，那么需要额外空出一个座位
                seat += 1;
            }

            for (int i = 0; i < Q[0].Team; i++){
                for (int j = nextStart; j < nextStart + 10; j++){
                    Place[Q[0].Seq][j] = seat;
                    seat += 2;
                }
                nextStart += 10;
            }

            break;
        }

        for (int k = nextStart; k < nextStart + 10; k++){ // 为所有队伍分配座位
            for (int j = 0; j < size; j++){
                Place[Q[j].Seq][k] = seat++;
            }
        }

        nextStart += 10; // 所有学校的同一队的人已经入座，十个座位全部坐完， 后移动十个位子

        for (int i = 0; i < size; i++){ // 所有队伍减一
            Q[i].Team -= 1;
            if(Q[i].Team == 0){
                for (int j = i; j < size - 1; j++){
                    Q[j].Seq = Q[j + 1].Seq;
                    Q[j].Team = Q[j + 1].Team;
                }
                size -= 1;
                i -= 1;
                // 位置已经更新，重新回到第i位进行计算
            }
        }

    }

    for (int i = 0; i < last; i++){
        if(Place[i] == 0){
            return 0;
        }else{
            cout << "#" << i + 1 << endl;
        }

        for (int j = 0; j < 105; j += 10){
            if(Place[i][j] == 0){
                break;
            }else{
                int k = j;
                for (k = j; k < j + 9; k++){
                    cout << Place[i][k] << " ";
                }
                cout << Place[i][k] << endl;
            }
        }
    }

    return 0;
}