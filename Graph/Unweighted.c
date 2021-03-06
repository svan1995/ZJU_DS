// dist[]和path[]全部初始化为-1
void Unweighted(LGraph Graph, int dist[], int path[], Vertex S)
{
    Queue Q;
    Vertex V;
    PtrToAdjVNode W;

    Q = CreateQueue(Graph->Nv);
    dist[S] = 0;
    AddQ(Q,S);

    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        for( W = Graph->G[V].FirstEdge; W; W = W->Next){
            if(dist[W->AdjV] == -1){
                dist[W->AdjV] = dist[V] + 1;
                path[W->AdjV] = V;
                AddQ(Q, W->AdjV);
            }
        }
    }
}