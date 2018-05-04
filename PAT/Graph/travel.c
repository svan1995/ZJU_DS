#define MaxVertexNum 500
#define INFINITY 65535
#include <stdio.h>
#include <stdlib.h>

typedef int Vertex;
typedef int WeightType;

int collected[MaxVertexNum] = {0,};

typedef struct GNode* PtrToGNode;
struct GNode
{
    int Nv;
    int Ne;
    int Start;
    int End;
    WeightType G[MaxVertexNum][MaxVertexNum];
    int M[MaxVertexNum][MaxVertexNum];
};
typedef PtrToGNode MGraph;

typedef struct ENode* PtrToENode;
struct ENode
{
    Vertex V1,V2;
    WeightType Weight;
    int Money;
};
typedef PtrToENode Edge;


MGraph CreateGraph(int VertexNum)
{
    Vertex V,W;
    MGraph Graph;

    Graph = (MGraph)malloc(sizeof(struct GNode));
    Graph->Nv = VertexNum;
    Graph->Ne = 0;
    Graph->Start = Graph->End = -1;
    for(V=0;V<Graph->Nv;V++){
        for(W=0;W<Graph->Nv;W++){
            Graph->G[V][W] = INFINITY;
            Graph->M[V][W] = INFINITY;
        }
    }
    return Graph;
}

void InsertEdge(MGraph Graph, Edge E)
{
    Graph->G[E->V1][E->V2] = E->Weight;
    Graph->G[E->V2][E->V1] = E->Weight;

    Graph->M[E->V1][E->V2] = E->Money;
    Graph->M[E->V2][E->V1] = E->Money;

}

MGraph BuildGraph()
{
    MGraph Graph;
    Edge E;
    int Nv,i;

    scanf("%d",&Nv);
    Graph = CreateGraph(Nv);

    scanf("%d",&(Graph->Ne));
    scanf("%d %d",&(Graph->Start),&(Graph->End));
    if(Graph->Ne != 0){
        E = (Edge)malloc(sizeof(struct ENode));
        for(i=0;i<Graph->Ne;i++){
            scanf("%d %d %d %d",&E->V1,&E->V2,&E->Weight,&E->Money);
            InsertEdge(Graph,E);
        }
    }
    return Graph;
}

void Travel(MGraph Graph);
void Initialize(MGraph Graph, int *D, int *P ,int *M);
Vertex FindMinDist(MGraph Graph, int* dist, int* collected);
// void SumMoney(MGraph Graph, int* path);

int main(int argc, char const *argv[])
{
    MGraph Graph = BuildGraph();   
    // printf("%d %d\n", Graph->G[0][2],Graph->M[0][2]);
    Travel(Graph);
    return 0;
}

void Travel(MGraph Graph)
{
    int dist[Graph->Nv],path[Graph->Nv],money[Graph->Nv];
    Vertex V, W;
    Initialize(Graph,dist,path,money);
    while(collected[Graph->End] != 1){
        V = FindMinDist(Graph, dist, collected);
        if(V == -1)
            break;
        collected[V] = 1;
        for(W = 0; W < Graph->Nv; W++){
            if(collected[W] != 1 && Graph->G[V][W] < INFINITY){
                if(dist[V] + Graph->G[V][W] < dist[W]){
                    dist[W] = dist[V] + Graph->G[V][W];
                    path[W] = V;
                    money[W] = money[V] + Graph->M[V][W];
                }
                if(dist[V] + Graph->G[V][W] == dist[W]){
                    if(money[V] + Graph->M[V][W] < money[W]){
                        money[W] = money[V] + Graph->M[V][W];
                        path[W] = V;
                    }
                }
            }
        }
    }
    printf("%d ", dist[Graph->End]);
    printf("%d\n", money[Graph->End]);
}

void Initialize(MGraph Graph, int *D, int *P, int *M)
{
    int i;
    for(i = 0; i < Graph->Nv; i++){
        D[i] = Graph->G[Graph->Start][i];
        M[i] = Graph->M[Graph->Start][i];
        if(D[i] == INFINITY)
            P[i] = -1;
        else
            P[i] = 0;
    }
    D[Graph->Start] = 0;
    M[Graph->Start] = 0;
    collected[Graph->Start] = 1;
}

Vertex FindMinDist(MGraph Graph, int* dist, int* collected)
{
    Vertex MinV, V;
    int MinDist = INFINITY;
    for(V = 0; V < Graph->Nv; V++){
        if(collected[V] != 1 && dist[V] < MinDist){
            MinDist = dist[V];
            MinV = V;
        }
    }
    if(MinDist < INFINITY)
        return MinV;
    else
        return -1;
}

// void SumMoney(MGraph Graph, int* path)
// {
//     Vertex V, W;
//     int sum = 0;
//     V = Graph->End;
//     W = path[Graph->End];
//     do{
//         sum += Graph->M[V][W];
//         V = W;
//         W = path[V];
//     }while(V != Graph->Start);
//     printf("%d\n",sum);
// }