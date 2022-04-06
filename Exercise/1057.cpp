#include <bits/stdc++.h>
using namespace std;

struct Info{
    char id[13];
    int All_Seq;
    int classroom;
    int Inclass_Seq;
    int score;
};  

Info Students[30000];

bool cmp(Info A, Info B){
    if(A.score != B.score){
        return A.score > B.score;
    }else{
        return (strcmp(A.id, B.id) < 0);
    }
}

void GiveSeq(int size, int Begin){
    int Seq = 1;
    Students[Begin].Inclass_Seq = Seq++;

    for (int now = Begin + 1, prev = Begin; now < size + Begin; now++ , prev++){
        if(Students[now].score == Students[prev].score){
            Students[now].Inclass_Seq = Students[prev].Inclass_Seq;
            Seq++;
        }else{
            Students[now].Inclass_Seq = Seq++;
        }
    }
}

void GiveSeq(int size){
    int Seq = 1;
    Students[0].All_Seq = Seq++;
    for (int now = 1, prev = 0; now < size; now++ , prev++){
        if(Students[now].score == Students[prev].score){
            Students[now].All_Seq = Students[prev].All_Seq;
            Seq++;
        }else{
            Students[now].All_Seq = Seq++;
        }
    }
}

int main(){

    int ClassRoomCnt, ClassStart = 0;
    cin >> ClassRoomCnt;
    for(int i = 0; i < ClassRoomCnt; i++){
        int ClassRoomPeopleCnt;
        cin >> ClassRoomPeopleCnt;

        for (int j = ClassStart; j < ClassRoomPeopleCnt + ClassStart; j++){
            Info temp;
            cin >> temp.id >> temp.score;
            temp.classroom = i + 1;
            Students[j] = temp;
        }

        sort(Students + ClassStart, Students + ClassRoomPeopleCnt + ClassStart, cmp);
        GiveSeq(ClassRoomPeopleCnt, ClassStart);
        ClassStart += ClassRoomPeopleCnt;
    }
    sort(Students, Students + ClassStart, cmp);
    GiveSeq(ClassStart);

    cout << ClassStart << endl;
    for (int i = 0; i < ClassStart; i++){
        cout << Students[i].id << ' ' << Students[i].All_Seq << ' ' << Students[i].classroom << ' ' << Students[i].Inclass_Seq << endl;
    }
}