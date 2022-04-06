#include <bits/stdc++.h>

using namespace std;

int SIZE = (int)pow(2,20);

void Deal(int Depth, int Seq){
    bool *Tree = (bool *)malloc(sizeof(bool)*SIZE);
    for (int i = 0; i < SIZE; i++){
        Tree[i] = false;
    }
    int Pre_Loc = 0;
    while(Seq--){
        Pre_Loc = 1;
        for(int i = 1; i < Depth; i++){
            // cout << Pre_Loc << " ";
            if(Tree[Pre_Loc]){
                Tree[Pre_Loc] = false;
                Pre_Loc = 2 * Pre_Loc + 1;
            }else{
                Tree[Pre_Loc] = true;
                Pre_Loc = 2 * Pre_Loc;
            }
        }
    }
    free(Tree);
    cout << Pre_Loc << endl;
}

int main()
{
    int n, D, I;
    cin >> n;

    for(int i = 0; i < n; i++){
        cin >> D >> I;
        Deal(D, I);
    }
    return 0;
}
