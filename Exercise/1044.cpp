#include <iostream>
#include <string>

using namespace std;

bool cmp(int D, char H[]){
    int H2D = (H[0] - '0') * 16 + (H[1] - '0');
    return (H2D == D);
}

void deal(char time[], char loc[], char face){
    
}

void solve(){
    string rawinfo;
    cin >> rawinfo;

    string prefix = rawinfo.substr(0, rawinfo.find(','));
    if(prefix != "$GPRMC")
        return;

    int checkNUM = 'G'^'P'^'R'^'M'^'C';
    for (int i = rawinfo.find(','); i < rawinfo.find('*'); i++)
        checkNUM = checkNUM ^ rawinfo[i];
    char GivenCheckNUM[2] = {rawinfo[rawinfo.size() - 2], rawinfo[rawinfo.size() - 1]};
    if(!cmp(checkNUM, GivenCheckNUM))
        return;

    char locTime[10] = {'\0'};
    char locEarth[10] = {'\0'};
    char Face;
    int commacnt = 0;
    while (true)
    {
        int comma = rawinfo.find(',');
        commacnt += 1;
        rawinfo = rawinfo.substr(comma+1);
        int nextcomma = rawinfo.find(',');
        if(nextcomma == rawinfo.npos){
            break;
        }
        if(commacnt == 1){
            for (int i = 0; i < nextcomma; i++){
                locTime[i] = rawinfo[i];
            }
        }else if(commacnt == 2){
            if(rawinfo[0] == 'T'){
                return;
            }
        }else if(commacnt == 5){
            for (int i = 0; i < nextcomma; i++){
                locEarth[i] = rawinfo[i];
            }
        }else if(commacnt == 6){
            Face = rawinfo[0];
            break;
        }
    }

    deal(locTime, locEarth, Face);
    return;
}

int main(){
    cout << ('G'^'P'^'R'^'M'^'C') << endl;
    return 0;
}