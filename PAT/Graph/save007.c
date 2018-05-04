#include <stdio.h>
#include <stdlib.h>



typedef struct GNode
{
    char visited;
    int vx;
    int vy;
}MyGraph;

void Save007(MyGraph* Graph,int N,int D);
int DFS(MyGraph* Graph, int i,int N, int D);
int IsSafe(MyGraph V,int D);
int FirstJump(MyGraph V, int D);
int Jump(MyGraph V, MyGraph W, int D);


int main(int argc, char const *argv[])
{
    int N,D;
    scanf("%d %d",&N,&D);
    MyGraph Graph[N];
    for(int i=0;i<N;i++){
        scanf("%d %d",&(Graph[i].vx),&(Graph[i].vy));
        Graph[i].visited = '0';
    }
    // printf("ok\n");
    Save007(Graph,N,D);

    return 0;
}


void Save007(MyGraph* Graph, int N, int D)
{
    int i,answer;
    // printf("ok\n");
    for(i=0;i<N;i++){
        if(Graph[i].visited == '0' && FirstJump(Graph[i],D)){
            // printf("%d\n",i);
            answer = DFS(Graph,i,N,D);
            if(answer == 1)
                break;
        }
    }
    if(answer == 1)
        printf("Yes\n");
    else
        printf("No\n");
}

int FirstJump(MyGraph V, int D)
{
    int d_2,r_2;
    r_2 = (15 + D)*(15 + D);
    d_2 = (V.vx)*(V.vx) + (V.vy)*(V.vy);
    if(r_2 >= d_2)
        return 1;
    else
        return 0;
}

int DFS(MyGraph* Graph, int i,int N, int D)
{
    int answer = 0;
    MyGraph V;
    Graph[i].visited = '1';
    V = Graph[i];
    if(IsSafe(V,D))
        answer = 1;
    else
    {
        for(int j=0;j<N;j++){
            if(Graph[j].visited == '0' && Jump(V,Graph[j],D)){
                answer = DFS(Graph,j,N,D);
                if(answer == 1)
                    break;
            }
        }
    }
    return answer;
}

int IsSafe(MyGraph V,int D)
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

int Jump(MyGraph V, MyGraph W, int D)
{
    int d;
    d = (V.vx-W.vx)*(V.vx-W.vx) + (V.vy-W.vy)*(V.vy-W.vy);
    if(d*d <= D*D)
        return 1;
    else
        return 0;
}
