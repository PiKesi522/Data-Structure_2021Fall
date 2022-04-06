#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define M 100
#define N 100
//********** Specification of SortLines **********
void SortLines(int (*p)[M], int n, int m)
/* PreCondition:
p points to a two-dimensional array with n lines and
m integers in each line
PostCondition:
array is sorted satisfying to the specification
*/
{
    int List[N] = {0};
    for (int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            List[i] += p[i][j];
        }
    }

    for (int i = 0; i < n - 1; i++){

        int small = i;

        for (int j = i + 1; j < n; j++){
            if(List[small] > List[j]){
                small = j;
            }else if(List[small] == List[j]){

                for (int k = 0; k < m; k++){
                    if(p[small][k] < p[j][k]){
                        break;
                    }else if(p[small][k] > p[j][k]){
                        small = j;
                        break;
                    }
                }

            }
        }

        int temp;
        
        for (int j = 0; j < m; j++){
            temp = p[small][j];
            p[small][j] = p[i][j];
            p[i][j] = temp;
        }

        temp = List[i];
        List[i] = List[small];
        List[small] = temp;
    }
}
/***************************************************************/
int main()
{
    int a[N][M];
    int n,m,i,j;
    int t,cas;
    scanf("%d",&cas);
    for(t=0; t<cas; t++)
    {
        memset(a,0,sizeof(a));
        scanf("%d%d",&n,&m);
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                scanf("%d",&a[i][j]);
        /***** function SortLines is called here *****/
        SortLines(a,n,m);
        /****************************************/
        printf("case #%d:\n",t);
        for (i=0; i<n; i++)
            for (j=0; j<m; j++)
                printf("%d%c",a[i][j],j<m-1?' ':'\n');
    }
    return 0;
}
