#include <bits/stdc++.h>
using namespace std;

struct Node{
    string name;
    Node* next = NULL;
};

Node List[101];

int main(){
    int n;
    cin >> n;
    string name;
    int score;
    for (int i = 0; i < n; i++){
        cin >> name >> score;

        Node *temp = &List[score];
        while(temp->next != NULL){
            temp = temp->next;
        }

        Node *p = new Node;
        p->name = name;
        p->next = NULL;
        temp->next = p;
        score = 1;
    }

    for (int i = 100; i >= 0; i--){
        Node* temp = &List[i];
        if(temp->next == NULL){
            // cout << i << endl;
            continue;
        }
        temp = temp->next;
        while(temp != NULL){
            cout << temp->name << " " << i << endl;
            temp = temp->next;
        }
    }
    
    return 0;
}