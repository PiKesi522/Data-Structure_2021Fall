#include<stdio.h>
#include<stdlib.h>
#define EH 0            /*等高*/
#define LH 1            /*左高*/
#define RH -1            /*右高*/
    
typedef int ElemType;                 /*数据类型*/

typedef struct BiTree{
    ElemType data;                    /*数据元素*/
    int BF;                         /*平衡因子*/
    struct BiTree *lchild,*rchild;     /*左右子女指针*/
}*Bitree,BitreeNode;


int InsertAVL(Bitree *T,ElemType e,bool *taller);
void LeftBalance(Bitree *T);
void RightBalance(Bitree *T);
void R_Rotate(Bitree *T);
void L_Rotate(Bitree *T);
bool *taller=(bool*)malloc(sizeof(bool));

int CountLayer(BiTree *root){
    if(root->lchild == NULL && root->rchild == NULL){
        return 1;
    }

    if(root->lchild == NULL){
        return CountLayer(root->rchild) + 1;
    }else if(root->rchild == NULL){
        return CountLayer(root->lchild) + 1;
    }else{
        int left  = CountLayer(root->rchild);
        int right = CountLayer(root->lchild);
        return (left > right ? left : right) + 1;
    }

}

int main(void)
{
    int N, data;
    scanf("%d", &N);
    Bitree T = NULL;
    for(int i = 0 ; i < N; i++){
        scanf("%d", &data);
        InsertAVL(&T, data, taller);
    }
    printf("%d %d", CountLayer(T) + 1, T->data);
    return 0;
}


/*若在平衡的二叉排序树T 中不存在和e 有相同关键码的结点，则插入一个数据元素为e 的*/
/*新结点，并反回1，否则反回0。若因插入而使二叉排序树失去平衡，则作平衡旋转处理，*/        
/*布尔型变量taller 反映T 长高与否*/    
int InsertAVL(Bitree *T,ElemType e,bool *taller)
{
    if(!*T)                /*插入新结点，树“长高”，置taller 为TURE*/
    {
        (*T)=(Bitree)malloc(sizeof(BitreeNode));
        (*T)->data = e;
        (*T)->lchild = (*T)->rchild = NULL;
        (*T)->BF = EH;
        *taller = true;
    }
    else
    {
        if(e==(*T)->data)        /*树中存在和e 有相同关键码的结点，不插入*/
        {
            *taller = false;
            return 0;
        }    
        if(e<(*T)->data)
        {
            if(!InsertAVL(&(*T)->lchild,e,taller))    return 0;  /*未插入*/
            if(*taller)
            switch((*T)->BF)
            {    
                case EH :                    /*原本左、右子树等高，因左子树增高使树增高*/
                    (*T)->BF=LH;
                    *taller=true;
                    break;
                
                case LH :                    /*原本左子树高，需作左平衡处理*/
                    LeftBalance(T);
                    *taller=false;
                    break;
                
                case RH :                    /*原本右子树高，使左、右子树等高*/
                    (*T)->BF=EH; 
                    *taller=false;
                    break;
                    
            }
            
        }
        else
        {
            if(!InsertAVL(&(*T)->rchild,e,taller))    return 0;  /*未插入*/
            if(*taller)
            switch((*T)->BF)
            {    
                case EH :                    /*原本左、右子树等高，因右子树增高使树增高*/
                    (*T)->BF=RH;
                    *taller=true;
                    break;
                
                case LH :                    /*原本左子树高，使左、右子树等高*/
                    (*T)->BF=EH; 
                     *taller=false;
                     break;
                
                case RH :                    /*原本右子树高，需作右平衡处理*/
                    RightBalance(T);
                    *taller=false;
                     break;
                    
            }
        }
    }
    return 1;
}



/*对以*p 指向的结点为根的子树，作左平衡旋转处理，处理之后，*p 指向的结点为子树的新根*/
void LeftBalance(Bitree *T)
{
    Bitree L=(*T)->lchild,Lr;             /*L 指向*T左子树根结点*/
    switch(L->BF)                /*检查L 平衡度，并作相应处理*/
    {
        case LH:                    /*新结点插在*p 左子树的左子树上，需作单右旋转处理*/
            (*T)->BF=L->BF=EH;
             R_Rotate(T);
             break;
        case EH:             /*原本左、右子树等高，因左子树增高使树增高*/
            (*T)->BF=LH;    //这里的EH好像没有写的必要 
              *taller=true;
              break;
        case RH:                     /*新结点插在*T 左孩子的右子树上，需作先左后右双旋处理*/
            Lr=L->rchild;             /*Lr 指向*p 左孩子的右子树根结点*/    
            switch(Lr->BF)         /*修正*T 及其左子树的平衡因子*/
            {
                case LH:
                    (*T)->BF = RH;
                    L->BF = EH;
                    break;
                case EH:
                    (*T)->BF = L->BF= EH;
                    break;
                case RH:
                    (*T)->BF = EH;
                    L->BF = LH;
                    break;
                
            }
            Lr->BF = EH;
            L_Rotate(&L);        /*对*T 的左子树作左旋转处理*/
            R_Rotate(T);        /*对*T 作右旋转处理*/
    }
}
//这里和leftbalance一个道理，试着自己写一下 
void RightBalance(Bitree *T)
{
    Bitree Lr= (*T)->rchild,L;
    switch(Lr->BF)
    {
        case EH:
            *taller = true;
            (*T)->BF = RH;
            break;
        case RH:
            (*T)->BF=Lr->BF=EH;
            L_Rotate(T);
            break;
        case LH:
            L = Lr->lchild;
            switch(L->BF)
            {
                case EH:
                    (*T)->BF=Lr->BF= EH;
                    break;
                case RH:
                    Lr->BF= EH;
                    (*T)->BF = LH;
                    break;
                case LH:
                    (*T)->BF = LH;
                    Lr->BF = EH;
                    break;
                
            }
            L->BF = EH;
            R_Rotate(&Lr);        
            L_Rotate(T);    
        
    }
}


/*对以*T 指向的结点为根的子树，作右单旋转处理，处理之后，*T 指向的结点为子树的新根*/
void R_Rotate(Bitree *T)
{ 
    Bitree L=(*T)->lchild;                 /*L 指向*T 左子树根结点*/
    (*T)->lchild=L->rchild;                 /*L 的右子树挂接*T 的左子树*/
    L->rchild=*T; *T=L;             /* *L 指向新的根结点*/
}


/*对以*p 指向的结点为根的子树，作左单旋转处理，处理之后，*p 指向的结点为子树的新根*/
void L_Rotate(Bitree *T)
{ 
    Bitree Lr=(*T)->rchild;                 /*Lr 指向*T 右子树根结点*/
    (*T)->rchild=Lr->lchild;                 /*L 的左子树挂接*p 的右子树*/
    Lr->lchild=*T; 
    *T=Lr;                                     /* *L 指向新的根结点*/
}