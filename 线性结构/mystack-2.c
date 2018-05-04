typedef struct SNode* PtrToSNode;
struct SNode{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S;
    S = malloc(sizeof(struct SNode));
    S->Next = NULL;
    return S;
}

bool IsEmpty(Stack S)
{
    return S->Next == NULL;
}

bool Push(Stack S,ElementType X)
{
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    return true;
}

ElementType Pop(Stack S)
{
    PtrToSNode FirstCell;
    ElementType TopElem;
    is(IsEmpty(S)){
        printf("stack is empty");
        return ERROR;
    }
    else{
        FirstCell = S->Next;
        TopElem = FirstCell->Data;
        S->Next = FirstCell->Next;
        free(FirstCell);
        return TopElem;
    }
}