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

void Save007(LGraph Graph,int D);
int DFS(LGraph Graph, int i, int D);
int IsSafe(struct GNode V,int D);
int FirstJump(struct GNode V, int D);
int Jump(struct GNode V, struct GNode W, int D);

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
    int i,answer;
    // printf("ok\n");
    for(i=0;i<Graph->Nv;i++){
        if(Graph->G[i].visited == '0' && FirstJump(Graph->G[i],D)){
            // printf("%d\n",i);
            answer = DFS(Graph,i,D);
            if(answer == 1)
                break;
        }
    }
    if(answer == 1)
        printf("Yes\n");
    else
        printf("No\n");
}

int FirstJump(struct GNode V, int D)
{
    int d_2,r_2;
    r_2 = (7.5 + D)*(7.5 + D);
    d_2 = (V.vx)*(V.vx) + (V.vy)*(V.vy);
    if(r_2 >= d_2)
        return 1;
    else
        return 0;
}

int DFS(LGraph Graph, int i, int D)
{
    int answer = 0;
    struct GNode V;
    Graph->G[i].visited = '1';
    V = Graph->G[i];
    if(IsSafe(V,D))
        answer = 1;
    else
    {
        for(int j=0;j<Graph->Nv;j++){
            if(Graph->G[j].visited == '0' && Jump(V,Graph->G[j],D)){
                answer = DFS(Graph,j,D);
                if(answer == 1)
                    break;
            }
        }
    }
    return answer;
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
