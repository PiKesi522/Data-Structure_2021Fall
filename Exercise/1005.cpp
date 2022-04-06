#include <iostream>
#include <vector>

using namespace std;

/*在两个线性表元素完全一致的情况下，哪个线性表元素更多哪个大
**在线性表中存在不一样的元素的情况下，那个元素哪个大，哪个线性表大
**写cmp
*/

int cmp(vector<int> A, vector<int> B){
    int t = (A.size() < B.size()) ? A.size() : B.size();
    for (int i = 0; i < t; i++){
        if(A.at(i) != B.at(i)){
            return (A.at(i) < B.at(i)) ? (-1) : 1;
        }
    }
    if(A.size() == B.size()){
        return 0;
    }else if(A.size() > B.size()){
        return 1;
    }else{
        return -1;
    }
}

int main(){
    vector<int> A, B;
    int m, n;
    cin >> m >> n;
    int num;
    for (int i = 0; i < m; i++){
        cin >> num;
        A.push_back(num);
    }
    for (int i = 0; i < n; i++){
        cin >> num;
        B.push_back(num);
    }
    cout << cmp(A, B) << endl;
}