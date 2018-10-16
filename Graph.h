#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Queue.h"
#define MaxVertexNum 100
using namespace std;


typedef int WeightType;
typedef int Vertex;
typedef int DataType;


//边的定义
typedef struct ENode *Edge;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};

//邻接矩阵表示的图
typedef struct MGNode *MGraph;
struct MGNode {
	int Nv;//顶点数
	int Ne;//边数
	DataType Data[MaxVertexNum];//顶点数据
	WeightType G[MaxVertexNum][MaxVertexNum];
};


//邻接表表示的图
//邻接点的定义
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;//顶点下标
	WeightType Weight;//头结点到此顶点的边权重
	PtrToAdjVNode Next;//指向下一顶点
};
//顶点表头节点
typedef struct VNode {
	DataType Data;//头结点存放顶点数据
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];
//图节点
typedef struct LGNode *LGraph;
struct LGNode {
	int Nv;
	int Ne;
	AdjList G;
};

//初始化一个有VertexNum个节点没有边的邻接矩阵表示的图
MGraph CreateMGraph(int VertexNum)
{
	Vertex v, w;
	MGraph Graph = (MGraph)malloc(sizeof(struct MGNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (v = 0; v < Graph->Nv; v++)
		for (w = 0; w < Graph->Nv; w++)
			Graph->G[v][w] = INFINITY;
	return Graph;
}

//插入边
void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}

//建立图
MGraph BuildMGraph() {
	Edge E;
	int Nv;//顶点数
	cout << "请输入顶点个数:";
	cin >> Nv;
	MGraph Graph = CreateMGraph(Nv);
	cout << "请输入边数:";
	cin >> Graph->Ne;
	for (int i = 1; i <= Graph->Ne; i++) {
		E = (Edge)malloc(sizeof(struct ENode));
		cout << "请输入边连接的两个顶点和权重:";
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(Graph, E);
	}
	for (Vertex V = 0; V < Graph->Nv; ++V) {
		cout << "请输入顶点数据:";
		cin >> Graph->Data[V];
	}
	return Graph;
}


//初始化一个有VertexNum个节点没有边的邻接表表示的图
LGraph CreateLGraph(int VertexNum)
{
	LGraph Graph = (LGraph)malloc(sizeof(struct LGNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (Vertex V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}


//插入边
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode1->AdjV = E->V2;
	NewNode1->Weight = E->Weight;
	NewNode1->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode1;
	//PtrToAdjVNode NewNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	//NewNode2->AdjV = E->V1;
	//NewNode2->Weight = E->Weight;
	//NewNode2->Next = Graph->G[E->V2].FirstEdge;
	//Graph->G[E->V2].FirstEdge = NewNode2;
}
//建立图
LGraph BuildLGraph() {
	int Nv;//顶点个数
	Edge E;
	cout<<"请输入顶点个数:";
	cin >> Nv;
	LGraph Graph = CreateLGraph(Nv);
	cout<<"请输入边数:";
	cin>>Graph->Ne;
	for (int i = 1; i <= Graph->Ne; i++) {
		E = (Edge)malloc(sizeof(struct ENode));
		cout<<"请输入边连接的两个顶点和权重:";
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(Graph, E);
	}
	for (Vertex V = 0; V < Graph->Nv; ++V) {
		cout << "请输入顶点数据:";
		cin >> Graph->G[V].Data;
	}
	return Graph;
}

//遍历图
//深度优先遍历
//全局变量，访问过的顶点，下标处为1，未访问的为0
int Visited[MaxVertexNum];
void visit(Vertex V) {
	cout << "正在访问顶点:" << V << endl;
}
void DFS(LGraph Graph, Vertex V, void(*visit)(Vertex)) {
	//深度优先，V为出发点
	PtrToAdjVNode W;
	visit(V);
	Visited[V] = true;
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
		//对V的每个邻接点W->AdjV
		if (!Visited[W->AdjV])//若未被访问,递归访问之
			DFS(Graph, W->AdjV, visit);
	}
}
void DFStraversal(LGraph Graph)
{
	Vertex V;
	for (V = 0; V < Graph->Nv; ++V)
		Visited[V] = false;
	for (V = 0; V < Graph->Nv; ++V) {
		if (!Visited[V])
			DFS(Graph, V, visit);
	}
}
//广度优先遍历(邻接表)
void BFStraversal(LGraph Graph) {
	Vertex V, W;
	PtrToAdjVNode X;
	Queue Q = InitQueue();
	for (V = 0; V < Graph->Nv; ++V)//图中所有顶点设为未访问
		Visited[V] = false;
	for (V = 0; V < Graph->Nv; V++) {//遍历图中所有顶点，保证非连通图也可遍历所有顶点
		if (!Visited[V]) {
			Visited[V] = true;//顶点未访问过，设为已访问，并访问
			visit(V);
			EnQueue(Q, V);
			while (!IsEmpty(Q)) {//队列不空时进行循环
				W = DeQueue(Q);
				for (X = Graph->G[W].FirstEdge; X; X = X->Next) {//对此顶点的所有邻接点，遍历访问
					if (!Visited[X->AdjV]) {
						Visited[X->AdjV] = true;
						visit(X->AdjV);
						EnQueue(Q, X->AdjV);
					}
				}
			}
		}
	}
}
//广度优先搜索(邻接矩阵)
//IsEdge判断V->W边是否是图中的边
bool IsEdge(MGraph Graph, Vertex V, Vertex W) {
	return Graph->G[V][W] < INFINITY ? false : true;
}
void BFS(MGraph Graph, Vertex S, void(*visit)(Vertex)) {
	//以S为出发点对邻接矩阵表示的图进行BFS搜索
	Queue Q = InitQueue();
	Vertex V, W;
	for (V = 0; V < Graph->Nv; ++V)//图中所有顶点设为未访问
		Visited[V] = false;
	Visited[S] = true;
	visit(S);
	EnQueue(Q, S);
	while (!IsEmpty(Q)) {
		V = DeQueue(Q);
		for (W = 0; W < Graph->Nv; W++) {//若W是V的邻接点且未访问过，则访问之
			if (!Visited[W] && IsEdge(Graph, V, W)) {
				Visited[W] = true;
				visit(W);
				EnQueue(Q, W);
			}
		}
	}
}



//无权图的单源最短路算法
void Unweighted(LGraph Graph,int dist[],int path[],Vertex S) {
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = InitQueue();
	dist[S] = 0;//顶点到自身的距离为0
	EnQueue(Q, S);//顶点S入队
	while (!IsEmpty(Q)) {
		V = DeQueue(Q);
		for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
			if (dist[W->AdjV] == -1) {
				dist[W->AdjV] = dist[V] + 1;
				path[W->AdjV] = V;
				EnQueue(Q, W->AdjV);
			}
		}
	}
}
//有权图的单源最短路算法
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) {
	Vertex MinV, V;//从未被收集的顶点中找出当前S到此顶点的路径最短的顶点
	int Mindist = INFINITY;
	for (V = 0; V < Graph->Nv; ++V) {//对每个顶点
		if (collected[V] == false && dist[V] < Mindist) {//V未被收集且S和V连通
			Mindist = dist[V];
			MinV = V;
		}
	}
	if (Mindist < INFINITY)
		return MinV;
	else return -1;
}
bool Dijkstra(MGraph Graph, int dist[], int path[], Vertex S) {
	Vertex V, W;
	int collected[MaxVertexNum];
	for (V = 0; V < Graph->Nv; ++V) {
		dist[V] = Graph->G[S][V];
		if (dist[V] < INFINITY)//S和V有直接路径
			path[V] = S;
		else path[V] = -1;
		collected[V] = false;
	}
	dist[S] = 0;
	collected[S] = true;
	while (1) {
		V = FindMinDist(Graph, dist, collected);
		if (V == -1)
			break;
		collected[V] = true;
		for (W = 0; W < Graph->Nv; ++W) {//对于V->W的每个W顶点，更新最短路径
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)//有负回路
					return false;
				if (dist[V] + Graph->G[V][W] < dist[W]) {
					dist[W] = dist[V] + Graph->G[V][W];
					path[W] = V;
				}
			}
		}
	}
	return true;
}
//有权图的多源最短路算法
bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum]) {
	Vertex i, j, k;
	for(i=0;i<Graph->Nv;++i)
		for (j = 0; j < Graph->Nv; ++j) {
			D[i][j] = Graph->G[i][j];//初始化最短路径，默认不存在的边路径权重为INFINITY
			path[i][j] = -1;
		}
	for (k = 0; k < Graph->Nv; ++k)
		for (i = 0; i < Graph->Nv; ++i)
			for (j = 0; j < Graph->Nv; ++j)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0)//存在负值圈
						return false;
					path[i][j] = k;
				}
	return true;
}

