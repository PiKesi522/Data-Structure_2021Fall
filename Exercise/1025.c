#include <stdio.h>
#define MAX 101

typedef struct stack{
    int x, y, d;
} STACK;

typedef struct move{
    int a, b;
} MOVE;

int maze[MAX][MAX];
int mark[MAX][MAX];

MOVE mv[8];
STACK s[MAX * MAX];
int top;

int startM, startN, endM, endN, n;

void setmove(){
    mv[0].a = -1;    mv[0].b = 0;
    mv[1].a = -1;    mv[1].b = 1;
    mv[2].a = 0;     mv[2].b = 1;
    mv[3].a = 1;     mv[3].b = 1;
    mv[4].a = 1;     mv[4].b = 0;
    mv[5].a = 1;     mv[5].b = -1;
    mv[6].a = 0;     mv[6].b = -1;
    mv[7].a = -1;    mv[7].b = -1;
}

void inputmaze(){
    int i, j;
    for (i = 0; i <= n + 1; i++){
        for (j = 0; j <= n + 1; j++){
            maze[i][j] = 1;
        }
    }
    getchar();
    for (i = 1; i <= n; i++){
        for (j = 1; j <= n; j++){
            scanf("%d", &maze[i][j]);
        }
        getchar();
    }
}

void setmark(){
    for (int i = 0; i <= n + 1; i++){
        for (int j = 0; j <= n + 1; j++){
            mark[i][j] = 0;
        }
    }
}

void getmazepath(){
    int i, j, k, g, h;

    s[0].x = startM;
    s[0].y = startN;
    s[0].d = 1;
    top = 1;
    mark[startM][startN] = 1;

    while(top > 0){
        i = s[--top].x;
        j = s[top].y;
        k = s[top].d;
        while(k < 7){
            g = i + mv[++k].a;
            h = j + mv[k].b;
            if(g == endM && h == endN){
                printf("yes\n");
                return;
            }

            if(maze[g][h] == '0' && mark[g][h] == 0){
                mark[g][h] = 1;
                s[top].x = i;
                s[top].y = j;
                s[top++].d = k;
                i = g;
                j = h;
                k = -1;
            }
        }
    }

    printf("no\n");
    return;
}

int main(){
    scanf("%d", &n);
    scanf("%d %d %d %d", &startM, &startN, &endM, &endN);
    inputmaze();
    setmark();
    getmazepath();
    return 0;
}