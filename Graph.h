#ifndef GRAPH_H
#define GRAPH_H
#include <iostream>
#include "Queue.h"
#define MaxVertexNum 100
using namespace std;
typedef int WeightType;
typedef int Vertex;
typedef int DataType;
//�ߵĶ���
typedef struct ENode *PtrToENode;
struct ENode {
	Vertex V1, V2;
	WeightType Weight;
};
typedef PtrToENode Edge;


//�ڽӾ����ʾ��ͼ
typedef struct MGNode *PreToMGNode;
struct MGNode {
	int Nv;//������
	int Ne;//����
	DataType Data[MaxVertexNum];
	WeightType G[MaxVertexNum][MaxVertexNum];
};
typedef PreToMGNode MGraph;


//�ڽӱ���ʾ��ͼ
//�ڽӵ�Ķ���
typedef struct AdjVNode *PtrToAdjVNode;
struct AdjVNode {
	Vertex AdjV;//�����±�
	WeightType Weight;
	PtrToAdjVNode Next;
};
//�����ͷ�ڵ�
typedef struct VNode {
	DataType Data;
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];
//ͼ�ڵ�
typedef struct LGNode *PtrToLGNode;
struct LGNode {
	int Nv;
	int Ne;
	AdjList G;
};
typedef PtrToLGNode LGraph;


//��ʼ��һ����VertexNum���ڵ�û�бߵ��ڽӾ����ʾ��ͼ
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
//�����
void InsertEdge(MGraph Graph, Edge E)
{
	Graph->G[E->V1][E->V2] = E->Weight;
	Graph->G[E->V2][E->V1] = E->Weight;
}
//����ͼ
MGraph BuildMGraph() {
	Vertex V;
	Edge E;
	int Nv, i;
	MGraph Graph;
	cout << "�����붥�����:";
	cin >> Nv;
	Graph = CreateMGraph(Nv);
	cout << "���������:";
	cin >> Graph->Ne;
	for (i = 1; i <= Graph->Ne; ++i) {
		E = (Edge)malloc(sizeof(struct ENode));
		cout<<"����������ӵ����������Ȩ��:";
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(Graph, E);
	}
	for (V = 0; V < Graph->Nv; ++V) {
		cout << "�����붥������:";
		cin >> Graph->Data[V];
	}
	return Graph;
}


//��ʼ��һ����VertexNum���ڵ�û�бߵ��ڽӱ���ʾ��ͼ
LGraph CreateLGraph(int VertexNum)
{
	Vertex V;
	LGraph Graph = (LGraph)malloc(sizeof(struct LGNode));
	Graph->Nv = VertexNum;
	Graph->Ne = 0;
	for (V = 0; V < Graph->Nv; V++)
		Graph->G[V].FirstEdge = NULL;
	return Graph;
}


//�����
void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode;
	NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode->AdjV = E->V2;
	NewNode->Weight = E->Weight;
	NewNode->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode;
	//NewNode = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	//NewNode->AdjV = E->V1;
	//NewNode->Weight = E->Weight;
	//NewNode->Next = Graph->G[E->V2].FirstEdge;
	//Graph->G[E->V2].FirstEdge = NewNode;
}
//����ͼ
LGraph BuildLGraph() {
	Vertex V;
	Edge E;
	int Nv, i;
	LGraph Graph;
	cout<<"�����붥�����:";
	cin >> Nv;
	Graph = CreateLGraph(Nv);
	cout<<"���������:";
	cin>>Graph->Ne;
	for (i = 1; i <= Graph->Ne; ++i) {
		E = (Edge)malloc(sizeof(struct ENode));
		cout<<"����������ӵ����������Ȩ��:";
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(Graph, E);
	}
	for (V = 0; V < Graph->Nv; ++V) {
		cout << "�����붥������:";
		cin>>Graph->G[V].Data;
	}
	return Graph;
}

//����ͼ
//������ȱ���
int Visited[MaxVertexNum];
void visit(Vertex V) {
	cout << "���ڷ��ʶ���:" << V << endl;
}
void DFS(LGraph Graph, Vertex V) {
	//������ȣ�VΪ������
	PtrToAdjVNode W;
	visit(V);
	Visited[V] = true;
	for (W = Graph->G[V].FirstEdge; W; W = W->Next) {
		//��V��ÿ���ڽӵ�W->AdjV
		if (!Visited[W->AdjV])//��δ������,�ݹ����֮
			DFS(Graph, W->AdjV);
	}
}
void DFStraversal(LGraph Graph)
{
	Vertex V;
	for (V = 0; V < Graph->Nv; ++V)
		Visited[V] = false;
	for (V = 0; V < Graph->Nv; ++V) {
		if (!Visited[V])
			DFS(Graph, V);
	}
}
//������ȱ���
void BFStraversal(LGraph Graph) {
	Vertex V, W;
	PtrToAdjVNode X;
	Queue Q = InitQueue();
	for (V = 0; V < Graph->Nv; ++V)//ͼ�����ж�����Ϊδ����
		Visited[V] = false;
	for (V = 0; V < Graph->Nv; V++)//����ͼ�����ж��㣬��֤����ͨͼҲ�ɱ������ж���
		if (!Visited[V]) {
			Visited[V] = true;//����δ���ʹ�����Ϊ�ѷ��ʣ�������
			visit(V);
			EnQueue(Q, V);
			while (!IsEmpty(Q)) {
				W = DeQueue(Q);
				for(X=Graph->G[W].FirstEdge;X;X=X->Next)//�Դ˶���������ڽӵ㣬��������
					if (!Visited[X->AdjV]) {
						Visited[X->AdjV] = true;
						visit(X->AdjV);
						EnQueue(Q, X->AdjV);
					}
			}
		}
}

