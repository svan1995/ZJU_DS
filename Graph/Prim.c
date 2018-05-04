Vertex FindMinDist(MGraph Graph, WeightType dist[])
{
	Vertex MinV, V;
	WeightType MinDist = INFINITY;

	for(V = 0, V < Graph->Nv; V++){
		if(dist[V] != 0 && dist[V] < MinDist){
			MinDist = dist[V];
			MinV = V;
		}
	}
	if(MinDist < INFINITY)
		return MinV;
	return -1;
}

int Prim(MGraph Graph, LGraph MST)
{
	WeightType dist[MaxVertexNum], TotalWeight;
	Vertex parent[MaxVertexNum], V, M;
	int VCount;
	Edge E;

	for(V = 0; V < Graph->Nv; V++){
		dist[V] = Graph->G[0][V];
		parent[V] = 0;
	}

	TotalWeight = 0;
	VCount = 0;

	MST = CreateGraph(Graph->Nv);
	E = (Edge)malloc(sizeof(struct ENode));

	dist[0] = 0;
	VCount++;
	parent[0] = -1;

	while(1){
		V = FindMinDist(Graph, dist);
		if(V == -1)
			break;

		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;
		VCount++;

		for(W = 0; W < Graph->Nv; W++)
			if(dist[W]！= 0 && Graph->G[V][W] < INFINITY){
				if(Graph->G[V][W] < dist[W]){
					dist[W] = Graph->G[V][W];
					parent[W] = V;
				}
			}
	}

	if(VCount < Graph->Nv)
		TotalWeight = -1;
	return TotalWeight;

}