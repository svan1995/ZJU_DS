#define MaxVertexNum 10001
#include <stdio.h>
#include <stdlib.h>

int Visited[MaxVertexNum] = {0,};

typedef int Vertex;
typedef int WeightType;
typedef char DataType;
typedef int ElementType;

typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1,V2;
    // WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    // WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FisrtEdge;
    // DataType Data;
}AdjList[MaxVertexNum];

typedef struct GNode* PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    AdjList G;
};
typedef PtrToGNode LGraph;


LGraph CreateGraph(int VertexNum)
{
    Vertex V;
    LGraph Graph;

    Graph = (LGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
                                // 从1到Nv
    for(V=0;V<=Graph->Nv;V++)   
        Graph->G[V].FisrtEdge = NULL;
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    // NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FisrtEdge;
    Graph->G[E->V1].FisrtEdge = NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    // NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FisrtEdge;
    Graph->G[E->V2].FisrtEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    // Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d",&E->V1,&E->V2);
            InsertEdge(Graph,E);
        }
    }
    
    // for(V=0;V<Graph->Nv;V++)
    //     scanf("%c",&(Graph->G[V].Data));

    return Graph;
}

typedef struct Node* PtrToNode;
struct Node{
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

void Visit(Vertex V)
{
    printf("正在访问%d顶点\n",V);
}

void BFS(LGraph Graph, Vertex S)
{
    Queue Q;
    PtrToAdjVNode W;
    Vertex V;
    int count,last,tail,level;

    Q = CreateQueue();

    Visited[S] = 1;
    count = 1;
    level = 0;
    last = S;
    AddQ(Q,S);  
    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        for(W = Graph->G[V].FisrtEdge;W;W = W->Next){
            if(!Visited[W->AdjV]){
                Visited[W->AdjV] = 1;
                count++;
                tail = W->AdjV;
                AddQ(Q,W->AdjV);
            }
        }
        if(V == last){
            level++;
            last = tail;
        }
        if(level == 6)
            break;
    }

    printf("%d: %.2f%%\n", S,100.0*count/Graph->Nv);
}





int main()
{
    LGraph Graph;
    Graph = BuildGraph();
    int i,j;
    for(i = 1;i <= Graph->Nv;i++){
        BFS(Graph,i);
        for(j = 1; j<= Graph->Nv;j++){
            Visited[j] = 0;
        }
    }

    return 0;
}