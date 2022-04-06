#include <iostream>

using namespace std;

int DP[21] = {0, 2, 4, 7};

int main(){
    int n;
    cin >> n;

    for (int i = 4; i < 21; i++){
        DP[i] = 2 * DP[i - 1] - DP[i - 2] + DP[i - 3];
    }

    while (n != -1)
    {
        cout << DP[n] << endl;
        cin >> n;
    }

    return 0;
}