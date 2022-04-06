#include <iostream>
#define MAXSIZE 100004
using namespace std;

// int Board[MAXSIZE][MAXSIZE] = {0};

struct Node{
    int x;
    int y;
};


int main(){
    int n, cnt = 0;
    cin >> n;
    Node List[MAXSIZE];

    for (int i = 0; i < n; i++){
        Node temp;
        cin >> temp.x >> temp.y;
        List[i] = temp;
        for (int j = 0; j < i; j++){
            if(List[j].x == temp.x){
                // 水平检测
                cnt++;
            }else if(List[j].y == temp.y){
                // 垂直检测
                cnt++;
            }else if((List[j].x + List[j].y) == (temp.x + temp.y)){
                // 左斜线检测
                cnt++;
            }else if((List[j].x - List[j].y) == (temp.x - temp.y)){
                // 右斜线检测
                cnt++;
            }
        }
    }

    cout << cnt << endl;
    return 0;
}