typedef struct Node* PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* PtrToQNode;
struct QNode{
    Position Front,Rear;
    int MaxSize;
};
typedef PtrToQNode Queue;

int IsEmpty(Queue Q)
{
    if(Q->Front == NULL)
        return 1;
    else
        return 0;
}

Queue CreateQueue()
{
    Queue Q;
    Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = Q->Rear = NULL;
    return Q;
}

void AddQ(Queue Q, ElementType X)
{
    Position Cell = (Position)malloc(sizeof(struct Node));
    Cell->Data = X;
    Cell->Next = NULL;
    if(IsEmpty(Q))
        Q->Rear = Q->Front = Cell;
    else{
        Q->Rear->Next = Cell;
        Q->Rear = Cell;
    }
}


ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;
    if(IsEmpty(Q)){
        printf("queue is empty");
        return ERROR;
    }
    else{
        FrontCell = Q->Front;
        if(Q->Front == Q->Rear){
            Q->Front = Q->Rear =NULL;
        }
        else
            Q->Front = Q->Front->Next;
        FrontElem = FrontCell->Data;
        free(FrontCell);
        return FrontElem;

    }
}