//最小生成树算法,稠密图
Vertex FindMinDist(MGraph Graph, WeightType dist[]) {
	//返回未被收录的顶点中dist最小者，dist为当前顶点到生成树的距离
	Vertex MinV, V;
	WeightType MinDist = INFINITY;
	for (V = 0; V < Graph->Nv; ++V) {
		if (dist[V] != 0 && dist[V] < MinDist) {
			MinDist = dist[V];
			MinV = V;
		}
	}
	if (MinDist < INFINITY) return MinV;
	else return -1;
}
int Prim(MGraph Graph, LGraph MST) {
	//将最小生成树保存为邻接表存储的图MST，返回最小权重和
	WeightType dist[MaxVertexNum], TotalWeight = 0;
	Vertex parent[MaxVertexNum], V, W;
	int Vcount = 0;
	MST = CreateLGraph(Graph->Nv);//MST为有Nv个节点没有边的图
	Edge E=(Edge)malloc(sizeof(struct ENode));
	for (V = 0; V < Graph->Nv; ++V) {
		dist[V] = Graph->G[0][V];//dist数组储存该顶点到生成树的最短距离，初始生成树为顶点0
		parent[V] = 0;//暂定所有顶点的父节点都是初始点0
	}
	dist[0] = 0;//处理第一个顶点
	Vcount++;
	parent[0] = -1;
	while (1) {
		V = FindMinDist(Graph, dist);
		if (V == -1) break;
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];//生成树和即将插入的顶点的边
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;//顶点V收录到生成树中
		Vcount++;//收录顶点数加一
		//for循环用于更新顶点到生成树的最短距离和顶点的父节点
		for (W = 0; W < Graph->Nv; ++W) {
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY)//若顶点未收录且是V的邻接点
				if (Graph->G[V][W] < dist[W]) {
					dist[W] = Graph->G[V][W];//更新生成树到此节点的最小距离
					parent[W] = V;//更新父节点
				}
		}
	}
	if (Vcount < Graph->Nv)//说明图不连通
		TotalWeight = -1;
	return TotalWeight;
}


//拓扑排序
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
	int Indegree[MaxVertexNum] = { 0 };//每个顶点的入度初始化为0
	int cnt = 0;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = InitQueue();
	for (V = 0; V < Graph->Nv; ++V)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;//累计每个顶点的入度
	for (V = 0; V < Graph->Nv; ++V)
		if (Indegree[V] == 0)
			EnQueue(Q, V);//把入度为0的顶点入队
	while (!IsEmpty(Q)) {
		V = DeQueue(Q);
		TopOrder[cnt++] = V;//保存拓扑序并累计出列的顶点个数
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)//顶点的入度为0时，入队
				EnQueue(Q, W->AdjV);
	}
	if (cnt != Graph->Nv)//有闭环
		return false;
	else return true;
}
#endif