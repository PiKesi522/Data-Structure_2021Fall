#include <iostream>

using namespace std;

char s[1000];
char t[10];
int ssize = 20;
int tsize = 3;

void insert(char *s, char *t, int pos){
    for (int i = (ssize + tsize - 1); i > pos; i--){
        s[i] = s[i - tsize];
    }
    for (int i = 0; i < tsize - 1; i++){
        s[pos + i] = t[i];
    }
}