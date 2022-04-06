#include <bits/stdc++.h>
using namespace std;

void shiftdown(int a[],int head, int tail){
    int t = a[head], j;
    while((j = 2 * head + 1) < tail){
        if(j < tail - 1 && a[j] < a[j + 1])
            j++;
        if(t < a[j]){
            a[head] = a[j];
            head = j;
        }else
            break;
    }
    a[head] = t;
}

void heap_sort(int a[], int n, int times){
    for (int i = (n - 2) / 2; i >= 0; i--)
        shiftdown(a, i, n);

    for (int i = n - 1; i > n - 1 - times; i--){
        int t = a[0];
        a[0] = a[i];
        a[i] = t;
        cout << a[i] << ' ';
        shiftdown(a, 0, i);
    }
    cout << endl;
}

int main(){
    int N, M;
    cin >> N >> M;
    int *List = (int *)malloc(sizeof(int) * N);
    for (int i = 0; i < N; i++){
        cin >> List[i];
    }
    if(M >= N)  M = N;
    heap_sort(List, N, M);
    return 0;
}