#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "CQueue.h"
#include "CStack.h"
#define MaxVertexNum 100 
typedef float WeightType;
typedef int Vertex;
typedef struct ENode {
	Vertex V1, V2;
	WeightType Weight;
}*Edge;


template <typename T>
class MGraph {
private:
	int Nv;
	int Ne;
	T Data[MaxVertexNum];
	WeightType G[MaxVertexNum][MaxVertexNum];
	void Visit(Vertex V) {
		std::cout << "正在访问顶点:" << V << ":" << Data[V] << std::endl;
	}
	void InsertEdge(Edge E) {
		G[E->V1][E->V2] = E->Weight;
		G[E->V2][E->V1] = E->Weight;
	}
	void DFSAchievement(Vertex S, int Visited[]) {
		Vertex W;
		Visit(S);
		Visited[S] = true;
		for (W = 0; W < Nv; W++) {
			if (G[S][W] < INFINITY && Visited[W] == false)
				DFSAchievement(W, Visited);
		}
	}
	void BFSAchievement(Vertex S, int Visited[]) {
		Vertex V, W;
		Queue<int> Q;
		Q.EnQueue(S);
		Visit(S);
		Visited[S] = true;
		while (!Q.IsEmpty()) {
			V = Q.DeQueue();
			for (W = 0; W < Nv; W++) {
				if (G[V][W] < INFINITY && Visited[W] == false) {
					Q.EnQueue(W);
					Visit(W);
					Visited[W] = true;
				}
			}
		}
	}
	void DisplayPath(Vertex A, Vertex B, int path[]) {
		Vertex V;
		Stack<Vertex> S;
		while (B != A) {
			S.Push(B);
			B = path[B];
		}
		S.Push(A);

		while (!S.IsEmpty()) {
			V = S.Pop();
			std::cout << V << ":" << Data[V] << std::endl;
		}
	}
	Vertex FindMinDist(float dist[]) {
		float MinDist = INFINITY;
		Vertex MinV = -1;
		for (int V = 0; V < Nv; V++) {
			if (dist[V] != 0 && dist[V] < MinDist) {
				MinDist = dist[V];
				MinV = V;
			}
		}
		return MinV;
	}
	Vertex FindMinDist(float dist[], int collected[]) {
		float MinDist = INFINITY;
		Vertex MinV = -1;
		for (int V = 0; V < Nv; V++) {
			if (collected[V] == false && dist[V] < MinDist) {
				MinDist = dist[V];
				MinV = V;
			}
		}
		return MinV;
	}
	bool DijkstraAchievement(float dist[], int path[], Vertex S) {
		Vertex V, W;
		int collected[MaxVertexNum];
		for (V = 0; V < Nv; ++V) {
			collected[V] = false;
			dist[V] = G[S][V];
			if (dist[V] < INFINITY)//S和V有直接路径
				path[V] = S;
			else path[V] = -1;
		}
		dist[S] = 0;
		collected[S] = true;
		while (1) {
			V = FindMinDist(dist, collected);
			if (V == -1)
				break;
			collected[V] = true;
			for (W = 0; W < Nv; ++W) {//对于V的每个邻接点W，更新最短路径
				if (collected[W] == false && G[V][W] < INFINITY) {
					if (G[V][W] < 0)//有负回路
						return false;
					if (dist[V] + G[V][W] < dist[W]) {
						dist[W] = dist[V] + G[V][W];
						path[W] = V;
					}
				}
			}
		}
		return true;
	}
	WeightType PrimAchievement(Vertex S, int A[], int B[]) {
		Vertex V, W;
		int i = 0, j = 0;
		int Vcount = 0;
		WeightType TotalWeight;
		Vertex *parent = new Vertex[Nv];//dist数组储存数组下标对应节点到生成树的最短距离
		WeightType *dist = new WeightType[Nv];//parent数组储存数组下标对应顶点的父节点
		for (V = 0; V < Nv; ++V) {
			dist[V] = G[S][V];//初始的生成树为顶点S
			parent[V] = S;//暂定所有顶点的父节点都是初始点
		}
		TotalWeight = 0;//处理节点S
		dist[S] = 0;
		Vcount++;
		while (1) {
			V = FindMinDist(dist);
			if (V == -1)
				break;
			A[i++] = parent[V];
			B[j++] = V;
			TotalWeight += dist[V];
			dist[V] = 0;
			Vcount++;
			for (W = 0; W < Nv; W++) {//for循环用于更新顶点到生成树的最短距离和顶点的父节点
				if (dist[W] != 0 && G[V][W] < INFINITY) //若顶点未收录且是V的邻接点
					if (G[V][W] < dist[W]) {
						dist[W] = G[V][W];//更新生成树到此节点的最小距离
						parent[W] = V;//更新父节点
					}
			}
		}
		if (Vcount < Nv)//说明图不连通
			TotalWeight = -1;
		return TotalWeight;
	}
	void Swap(ENode &E1, ENode &E2) {
		ENode temp;
		temp.V1 = E1.V1;
		temp.V2 = E1.V2;
		temp.Weight = E1.Weight;
		E1.V1 = E2.V1;
		E1.V2 = E2.V2;
		E1.Weight = E2.Weight;
		E2.V1 = temp.V1;
		E2.V2 = temp.V2;
		E2.Weight = temp.Weight;
	}
	void Edge_Sort(ENode E[], int N) {
		int i, j, flag;
		for (i = N - 1; i > 0; i--) {
			flag = 0;
			for (j = 0; j < i && E[j].Weight>E[j + 1].Weight; j++) {
				Swap(E[j], E[j + 1]);
				flag = 1;
			}
			if (flag == 0)
				break;
		}
	}
public:
	MGraph() {
		Vertex V, W;
		Edge E = new ENode;
		std::cout << "请输入顶点数:";
		std::cin >> Nv;
		std::cout << "请输入边数:";
		std::cin >> Ne;
		for (V = 0; V < Nv; V++)
			for (W = 0; W < Nv; W++)
				G[V][W] = INFINITY;
		for (int i = 1; i <= Ne; i++) {
			std::cout << "请输入边连接的两个顶点和权重:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "请输入第" << V << "个顶点的数据:";
			std::cin >> Data[V];
		}
	}
	MGraph(int VertexNum, int EdgeNum) {
		Vertex V, W;
		Edge E = new ENode;
		Nv = VertexNum;
		Ne = EdgeNum;
		for (V = 0; V < Nv; V++)
			for (W = 0; W < Nv; W++)
				G[V][W] = INFINITY;
		for (int i = 1; i <= Ne; i++) {
			std::cout << "请输入边连接的两个顶点和权重:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "请输入第" << V << "个顶点的数据:";
			std::cin >> Data[V];
		}
	}
	void DFS(Vertex S) {
		int *v = new int[Nv];
		for (int i = 0; i < Nv; i++)
			v[i] = 0;
		DFSAchievement(S, v);
	}
	void BFS(Vertex S) {
		int *v = new int[Nv];
		for (int i = 0; i < Nv; i++)
			v[i] = 0;
		BFSAchievement(S, v);
	}
	void Dijkstra(Vertex A, Vertex B) {
		//有权图的单源最短路算法
		float *dist = new float[Nv];
		int *path = new int[Nv];
		if (DijkstraAchievement(dist, path, A)) {
			std::cout << "The dist from " << A << " to " << B << ":" << dist[B] << std::endl;
			std::cout << "The path from " << A << " to " << B << ":" << endl;
			DisplayPath(A, B, path);
		}
		else
			std::cout << "图中有负回路!" << std::endl;
	}
	bool Floyd(WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum]) {
		Vertex i, j, k;
		for (i = 0; i < Nv; ++i)
			for (j = 0; j < Nv; ++j) {
				D[i][j] = G[i][j];//初始化最短路径，默认不存在的边路径权重为INFINITY
				path[i][j] = -1;
			}
		for (k = 0; k < Nv; ++k)
			for (i = 0; i < Nv; ++i)
				for (j = 0; j < Nv; ++j)
					if (D[i][k] + D[k][j] < D[i][j]) {
						D[i][j] = D[i][k] + D[k][j];
						if (i == j && D[i][j] < 0)//存在负值圈
							return false;
						path[i][j] = k;
					}
		return true;
	}
	void Prim(Vertex S = 0) {//加点法
		int *A = new int[Nv - 1];//存储Nv-1条边
		int *B = new int[Nv - 1];//存储Nv-1条边
		WeightType temp = PrimAchievement(S, A, B);
		if (temp != -1) {
			std::cout << "权重和:" << temp << std::endl;
			std::cout << "各边:" << std::endl;
			for (int i = 0; i < Nv - 1; i++)
				std::cout << A[i] << ":" << Data[A[i]] << "--->" << B[i] << ":" << Data[B[i]] << std::endl;
		}
		else
			std::cout << "图不连通!" << std::endl;
	}
	void Kruskal() {//加边法
		Edge E = new ENode[Ne];
		int i, j, k = 0, n;
		for (i = 0; i < Nv; i++) {
			for (j = i + 1; j < Nv; j++) {
				if (G[i][j] < INFINITY) {
					E[k].V1 = i;
					E[k].V2 = j;
					E[k].Weight = G[i][j];
					k++;
				}
			}
		}
		Edge_Sort(E, Ne);
		Vertex *VexSet = new Vertex[Nv];
		for (i = 0; i < Nv; i++)
			VexSet[i] = i;//每个节点初始为一个集合
		for (i = 0; i < Ne; i++) {
			j = VexSet[E[i].V1];
			k = VexSet[E[i].V2];
			if (j != k) {
				std::cout << E[i].V1 << "--->" << E[i].V2 << std::endl;
				for (n = 0; n < Nv; n++) {
					if (VexSet[n] == k)
						VexSet[n] = j;
				}
			}
		}
	}
};



