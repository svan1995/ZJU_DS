#include <stdio.h>
#include <stdlib.h>


typedef struct TNode *Postion;
typedef Postion BinTree;

struct TNode
{
    int Data;
    BinTree Left;
    BinTree Right;
};


BinTree Insert(BinTree BST,int X)
{
    if(!BST){
        BST = (BinTree)malloc(sizeof(struct TNode));
        BST->Data = X;
        BST->Left = BST->Right = NULL;
    }
    else{
        if(X < BST->Data)
            BST->Left = Insert(BST->Left,X);
        else if(X > BST->Data)
            BST->Right = Insert(BST->Right,X);
    }
    return BST;
}

int IsEqual(BinTree T1,BinTree T2);
int main()
{
    int N,L,i,j;
    int flag,m;
    BinTree T[10][10];
    int k = 0;
    int B[10];
    do{
        scanf("%d",&N);
        if(N != 0){
            scanf("%d",&L);
            B[k] = L;
            for(i = 0;i<=L;i++)
                T[k][i] = NULL;
            for(i = 0;i<=L;i++){
                for(j = 0;j<N;j++){
                    scanf("%d",&m);
                    T[k][i] = Insert(T[k][i],m);
                }
            }
            k++;
        }
    }while(N != 0);

    for(j = 0;j<k;j++){
        for(i = 1;i<=B[j];i++){
            flag = IsEqual(T[j][0],T[j][i]);
            if(flag)
                printf("Yes\n");
            else
                printf("No\n");
        }
    }
}

int IsEqual(BinTree T1,BinTree T2)
{
    if(T1&&T2){
        if(T1->Data != T2->Data)
            return 0;
        else
            return IsEqual(T1->Left,T2->Left) && IsEqual(T1->Right,T2->Right); 
    }
    if((T1 && (!T2)) || ((!T1) && T2))
        return 0;
    else
        return 1;
}