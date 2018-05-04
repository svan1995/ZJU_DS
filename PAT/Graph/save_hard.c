#include <stdio.h>
#include <stdlib.h>
#define MaxNum 100

typedef struct GNode
{
    char visited;
    int vx;
    int vy;
}MyGraph[MaxNum];

struct Node 
{
    int Nv;
    MyGraph G;
};
typedef struct Node* LGraph;

typedef int ElementType;

typedef struct SNode* PtrToNode;
struct SNode{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* PtrToQNode;
struct QNode{
    Position Front,Rear;
    // int MaxSize;
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
    Position Cell = (Position)malloc(sizeof(struct SNode));
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
    // if(IsEmpty(Q)){
    //     printf("queue is empty");
    //     return ERROR;
    // }
    
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


typedef struct SSNode* PtrToSNode;
struct SSNode{
    ElementType Data;
    PtrToSNode Next;
};
typedef PtrToSNode Stack;

Stack CreateStack()
{
    Stack S;
    S = malloc(sizeof(struct SSNode));
    S->Next = NULL;
    return S;
}

int IsSEmpty(Stack S)
{
    return S->Next == NULL;
}

void Push(Stack S,ElementType X)
{
    PtrToSNode TmpCell;
    TmpCell = (PtrToSNode)malloc(sizeof(struct SSNode));
    TmpCell->Data = X;
    TmpCell->Next = S->Next;
    S->Next = TmpCell;
    
}

ElementType Pop(Stack S)
{
    PtrToSNode FirstCell;
    ElementType TopElem;

    FirstCell = S->Next;
    TopElem = FirstCell->Data;
    S->Next = FirstCell->Next;
    free(FirstCell);
    return TopElem;

}



void Save007(LGraph Graph,int D);
int IsSafe(struct GNode V,int D);
int FirstJump(struct GNode V, int D);
int Jump(struct GNode V, struct GNode W, int D);
int FirstDistance(LGraph Graph, int i, int* path);
void Path(LGraph Graph, int i, int* path);

int main(int argc, char const *argv[])
{
    int N,D;
    scanf("%d %d",&N,&D);
    LGraph Graph;
    Graph = (LGraph)malloc(sizeof(struct Node));
    Graph->Nv = N;
    for(int i=0;i<N;i++){
        scanf("%d %d",&(Graph->G[i].vx),&(Graph->G[i].vy));
        Graph->G[i].visited = '0';
    }
    // printf("ok\n");
    Save007(Graph,D);
    return 0;
}


void Save007(LGraph Graph, int D)
{
    int i,answer,V,X;
    int dist[Graph->Nv], path[Graph->Nv], safe[Graph->Nv];
    Queue Q;
    Q = CreateQueue();
    answer = 0;
    X = 51;
    for(int i = 0; i < Graph->Nv; i++){
        dist[i] = -1;
        path[i] = -2;
        safe[i] = 0;
    }
    if(D >= 42.5){
        printf("1\n");
        return;
    }

    // printf("ok\n");
    for(i=0;i<Graph->Nv;i++){
        if(Graph->G[i].visited == '0' && FirstJump(Graph->G[i],D)){
            dist[i] = 1;
            path[i] = -1;
            Graph->G[i].visited = '1';
            if(IsSafe(Graph->G[i],D)){
                safe[i] = 1;
                answer = 1;
            }
            AddQ(Q,i); 
        }
    }

    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        for(i = 0; i < Graph->Nv; i++){
            if(Graph->G[i].visited == '0' && Jump(Graph->G[V],Graph->G[i],D)){
                dist[i] = dist[V] + 1;
                path[i] = V;
                Graph->G[i].visited = '1';
                if(IsSafe(Graph->G[i],D)){
                    safe[i] = 1;
                    answer = 1;
                }
                AddQ(Q,i);
            }
        }
    }

    if(answer == 0){
        printf("0\n");
    }
    if(answer == 1){
        for(i = 0; i < Graph->Nv; i++){
            if(safe[i] == 1){
                X = i;
            }
        }
        for(i = 0; i < Graph->Nv; i++){
            if(safe[i] == 1){
                if(dist[i] < dist[X])
                    X = i;
                if(dist[i] == dist[X] && FirstDistance(Graph,i,path) < FirstDistance(Graph,X,path))
                    X = i;
            }
        }
        printf("%d\n", dist[X]+1);
        Path(Graph,X,path);
    }
        
}

int FirstJump(struct GNode V, int D)
{
    int d_2,r_2;
    r_2 = (7.5 + D)*(7.5 + D);
    d_2 = (V.vx)*(V.vx) + (V.vy)*(V.vy);
    if(r_2 >= d_2){
        return 1;
    }
    else
        return 0;
}



int IsSafe(struct GNode V,int D)
{
    int left,right,up,down;
    left = V.vx - D;
    right = V.vx + D;
    up = V.vy + D;
    down = V.vy - D;
    if(left <= -50 || right >= 50 || up >= 50 || down <= -50 )
        return 1;
    else
        return 0;
}

int Jump(struct GNode V, struct GNode W, int D)
{
    int d;
    d = (V.vx-W.vx)*(V.vx-W.vx) + (V.vy-W.vy)*(V.vy-W.vy);
    if(d <= D*D)
        return 1;
    else
        return 0;
}

int FirstDistance(LGraph Graph, int i, int* path)
{
    while(path[i] != -1){
        i = path[i];
    }
    return (Graph->G[i].vx * Graph->G[i].vx + Graph->G[i].vy + Graph->G[i].vy);
}

void Path(LGraph Graph, int i, int* path)
{
    Stack S;
    int X;
    S = CreateStack();
    while(path[i] != -1){
        Push(S,i);
        i = path[i];
    }
    Push(S,i);

    
    while(!IsSEmpty(S)){
        X = Pop(S);
        printf("%d %d\n", Graph->G[X].vx, Graph->G[X].vy);
    }
}