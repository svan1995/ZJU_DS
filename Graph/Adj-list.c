#define MaxVertexNum 100
typedef int Vertex;
typedef int WeightType;
typedef char DataType;


typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
};
typedef PtrToENode Edge;

typedef struct AdjVNode* PtrToAdjVNode;
struct AdjVNode
{
    Vertex AdjV;
    WeightType Weight;
    PtrToAdjVNode Next;
};

typedef struct Vnode{
    PtrToAdjVNode FisrtEdge;
    DataType Data;
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
    PtrToAdjVNode NewNode;
    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V2;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V1].FisrtEdge;
    Graph->G[E->V1].FisrtEdge = NewNode;

    NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
    NewNode->AdjV = E->V1;
    NewNode->Weight = E->Weight;
    NewNode->Next = Graph->G[E->V2].FisrtEdge;
    Graph->G[E->V2].FisrtEdge = NewNode;
}

LGraph BuildGraph()
{
    LGraph Graph;
    Edge E;
    Vertex V;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);
    scanf("%d",&(Graph->Ne));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d %d",&E->V1,&E->V2,&E->Weight);
            InsertEdge(Graph,E);
        }
    }
    
    for(V=0;V<Graph->Nv;V++)
        scanf("%c",&(Graph->G[V].Data));

    return Graph;
}