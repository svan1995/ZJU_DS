typedef struct TNode *Postion;
typedef Postion BinTree;

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


void InorderTraversal(BinTree BT)
{
    if(BT){
        InorderTraversal(BT->Left);
        printf("%d", BT->Data);
        InorderTraversal(BT->Right);
    }
}

void PreorderTraversal(BinTree BT)
{
    if(BT){
        printf("%d", BT->Data);
        PreorderTraversal(BT->Left);
        PreorderTraversal(BT->Right);
    }
}

void PostorderTraversal(BinTree BT)
{
    if(BT){
        PostorderTraversal(BT->Left);
        PostorderTraversal(BT->Right);
        printf("%d", BT->Data);
    }
}

void PreorderPrintLeaves(BinTree BT)
{
    if(!BT->Left&&!BT->Right){
        printf("%d", BT->Data);
    }
    PreorderPrintLeaves(BT->Left);
    PreorderPrintLeaves(BT->Right);
}

int GetHeight(BinTree BT)
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