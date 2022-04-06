#include <iostream>

using namespace std;

void Solve(){
    string Sentence, Target;
    cin >> Sentence >> Target;
    int Sentence_length = Sentence.size();
    int Target_length = Target.size();
    for (int i = 0; i < Sentence_length; i++){
        if(Sentence[i] == Target[0]){
            int temp = i;
            bool flag = true;
            for (int j = 0; j < Target_length;){
                if(temp == Sentence_length){
                    flag = false;
                    break;
                }

                if(Sentence[temp++] != Target[j++]){
                    flag = false;
                    break;
                }
            }

            if(flag){
                for (int j = 0; j < Target_length; j++){
                    Sentence[i + j] = '\0';
                }
            }
        }
    }
    for (int i = 0; i < Sentence_length; i++){
        if(Sentence[i] != '\0'){
            cout << Sentence[i];
        }
    }
    cout << endl;
}

int main(){
    int q;
    cin >> q;
    getchar();
    for (int i = 0; i < q; i++){
        cout << "case #" << i << ":" << endl;
        Solve();
    }
    return 0;
}