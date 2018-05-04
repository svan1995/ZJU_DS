#define MinData -100001
#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;
typedef struct HNode* Heap; 
struct HNode{
    ElementType *Data;
    int Size;
    int Capacity;
};

typedef Heap MinHeap;

MinHeap CreateHeap(int MaxSize)
{
    MinHeap H = (MinHeap)malloc(sizeof(struct HNode));
    H->Data = (ElementType*)malloc(sizeof(ElementType)*MaxSize);
    H->Size = 0;
    H->Capacity = MaxSize;
    H->Data[0] = MinData;
    return H;
}

void Insert(MinHeap H,ElementType X)
{
    int i;
    i = ++H->Size;
    for(;H->Data[i/2]>X;i/=2){
        H->Data[i] = H->Data[i/2];
    }
    H->Data[i] = X;
}

int main(int argc, char const *argv[])
{
    int M,N;
    int X;
    int i,j;
    int flag=0;
    MinHeap H;
    scanf("%d %d",&M,&N);
    int R[N];
    H = CreateHeap(M);
    for(i=0;i<M;i++){
        scanf("%d",&X);
        Insert(H,X);
    }
    for(i=0;i<N;i++)
        scanf("%d",&R[i]);
    for(i=0;i<N;i++){
        flag = 0;
        for(j=R[i];j>0;j/=2){
            if(flag)
                printf(" ");
            printf("%d", H->Data[j]);
            flag++;
            if(j==1)
                printf("\n");
        }
    }


    return 0;
}


