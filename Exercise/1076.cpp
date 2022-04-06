#include <bits/stdc++.h>
using namespace std;

struct Unit{
    char Name[31];
    int Occur;
};

int DATA_COUNT, EXIST_COUNT = 0;

bool cmp(Unit A, Unit B){
    return (strcmp(A.Name, B.Name) < 0);
}

int StrFind(char *c, Unit *U){
    for (int i = 0; i < EXIST_COUNT; i++){
        if(strcmp(U[i].Name, c) == 0)
            return i;
    }
    return -1;
}

void shiftdown(Unit a[],int head, int tail){
    Unit t = a[head];
    int j;
    while((j = 2 * head + 1) < tail){
        if(j < tail - 1 && (strcmp(a[j].Name, a[j+1].Name) < 0))
            j++;
        if(strcmp(t.Name, a[j].Name) < 0){
            a[head].Occur = a[j].Occur;
            strcpy(a[head].Name, a[j].Name);
            head = j;
        }else
            break;
    }
    strcpy(a[head].Name, t.Name);
    a[head].Occur = t.Occur;
}

void heap_sort(Unit a[], int n){
    for (int i = (n - 2) / 2; i >= 0; i--)
        shiftdown(a, i, n);

    for (int i = n - 1; i > 0; i--){
        Unit t = a[0];

        strcpy(a[0].Name,a[i].Name);
        a[0].Occur = a[i].Occur;

        strcpy(a[i].Name, t.Name);
        a[i].Occur = t.Occur;

        shiftdown(a, 0, i);
    }
}

int main(){
    cin >> DATA_COUNT;
    Unit *CATEGORY = (Unit *)malloc(sizeof(Unit) * DATA_COUNT);
    int Loc;
    getchar();
    for (int i = 0; i < DATA_COUNT; i++){
        char ch, temp[31] = {'\0'};
        int k = 0;
        while((ch = getchar()) != '\n')
            temp[k++] = ch;

        Loc = StrFind(temp, CATEGORY);
        if(Loc == -1){
            strcpy(CATEGORY[EXIST_COUNT].Name, temp);
            CATEGORY[EXIST_COUNT++].Occur = 1;
        }else{
            CATEGORY[Loc].Occur += 1;
        }
    }

    heap_sort(CATEGORY, EXIST_COUNT);

    for (int i = 0; i < EXIST_COUNT; i++){
        double P = 100.0 * CATEGORY[i].Occur / DATA_COUNT;
        cout << CATEGORY[i].Name << ' ';
        printf("%.4lf%%\n", P);
    }
    return 0;
}