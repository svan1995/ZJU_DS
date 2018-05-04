#define MaxData 1000
#define MinData -1000
#define ERROR -1
typedef struct HNode* Heap; 
struct HNode{
    ElementType *Data;
    int Size;
    int Capacity;
};

typedef Heap MaxHeap;
typedef Heap MinHeap;



MaxHeap CreateHeap(int MaxSize)
{
    MaxHeap H = (MaxHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MaxData;
    return H;
}

MinHeap CreateHeap_Min(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType *)malloc((MaxSize+1)*sizeof(ElementType));
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MinData;
    return H;    
}

bool IsFull(MaxHeap H)
{
    return(H->Size == H->Capacity);
}

bool Insert(MaxHeap H,ElementType X)
{
    int i;
    if(IsFull(H)){
        printf("MaxHeap is full");
        return false;
    }
    i = ++H->Size;
    for(;H->Data[i/2] < X;i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
    return true;
}

bool Insert_Min(MinHeap H,ElementType X)
{
    int i;
    if(IsFull(H)){
        printf("MinHeap is full");
        return false;
    }
    i = ++H->Size;
    for(;H->Data[i/2] > X;i/=2)
        H->Data[i] = H->Data[i/2];
    H->Data[i] = X;
    return true;
}

bool IsEmpty(MaxHeap H)
{
    return(H->Size == 0);
}

ElementType DeleteMax(MaxHeap H)
{
    int Parent,Child;
    ElementType MaxItem,X;
    if(IsEmpty(H)){
        printf("MaxHeap is empty");
    }
    MaxItem = H->Data[1];
    X = H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent = Child){
        Child = 2 * Parent;
        if((Child != H->Size)&&(H->Data[Child]<H->Data[Child+1]))
            Child++;
        if(X >= H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    return MaxItem;
}

ElementType DeleteMin(MinHeap H)
{
    int Parent,Child;
    ElementType MaxItem,X;
    if(IsEmpty(H)){
        printf("MinHeap is empty");
    }
    MinItem = H->Data[1];
    X = H->Data[H->Size--];
    for(Parent=1;Parent*2<=H->Size;Parent = Child){
        Child = 2 * Parent;
        if((Child != H->Size)&&(H->Data[Child]>H->Data[Child+1]))
            Child++;
        if(X <= H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
    return MinItem;
}

void PercDown(MaxHeap H,int p)
{
    ElementType X;
    int Parent,Child;
    X = H->Data[p];
    for(Parent=p;Parent*2<=H->Size;Parent = Child){
        Child = 2 * Parent;
        if((Child != H->Size)&&(H->Data[Child]<H->Data[Child+1]))
            Child++;
        if(X >= H->Data[Child])
            break;
        else
            H->Data[Parent] = H->Data[Child];
    }
    H->Data[Parent] = X;
}

void BuildHeap(MaxHeap H)
{
    // 假设所有H->Size个元素已经存在于H->Data[]中
    int i;
    for(i = H->Size/2;i>0;i++){
        PercDown(H,i);
    }
}