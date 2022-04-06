// 树的双亲数组表示转化为树
// 树的后序遍历

#include <bits/stdc++.h>
using namespace std;
struct LNode{
    int parent;
    vector<int> children;
};

vector<LNode *> addr;

void posOrderTraversal(vector<LNode *> &addr, int root){
    for(int i = 0; i < addr[root]->children.size(); i++){
        posOrderTraversal(addr, addr[root]->children[i]);
    }
    cout << root << ' ';
}

void Trans(int n){
    for (int i = 0; i < n; i++){
        LNode *temp = new LNode;
        addr.push_back(temp);
    }

    int temp_parent, root;
    for (int i = 0; i < n; i++){
        cin >> temp_parent;
        addr[i]->parent = temp_parent;
        if(temp_parent != -1){
            addr[temp_parent]->children.push_back(i);
        }else{
            root = i;
        }
    }

    posOrderTraversal(addr, root);
    cout << endl;
    return;
}

int main(){
    int size;
    cin >> size;
    Trans(size);
    return 0;
}