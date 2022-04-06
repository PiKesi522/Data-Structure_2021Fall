#include <iostream>
using namespace std;

int CNT_Compare = 0, CNT_Exchange = 0, CNT_BubbleTime = 0;

void Bubble_Sort_Opitimize(int a[], int n){
    int temp;
    bool orgnized = false;
    int Last;
    int NextEnd = n - 1;
    for (int i = 0; i < n - 1; i++){
        orgnized = true;
        Last = NextEnd;

        for (int j = 0; j < Last ; j++){
            CNT_Compare += 1;

            if (a[j] > a[j + 1]){
                CNT_Exchange += 1;

                temp = a[j + 1];
                a[j + 1] = a[j];
                a[j] = temp;

                NextEnd = j;
                orgnized = false;
            }
        }
        
        CNT_BubbleTime += 1;

        if(orgnized){
            return;
        }
    }
}

int main(){
    int N;
    cin >> N;
    int List[5001];
    for (int i = 0; i < N; i++){
        cin >> List[i];
    }

    Bubble_Sort_Opitimize(List, N);
    cout << CNT_Compare << " " << CNT_Exchange << " " << CNT_BubbleTime << endl;
    return 0;
}