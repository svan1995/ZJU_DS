typedef struct TNode *Postion;
typedef Postion BinTree;

struct TNode
{
    ElementType Data;
    BinTree Left;
    BinTree Right;
};


Postion Find(BinTree BST,ElementType X)
{
    if(!BST)
        return NULL;
    if(X > BST->Data)
        return Find(BST->Right,X);
    else if(X < BST->Data)
        return Find(BST->Left,X);
    else
        return BST;
}

Postion Find(BinTree BST,ElementType X)
{
    while(BST){
        if(X > BST->Data)
            BST = BST->Right;
        else if(X < BST->Data)
            BST = BST->Left;
        else 
            break;
    }
    return BST;
}

Postion FindMax(BinTree BST)
{
    if(BST)
        while(BST->Right)
            BST = BST->Right;
    return BST;
}

Postion FindMin(BinTree BST)
{
    if(BST)
        while(BST->Left)
            BST = BST->Left;
    return BST;
}


BinTree Insert(BinTree BST,ElementType X)
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

BinTree Delete(BinTree BST,ElementType X)
{
    Postion Tmp;
    if(!BST)
        printf("the value is not in BST");
    else{
        if(X < BST->Data)
            BST->Left = Delete(BST->Left,X);
        if(X > BST->Data)
            BST->Right = Delete(BST->Right,X);
        else{
            if(BST->Left && BST->Right){
                Tmp = FindMin(BST->Right);
                BST->Data = Tmp->Data;
                BST->Right = Delete(BST->Right,BST->Data);
            }
            else{
                Tmp = BST;
                if(!BST->Left)
                    BST = BST->Right;
                else
                    BST = BST->Left;
                free(Tmp);
            }
        }
    }
    return BST;
}