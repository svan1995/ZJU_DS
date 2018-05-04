typedef int Position;
typedef struct SNode* PtrToNode;
struct SNode{
    ElementType *Data;
    Position Top;
    int MaxSize;
}
typedef PtrToNode Stack;

Stack CreateStack(int MaxSize)
{
    Stack S = (Stack)malloc(sizeof(struct SNode));
    S->Data = (ElementType*)malloc(MaxSize*sizeof(ElementType));
    S->Top = -1;
    S->MaxSize = MaxSize;
    return S;
}

bool IsFull(Stack S)
{
    return (S->Top == S->MaxSize -1);
}

bool Push(Stack S,ElementType X)
{
    if(IsFull(S)){
        printf("stack is full");
        return false;
    }
    else{
        S-Data[++(S->Top)] = X;
        return true;
    }
}

bool IsEmpty(Stack S)
{
    return(S->Top == -1);
}

ElementType Pop(Stack S)
{
    if(IsEmpty(S)){
        printf("stack is empty");
        return ERROR;
    }
    else{
        return(S->Data[(S->Top)--]);
    }
}