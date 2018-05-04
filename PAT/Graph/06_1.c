#include <stdio.h>
#include <stdlib.h>

#define MaxVertexNum 10
typedef int Vertex;
typedef int WeightType;
typedef int ElementType;
typedef char DataType;

int Visited[MaxVertexNum]={0,};


typedef struct Node* PtrToNode;
struct Node{
    ElementType Data;
    PtrToNode Next;
};
typedef PtrToNode Position;

typedef struct QNode* PtrToQNode;
struct QNode{
    Position Front,Rear;
};
typedef PtrToQNode Queue;

void AddQ(Queue Q,ElementType X)
{

    Position RearCell=(Position)malloc(sizeof(struct Node));
    RearCell->Data = X;
    RearCell->Next = NULL;
    if(Q->Front == NULL){
        Q->Front = RearCell;
        Q->Rear = RearCell;
    }
    else{
        Q->Rear->Next = RearCell;
        Q->Rear = RearCell;
    }
}

int IsEmpty(Queue Q)
{
    if(Q->Front == NULL)
        return 1;
    else
        return 0;
}

ElementType DeleteQ(Queue Q)
{
    Position FrontCell;
    ElementType FrontElem;
    
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
    for(V=0;V<Graph->Nv;V++)
        Graph->G[V].FisrtEdge = NULL;
    return Graph;
}

void InsertEdge(LGraph Graph, Edge E)
{

    PtrToAdjVNode NewNode,Pre,Now;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    // NewNode->Weight = E->Weight;
    Pre = Graph->G[E->V1].FisrtEdge;
    if(Pre == NULL || NewNode->AdjV < Pre->AdjV){
        NewNode->Next = Pre;
        Graph->G[E->V1].FisrtEdge = NewNode;
    }else{
        while(Pre){
            Now = Pre->Next;
            if(Now == NULL || NewNode->AdjV < Now->AdjV){
                NewNode->Next = Now;
                Pre->Next = NewNode;
                break;
            }
            Pre = Now;
            Now = Now->Next;
    }
    }


    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    // NewNode->Weight = E->Weight;

    Pre = Graph->G[E->V2].FisrtEdge;
    if(Pre == NULL || NewNode->AdjV < Pre->AdjV){
        NewNode->Next = Pre;
        Graph->G[E->V2].FisrtEdge = NewNode;
    }else{
        while(Pre){
            Now = Pre->Next;
            if(Now == NULL || NewNode->AdjV < Now->AdjV){
                NewNode->Next = Now;
                Pre->Next = NewNode;
                break;
            }
            Pre = Now;
            Now = Now->Next;
    }
    }

}

LGraph BuildGraph(int Nv,int NE)
{
    LGraph Graph;
    Edge E;
    int i;

    Graph = CreateGraph(Nv);
    Graph->Ne = NE;
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


void Visit(Vertex V)
{
    printf("%d ",V);
}

void DFS(LGraph Graph, Vertex V,void(*Visit)(Vertex))
{
    PtrToAdjVNode W;

    Visit(V);
    Visited[V] = 1;

    for(W = Graph->G[V].FisrtEdge;W;W=W->Next)
    {
        if(!Visited[W->AdjV]){
            DFS(Graph,W->AdjV,Visit);
        }
    }
}

void BFS(LGraph Graph, Vertex S,void(*Visit)(Vertex))
{
    Queue Q = (Queue)malloc(sizeof(struct QNode));
    Q->Front = Q->Rear= NULL;
    PtrToAdjVNode W;
    Vertex V;

    Visit(S);
    Visited[S] = 1;
    // printf("ok\n");
    AddQ(Q,S);
    // printf("ok\n");
    
    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        for(W = Graph->G[V].FisrtEdge;W;W = W->Next){
            if(!Visited[W->AdjV]){
                Visit(W->AdjV);
                Visited[W->AdjV] = 1;
                AddQ(Q,W->AdjV);
            }
        }
    }
}


void ListComponents_D(LGraph Graph)
{
    for(int i=0;i<Graph->Nv;i++){
        if(!Visited[i]){
            printf("{ ");
            DFS(Graph,i,Visit);
            printf("}\n");
        }
    }
}


void ListComponents_B(LGraph Graph)
{
    for(int i=0;i<Graph->Nv;i++){
        if(!Visited[i]){
            printf("{ ");
            BFS(Graph,i,Visit);
            printf("}\n");
        }
    }
}

int main()
{
    int N,E;
    LGraph Graph;

    scanf("%d %d",&N,&E);
    Graph = BuildGraph(N,E);
    // DFS(Graph,0,Visit);
    ListComponents_D(Graph);

    for(int j=0;j<N;j++)
        Visited[j] = 0;
    ListComponents_B(Graph);

    return 0;
}