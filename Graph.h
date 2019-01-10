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
		std::cout << "���ڷ��ʶ���:" << V << ":" << Data[V] << std::endl;
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
			if (dist[V] < INFINITY)//S��V��ֱ��·��
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
			for (W = 0; W < Nv; ++W) {//����V��ÿ���ڽӵ�W���������·��
				if (collected[W] == false && G[V][W] < INFINITY) {
					if (G[V][W] < 0)//�и���·
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
		Vertex *parent = new Vertex[Nv];//dist���鴢�������±��Ӧ�ڵ㵽����������̾���
		WeightType *dist = new WeightType[Nv];//parent���鴢�������±��Ӧ����ĸ��ڵ�
		for (V = 0; V < Nv; ++V) {
			dist[V] = G[S][V];//��ʼ��������Ϊ����S
			parent[V] = S;//�ݶ����ж���ĸ��ڵ㶼�ǳ�ʼ��
		}
		TotalWeight = 0;//����ڵ�S
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
			for (W = 0; W < Nv; W++) {//forѭ�����ڸ��¶��㵽����������̾���Ͷ���ĸ��ڵ�
				if (dist[W] != 0 && G[V][W] < INFINITY) //������δ��¼����V���ڽӵ�
					if (G[V][W] < dist[W]) {
						dist[W] = G[V][W];//�������������˽ڵ����С����
						parent[W] = V;//���¸��ڵ�
					}
			}
		}
		if (Vcount < Nv)//˵��ͼ����ͨ
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
		std::cout << "�����붥����:";
		std::cin >> Nv;
		std::cout << "���������:";
		std::cin >> Ne;
		for (V = 0; V < Nv; V++)
			for (W = 0; W < Nv; W++)
				G[V][W] = INFINITY;
		for (int i = 1; i <= Ne; i++) {
			std::cout << "����������ӵ����������Ȩ��:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "�������" << V << "�����������:";
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
			std::cout << "����������ӵ����������Ȩ��:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "�������" << V << "�����������:";
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
		//��Ȩͼ�ĵ�Դ���·�㷨
		float *dist = new float[Nv];
		int *path = new int[Nv];
		if (DijkstraAchievement(dist, path, A)) {
			std::cout << "The dist from " << A << " to " << B << ":" << dist[B] << std::endl;
			std::cout << "The path from " << A << " to " << B << ":" << endl;
			DisplayPath(A, B, path);
		}
		else
			std::cout << "ͼ���и���·!" << std::endl;
	}
	bool Floyd(WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum]) {
		Vertex i, j, k;
		for (i = 0; i < Nv; ++i)
			for (j = 0; j < Nv; ++j) {
				D[i][j] = G[i][j];//��ʼ�����·����Ĭ�ϲ����ڵı�·��Ȩ��ΪINFINITY
				path[i][j] = -1;
			}
		for (k = 0; k < Nv; ++k)
			for (i = 0; i < Nv; ++i)
				for (j = 0; j < Nv; ++j)
					if (D[i][k] + D[k][j] < D[i][j]) {
						D[i][j] = D[i][k] + D[k][j];
						if (i == j && D[i][j] < 0)//���ڸ�ֵȦ
							return false;
						path[i][j] = k;
					}
		return true;
	}
	void Prim(Vertex S = 0) {//�ӵ㷨
		int *A = new int[Nv - 1];//�洢Nv-1����
		int *B = new int[Nv - 1];//�洢Nv-1����
		WeightType temp = PrimAchievement(S, A, B);
		if (temp != -1) {
			std::cout << "Ȩ�غ�:" << temp << std::endl;
			std::cout << "����:" << std::endl;
			for (int i = 0; i < Nv - 1; i++)
				std::cout << A[i] << ":" << Data[A[i]] << "--->" << B[i] << ":" << Data[B[i]] << std::endl;
		}
		else
			std::cout << "ͼ����ͨ!" << std::endl;
	}
	void Kruskal() {//�ӱ߷�
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
			VexSet[i] = i;//ÿ���ڵ��ʼΪһ������
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
	Vertex AdjV;//�����±�
	WeightType Weight;//ͷ��㵽�˶���ı�Ȩ��
	VNode* Next;//ָ����һ����
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
		std::cout << "���ڷ��ʶ���:" << V << ":" << G[V].Data << std::endl;
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
		dist[S] = 0;//���㵽����ľ���Ϊ0
		Q.EnQueue(S);//����S���
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
		std::cout << "�����붥����:";
		std::cin >> Nv;
		std::cout << "���������:";
		std::cin >> Ne;
		for (V = 0; V < Nv; V++)
			G[V].FirstEdge = NULL;
		for (int i = 1; i <= Ne; i++) {
			std::cout << "����������ӵ����������Ȩ��:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "�������" << V << "�����������:";
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
			std::cout << "����������ӵ����������Ȩ��:";
			std::cin >> E->V1 >> E->V2 >> E->Weight;
			InsertEdge(E);
		}
		for (V = 0; V < Nv; ++V) {
			std::cout << "�������" << V << "�����������:";
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
		//��Ȩͼ�ĵ�Դ���·�㷨
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
		int Indegree[MaxVertexNum] = { 0 };//ÿ���������ȳ�ʼ��Ϊ0
		int cnt = 0;
		Vertex V;
		VNode *W;
		Queue<Vertex> Q;
		for (V = 0; V < Nv; ++V)
			for (W = G[V].FirstEdge; W; W = W->Next)
				Indegree[W->AdjV]++;//�ۼ�ÿ����������
		for (V = 0; V < Nv; ++V)
			if (Indegree[V] == 0)
				Q.EnQueue(V);//�����Ϊ0�Ķ������
		while (!Q.IsEmpty()) {
			V = Q.DeQueue();
			TopOrder[cnt++] = V;//�����������ۼƳ��еĶ������
			for (W = G[V].FirstEdge; W; W = W->Next)
				if (--Indegree[W->AdjV] == 0)//��������Ϊ0ʱ�����
					Q.EnQueue(W->AdjV);
		}
		if (cnt != Nv)//�бջ�
			return false;
		else return true;
	}
};
#endif