void Visit(Vertex V)
{
    printf("正在访问%d顶点\n",V);
}

void DFS(LGraph Graph, Vertex V,void(*Visit)(Vertex))
{
    PtrToAdjVNode W;

    Visit(V);
    Visited[V] = true;

    for(W = Graph->G[V].FisrtEdge;W;W=W->Next)
    {
        if(!Visited[W->AdjV]){
            DFS(Graph,W->AdjV,Visit);
        }
    }
}