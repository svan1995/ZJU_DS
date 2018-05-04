#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct AVLNode* Position;
typedef Position AVLTree;
struct AVLNode
{
    ElementType Data;
    AVLTree Left;
    AVLTree Right;
    int Height;
};

int Max(int a,int b)
{
    return a>b? a:b;
}

int GetHeight(AVLTree BT)
{
    int HL,HR,MaxH;
    if(BT){
        HL = GetHeight(BT->Left);
        HR = GetHeight(BT->Right);
        MaxH = (HL>HR)? HL:HR;
        return (MaxH+1);
    }
    else
        return 0;
}


AVLTree SingleLeftRotation(AVLTree A)
{
    AVLTree B = A->Left;
    A->Left = B->Right;
    B->Right = A;
    A->Height = Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height = Max(GetHeight(B->Left),GetHeight(B->Right))+1;
    return B;
}

AVLTree SingleRightRotation(AVLTree A)
{
    AVLTree B = A->Right;
    A->Right = B->Left;
    B->Left = A;
    A->Height = Max(GetHeight(A->Left),GetHeight(A->Right))+1;
    B->Height = Max(GetHeight(B->Left),GetHeight(B->Right))+1;
    return B;
}

AVLTree DoubleLeftRightRotation(AVLTree A)
{
    A->Left = SingleRightRotation(A->Left);
    return SingleLeftRotation(A);
}

AVLTree DoubleRightLeftRotation(AVLTree A)
{
    A->Right = SingleLeftRotation(A->Right);
    return SingleRightRotation(A);
}


AVLTree Insert(AVLTree T,ElementType X)
{
    if(!T){
        T = (AVLTree)malloc(sizeof(struct AVLNode));
        T->Data = X;
        T->Height = 1;
        T->Left = T->Right = NULL;
    }
    else if(X < T->Data){
        T->Left = Insert(T->Left,X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==2){
            if(X < T->Left->Data)
                T = SingleLeftRotation(T);
            else
                T = DoubleLeftRightRotation(T);
        }
    }
    else if(X > T->Data){
        T->Right = Insert(T->Right,X);
        if(GetHeight(T->Left)-GetHeight(T->Right)==-2){
            if(X > T->Right->Data)
                T = SingleRightRotation(T);
            else
                T = DoubleRightLeftRotation(T);
        }
    }
    
    T->Height = Max(GetHeight(T->Left),GetHeight(T->Right))+1;
    return T;

}

int main(int argc, char const *argv[])
{
    int N,number;
    AVLTree T=NULL;
    scanf("%d",&N);
    for(int i = 0;i<N;i++ ){
        scanf("%d",&number);
        T = Insert(T,number);
    }    
    printf("%d", T->Data);
    return 0;
}

