#include <iostream>
#include <string>
#include <vector>
#define MAXSIZE 10000
#define STORE_STAGE 1
#define QUERY_STAGE 0

using namespace std;

struct Node{
    char account[12] = {'\0'};
    char money[12];
    Node *next;
};

Node List[MAXSIZE];

int Hash(char key[]){
    return (key[0] - 'a') * 100 + (key[1] - 'a');
}

Node *MakeNode(){
    Node *temp = (Node *)malloc(sizeof(Node));
    return temp;
}

bool CMP(char A[], char B[]){
    for (int i = 0; i < 12; i++){
        if(A[i] != B[i]){
            return false;
        }
    }
    return true;
}

void Store(char key[], char text[], int key_len, int text_len){
    int code = Hash(key);
    Node *p = &List[code];
    while(p->account[0] != '\0'){
        p = p->next;
    }

    for (int i = 0; i < key_len; i++){
        p->account[i] = key[i];
    }
    for (int i = 0; i < text_len; i++){
        p->money[i] = text[i];
    }
    p->next = (Node *)malloc(sizeof(Node));
}

void Find(char key[], int key_len){
    int code = Hash(key);
    if(List[code].account[0] == '\0'){
        cout << "eh" << endl;
        return;
    }

    Node *p = &List[code];
    while(p->account[0] != '\0'){
        if(CMP(p->account, key)){
            cout << p->money << endl;
            return;
        }
        p = p->next;
    }    
    cout << "eh" << endl;
    return;
}

int main(){
    string buffer;
    while(getline(cin, buffer)){
        char text[12] = {'\0'}, key[12] = {'\0'};
        if(buffer.length() == 0)
            break;

        int blank = buffer.find(' ');
        int text_len = blank, key_len = buffer.size() - blank - 1;
        for (int i = 0; i < text_len; i++)
            text[i] = buffer[i];
        for (int i = 0; i < key_len; i++)
            key[i] = buffer[blank + i + 1];
        //cout << text.size() << " " << key.size() << endl;
        Store(key, text, key_len, text_len);
    }
    while(cin >> buffer){
        char key[12] = {'\0'};
        for (int i = 0; i < buffer.size(); i++){
            key[i] = buffer[i];
        }
        Find(key, buffer.size());
    }
    return 0;
}