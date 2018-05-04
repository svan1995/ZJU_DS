#include <stdio.h>
#include <stdlib.h>


struct SNode{
    int *Data;
    int Top;
    int MaxSize;
};
typedef struct SNode* Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (int*)malloc(MaxSize*sizeof(int));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

int IsFull(Stack S)
{
    return (S->Top == S->MaxSize -1);
}

int Push(Stack S,int X)
{
    if(IsFull(S)){
        // printf("stack is full");
        return 0;
    }
    else{
        S->Data[++(S->Top)] = X;
        return 1;
    }
}

int IsEmpty(Stack S)
{
    return(S->Top == -1);
}

int Pop(Stack S)
{
    if(IsEmpty(S)){
        // printf("stack is empty");
        return 0;
    }
    else{
        return(S->Data[(S->Top)--]);
    }
}

void CheckPop(int m,int n,int *a)
{
    // int a[n];
    int i = 0;
    int j = 1;
    int flag = 0;
    // for(;i<n;i++){
    //     scanf("%d",&a[i]);
    // }
    Stack S;
    S = CreateStack(m);
    Push(S,j++);
    i = 0;
    while(i<n){
        if(S->Top == -1)
            Push(S,j++);
        else{
            if( S->Data[S->Top] < a[i]){
                if(Push(S,j++) == 0){
                    flag = 1;
                    break;
                }
            }
            else if(S->Data[S->Top] == a[i]){
                Pop(S);
                i++;
            }
            else{
                flag = 1;
                break;
            }
        }
    }
    if(flag)
        printf("NO\n");
    else
        printf("YES\n");
}


int main(int argc, char const *argv[])
{
    int M,N,K;
    

    scanf("%d %d %d",&M,&N,&K);
    int a[K][N];
    for(int i = 0;i<K;i++){
        for(int j = 0;j<N;j++){
            scanf("%d",&a[i][j]);
        }
    }
    for(int i = 0;i<K;i++){
        CheckPop(M,N,a[i]);
    } 
    
}