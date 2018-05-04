typedef struct TNode *Postion;
typedef Postion BinTree;
#define NoInfo 0;

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


void InorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreateStack();
    T = BT;
    while(T || !IsEmpty(S)){
        while(T){
            Push(S,T);
            T = T->Left;
        }
        T = Pop(S);
        printf("%d",T->Data);
        T = T->Right;
    }
}

void PreorderTraversal(BinTree BT)
{
    BinTree T;
    Stack S = CreateStack();
    T= BT;
    while(T || !IsEmpty(S)){
        while(T){
            printf("%d", T->Data);
            Push(S,T);
            T = T->Left;
        }
        T = Pop(S);
        T = T->Right;
    }
}

void LevelorderTraversal(BinTree BT)
{
    Queue Q;
    BinTree T;
    if(!BT) return;
    Q = CreateQueue();
    AddQ(Q,BT);
    while(!IsEmpty(Q)){
        T = Delete(Q);
        printf("%d", T->Data);
        if(T->Left)
            AddQ(Q,T->Left);
        if(T->Right)
            AddQ(Q,T->Right);
    }
}

BinTree CreateTree()
{
    ElementType Data;
    BinTree BT,T;
    Queue Q = CreateQueue();

    scanf("%d",&Data);
    if(Data != NoInfo){
        BT = (BinTree)malloc(sizeof(struct TNode));
        BT->Data = Data;
        BT->Left = BT->Right = NULL;
        AddQ(Q,BT);
    }
    else
        return NULL;
    while(!IsEmpty(Q)){
        T = Delete(Q);
        scanf("%d",&Data);
        if(Data == NoInfo)
            T->Left =NULL;
        else{
            T->Left = (BinTree)malloc(sizeof(struct TNode));
            T->Left->Data = Data;
            T->Left->Left = T->Left->Right = NULL;
            AddQ(Q,T->Left);
        }
        scanf("%d",&Data);
        if(Data == NoInfo)
            T->Right =NULL;
        else{
            T->Right = (BinTree)malloc(sizeof(struct TNode));
            T->Right->Data = Data;
            T->Right->Left = T->Right->Right = NULL;
            AddQ(Q,T->Right);
        }
    }
    return BT;
}

