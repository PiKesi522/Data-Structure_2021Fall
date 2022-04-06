#include <iostream>
#include <vector>

using namespace std;

int bina(vector<int> L, int min, int max, int v){
    if(min > max){
        return -1;
    }

    int loc = (min + max) / 2;
    if(L.at(loc) == v){
        return loc;
    }else if(L.at(loc) > v){
        return bina(L, min, loc, v);
    }else if(L.at(loc) < v){
        return bina(L, loc, max, v);
    }

    return -1;
}

int main(){
    int n,v;
    cin >> n;
    vector<int> L;
    for(int i = 0; i < n; i++){
        int num;
        cin >> num;
        L.push_back(num);
    }

    cin >> v;
    cout << bina(L, 0, n, v) << endl;
    return 0;
}