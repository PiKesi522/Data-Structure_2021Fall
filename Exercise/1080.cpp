#include <bits/stdc++.h>
#define MAXN 1000
#define inf 0x7fffffff
using namespace std;
typedef struct huffnode {
    char data; // 值
    struct huffnode * leftChild; // 左子树
    struct huffnode * rightChild; // 右子树
    /* 其他成员变量，细节隐藏不表 */
} HUFFNODE;

HUFFNODE *head;
char *cipher;

void decipherHuffmanCoding(HUFFNODE * head, char cipher[]){
    if(cipher[0] != '0' && cipher[0] != '1'){
        cout << endl;
        return;
    }
    
    huffnode *temp = head;
    int cnt = 0;
    while(temp->data == '*'){
        if(cipher[cnt++] == '0')
            temp = temp->leftChild;
        else
            temp = temp->rightChild; 
    }
    cout << temp->data;
    decipherHuffmanCoding(head, cipher + cnt * sizeof(char));
}

int main(){
    decipherHuffmanCoding(head, cipher);
    return 0;
}