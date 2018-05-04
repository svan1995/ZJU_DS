#include <stdio.h>
#include <stdlib.h>

typedef struct Node * PtrToNode;
typedef struct SNode* PtrToSNode;
typedef PtrToNode Tree;
typedef PtrToSNode Stack;

struct Node{
    int Data;
    PtrToNode Left;
    PtrToNode Right;
};

int flag = 0;

struct SNode{
    PtrToNode Data;
    PtrToSNode Next;
};

PtrToNode BuildTree();
void PostorderTraversal(PtrToNode T);

int main()
{
    PtrToNode T;
    T = BuildTree();

    // printf("%d\n", T->Left->Right->Data);
    PostorderTraversal(T);
    return 0;
}

Stack CreateStack()
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

void Push(Stack S,PtrToNode X)
{
    PtrToSNode Tmp;
    Tmp = (PtrToSNode)malloc(sizeof(struct SNode));
    Tmp->Data = X;
    Tmp->Next = S->Next;
    S->Next = Tmp;
}

PtrToNode Pop(Stack S)
{
    PtrToNode X;
    PtrToSNode FirstCell;
    FirstCell = S->Next;
    X = FirstCell->Data;
    S->Next = FirstCell->Next;
    free(FirstCell);
    return X;
}

int GetData(char* s)
{
    int x;
    if(s[6]==0)
        x = s[5]-'0';
    else
        x = (s[5]-'0')*10 + s[6]-'0';
    return x;
    
}

PtrToNode BuildTree()
{
    int flag,i,N;
    scanf("%d\n",&N);
    PtrToNode T,Q,Tmp;
    T = (PtrToNode)malloc(sizeof(struct Node));
    T->Left = T->Right = NULL;
    char str[10];
    flag = 0;
    Stack S = CreateStack();
    gets(str);
    T->Data = GetData(str);
    Q = T;
    Push(S,Q);
    for(i=1;i<2*N;i++){
        gets(str);
        if(str[1]=='u'){
            Tmp = (PtrToNode)malloc(sizeof(struct Node));
            Tmp->Data = GetData(str);
            Tmp->Left = Tmp->Right = NULL;
            if(flag == 0){
                Q->Left = Tmp;
                Q = Q->Left;
                Push(S,Q);
            }
            else{
                Q->Right = Tmp;
                Q = Q->Right;
                Push(S,Q);
                flag = 0;
            }

        }
        if(str[1]=='o'){
            Q = Pop(S);
            flag = 1;
        }        
    }
    return T;
}

void PostorderTraversal(PtrToNode T)
{
    
    if(T){
        PostorderTraversal(T->Left);
        PostorderTraversal(T->Right);
        if(flag){
            printf(" ");
        }
        printf("%d", T->Data);
        flag++; 
    }
}



