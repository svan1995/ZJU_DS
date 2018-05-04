void Visit(Vertex V)
{
    printf("正在访问%d顶点\n",V);
}

void BFS_L(LGraph Graph, Vertex S,void(*Visit)(Vertex))
{
    Queue Q;
    PtrToAdjVNode W;
    Vertex V;

    Visit(S);
    Visited[S] = true;
    AddQ(Q,S);
    
    while(!IsEmpty(Q)){
        V = DeleteQ(Q);
        for(W = Graph->G[V].FisrtEdge;W;W = W->Next){
            if(!Visited[W->AdjV]){
                Visit(W->AdjV);
                Visited[W->AdjV] = true;
                AddQ(Q,W->AdjV);
            }
        }
    }
}