//��Ȩͼ�ĵ�Դ���·�㷨
void Unweighted(LGraph Graph,int dist[],int path[],Vertex S) {
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = InitQueue();
	dist[S] = 0;//���㵽�����ľ���Ϊ0
	EnQueue(Q, S);//����S���
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
//��Ȩͼ�ĵ�Դ���·�㷨
Vertex FindMinDist(MGraph Graph, int dist[], int collected[]) {
	Vertex MinV, V;//��δ���ռ��Ķ������ҳ���ǰS���˶����·����̵Ķ���
	int Mindist = INFINITY;
	for (V = 0; V < Graph->Nv; ++V) {//��ÿ������
		if (collected[V] == false && dist[V] < Mindist) {//Vδ���ռ���S��V��ͨ
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
		if (dist[V] < INFINITY)//S��V��ֱ��·��
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
		for (W = 0; W < Graph->Nv; ++W) {//����V->W��ÿ��W���㣬�������·��
			if (collected[W] == false && Graph->G[V][W] < INFINITY) {
				if (Graph->G[V][W] < 0)//�и���·
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
//��Ȩͼ�Ķ�Դ���·�㷨
bool Floyd(MGraph Graph, WeightType D[][MaxVertexNum], Vertex path[][MaxVertexNum]) {
	Vertex i, j, k;
	for(i=0;i<Graph->Nv;++i)
		for (j = 0; j < Graph->Nv; ++j) {
			D[i][j] = Graph->G[i][j];//��ʼ�����·����Ĭ�ϲ����ڵı�·��Ȩ��ΪINFINITY
			path[i][j] = -1;
		}
	for (k = 0; k < Graph->Nv; ++k)
		for (i = 0; i < Graph->Nv; ++i)
			for (j = 0; j < Graph->Nv; ++j)
				if (D[i][k] + D[k][j] < D[i][j]) {
					D[i][j] = D[i][k] + D[k][j];
					if (i == j && D[i][j] < 0)//���ڸ�ֵȦ
						return false;
					path[i][j] = k;
				}
	return true;
}

//��С�������㷨,����ͼ
Vertex FindMinDist(MGraph Graph, WeightType dist[]) {
	//����δ����¼�Ķ�����dist��С�ߣ�distΪ��ǰ���㵽�������ľ���
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
int Prim(MGraph Graph, MGraph MST) {
	//����С����������Ϊ�ڽӱ��洢��ͼMST��������СȨ�غ�
	WeightType dist[MaxVertexNum], TotalWeight = 0;
	Vertex parent[MaxVertexNum], V, W;
	int Vcount = 0;
	Edge E=(Edge)malloc(sizeof(struct ENode));
	for (V = 0; V < Graph->Nv; ++V) {
		dist[V] = Graph->G[0][V];//dist���鴢��ö��㵽����������̾��룬��ʼ������Ϊ����0
		parent[V] = 0;//�ݶ����ж���ĸ��ڵ㶼�ǳ�ʼ��0
	}
	MST = CreateMGraph(Graph->Nv);//MSTΪ��Nv���ڵ�û�бߵ�ͼ
	dist[0] = 0;//������һ������
	Vcount++;
	parent[0] = -1;
	while (1) {
		V = FindMinDist(Graph, dist);
		if (V == -1) break;
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];//�������ͼ�������Ķ���ı�
		InsertEdge(MST, E);
		TotalWeight += dist[V];
		dist[V] = 0;//����V��¼����������
		Vcount++;//��¼��������һ
		//forѭ�����ڸ��¶��㵽����������̾���Ͷ���ĸ��ڵ�
		for (W = 0; W < Graph->Nv; ++V) {
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY)//������δ��¼����V���ڽӵ�
				if (Graph->G[V][W] < dist[W]) {
					dist[W] = Graph->G[V][W];//�������������˽ڵ����С����
					parent[W] = V;//���¸��ڵ�
				}
		}
	}
	if (Vcount < Graph->Nv)//˵��ͼ����ͨ
		TotalWeight = -1;
	return TotalWeight;
}


//��������
bool TopSort(LGraph Graph, Vertex TopOrder[]) {
	int Indegree[MaxVertexNum], cnt;
	Vertex V;
	PtrToAdjVNode W;
	Queue Q = InitQueue();
	for (V = 0; V < Graph->Nv; V++)
		Indegree[V] = 0;//��ʼ��ÿ����������Ϊ0
	for (V = 0; V < Graph->Nv; ++V)
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			Indegree[W->AdjV]++;//�ۼ�ÿ����������
	for (V = 0; V < Graph->Nv; ++V)
		if (Indegree[V] == 0)
			EnQueue(Q, V);//�����Ϊ0�Ķ������
	while (!IsEmpty(Q)) {
		V = DeQueue(Q);
		TopOrder[cnt++] = V;//�ۼƳ��еĶ������
		for (W = Graph->G[V].FirstEdge; W; W = W->Next)
			if (--Indegree[W->AdjV] == 0)//��������Ϊ0ʱ�����
				EnQueue(Q, W->AdjV);
	}
	if (cnt != Graph->Nv)
		return false;
	else return true;
}
#endif