struct VNode {
	Vertex AdjV;//顶点下标
	WeightType Weight;//头结点到此顶点的边权重
	VNode* Next;//指向下一顶点
};
template <typename T>
struct GList {
	T Data;
	VNode* FirstEdge;
};
template <typename T>
class LGraph {
private:
	int Nv;
	int Ne;
	GList<T> G[MaxVertexNum];
	void Visit(Vertex V) {
		std::cout << "正在访问顶点:" << V << ":" << G[V].Data << std::endl;
	}
	void InsertEdge(Edge E) {
		VNode* NewNode1 = new VNode;
		NewNode1->AdjV = E->V2;
		NewNode1->Weight = E->Weight;
		NewNode1->Next = G[E->V1].FirstEdge;
		G[E->V1].FirstEdge = NewNode1;
		/*VNode* NewNode2 = new VNode;
		NewNode2->AdjV = E->V1;
		NewNode2->Weight = E->Weight;
		NewNode2->Next = G[E->V2].FirstEdge;
		G[E->V2].FirstEdge = NewNode2;*/
	}
	void DFSAchievement(Vertex S,int Visited[]) {
		VNode* V;
		Visit(S);
		Visited[S] = true;
		for (V = G[S].FirstEdge; V; V = V->Next) {
			if (Visited[V->AdjV] == false)
				DFSAchievement(V->AdjV, Visited);
		}
	}
	void BFSAchievement(Vertex S, int Visited[]) {
		Vertex V;
		VNode* W;
		Queue<int> Q;
		Q.EnQueue(S);
		Visit(S);
		Visited[S] = true;
		while (!Q.IsEmpty()) {
			V = Q.DeQueue();
			for (W = G[V].FirstEdge; W; W = W->Next) {
				if (Visited[W->AdjV] == false) {
					Q.EnQueue(W->AdjV);
					Visit(W->AdjV);
					Visited[W->AdjV] = true;
				}
			}
		}
	}
	void DisplayPath(Vertex A, Vertex B, int path[]) {
		Vertex V;
		Stack<Vertex> S;
		while (B != A) {
			S.Push(B);
			B = path[B];
		}
		S.Push(A);

		while (!S.IsEmpty()) {
			V = S.Pop();
			std::cout << V << ":" << G[V].Data << std::endl;
		}
	}
	void UnweightedAchievement(int dist[], int path[], Vertex S) {
		Vertex V;
		VNode* W;
		Queue<T> Q;
		dist[S] = 0;//顶点到自身的距离为0
		Q.EnQueue(S);//顶点S入队
		while (!Q.IsEmpty()) {
			V = Q.DeQueue();
			for (W = G[V].FirstEdge; W; W = W->Next) {
				if (dist[W->AdjV] == -1) {
					dist[W->AdjV] = dist[V] + 1;
					path[W->AdjV] = V;
					Q.EnQueue(W->AdjV);
				}
			}
		}
	}
public:
	LGraph() {
		Vertex V;
		Edge E = new ENode;
		std::cout << "请输入顶点数:";
		std::cin >> Nv;
		std::cout << "请输入边数:";
		std::cin >> Ne;
		for (V = 0; V < Nv; V++)
			G[V].FirstEdge = NULL;
		for (int i = 1; i <= Ne; i++) {
			std::cout << "请输入边连接的两个顶点和权重:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "请输入第" << V << "个顶点的数据:";
			std::cin >> G[V].Data;
		}
	}
	LGraph(int VertexNum, int EdgeNum) {
		Vertex V;
		Edge E = new ENode;
		Nv = VertexNum;
		Ne = EdgeNum;
		for (V = 0; V < Nv; V++)
			G[V].FirstEdge = NULL;
		for (int i = 1; i <= Ne; i++) {
			std::cout << "请输入边连接的两个顶点和权重:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "请输入第" << V << "个顶点的数据:";
			std::cin >> G[V].Data;
		}
	}
	void DFS(Vertex S) {
		int *v = new int[Nv];
		for (int i = 0; i < Nv; i++)
			v[i] = 0;
		DFSAchievement(S, v);
	}
	void BFS(Vertex S) {
		int *v = new int[Nv];
		for (int i = 0; i < Nv; i++)
			v[i] = 0;
		BFSAchievement(S, v);
	}
	void Unweighted(Vertex S,Vertex Aim) {
		//无权图的单源最短路算法
		int *dist = new int[Nv];
		memset(dist, -1, sizeof(int) * Nv);
		int *path = new int[Nv];
		for (Vertex V = 0; V < Nv; V++)
			path[V] = S;
		path[S] = -1;
		UnweightedAchievement(dist, path, S);
		std::cout << "The dist from " << S << " to " << Aim << ":" << dist[Aim] << std::endl;
		std::cout << "The path from " << S << " to " << Aim << ":" << endl;
		DisplayPath(S, Aim, path);
	}
	bool TopSort(Vertex TopOrder[]) {
		int Indegree[MaxVertexNum] = { 0 };//每个顶点的入度初始化为0
		int cnt = 0;
		Vertex V;
		VNode *W;
		Queue<Vertex> Q;
		for (V = 0; V < Nv; ++V)
			for (W = G[V].FirstEdge; W; W = W->Next)
				Indegree[W->AdjV]++;//累计每个顶点的入度
		for (V = 0; V < Nv; ++V)
			if (Indegree[V] == 0)
				Q.EnQueue(V);//把入度为0的顶点入队
		while (!Q.IsEmpty()) {
			V = Q.DeQueue();
			TopOrder[cnt++] = V;//保存拓扑序并累计出列的顶点个数
			for (W = G[V].FirstEdge; W; W = W->Next)
				if (--Indegree[W->AdjV] == 0)//顶点的入度为0时，入队
					Q.EnQueue(W->AdjV);
		}
		if (cnt != Nv)//有闭环
			return false;
		else return true;
	}
};
#endif