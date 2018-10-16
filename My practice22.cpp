#include <iostream>
#include "Graph.h"
using namespace std;
//  Ҫ�������������һ������N(N < 100)��ʾ��������������
//	���Ŷ���N�����ݡ�
//	ÿ�����ݳ��Ȳ��ȣ����ÿո�ֿ������ɸ���������100������������������100000��
//	ÿ����������һ��ID�š�
//	Ҫ��������1�У�����������m n���ÿո�ָ���
//	���У�m��ʾ�Ϻ�ID��n��ʾ�غ�ID

//int main() {
//	int N[10] = { 0 };
//	for (int i = 0; i <10; i++) {
//		cout << N[i] << endl;
//	}
//	return 0;
//}

//��С������Prim�㷨
//С����������
Vertex FindMin(MGraph Graph,int dist[]) {
	Vertex MinV, V;
	int MinDist = INFINITY;
	for (V = 0; V < Graph->Nv; V++)
		if (dist[V] < MinDist&&dist[V] != 0) {
			MinDist = dist[V];
			MinV = V;
		}
	if (MinDist < INFINITY)
		return MinV;
	else return -1;
}


int Prim(MGraph Graph,LGraph MST) {
	MST = CreateLGraph(Graph->Nv);
	Edge E = (Edge)malloc(sizeof(struct ENode));
	int dist[MaxVertexNum];
	int parent[MaxVertexNum];//�±괦�����±�ڵ�ĸ��ڵ�
	Vertex V, W;
	WeightType TotalWeight = 0;
	int count = 0;
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[0][V];
		parent[V] = 0;
	}
	{//�����һ���ڵ�
		dist[0] = 0;
		parent[0] = -1;
		count++;
	}
	while (1) {
		V = FindMin(Graph, dist);
		if (V == -1)
			break;
		TotalWeight += dist[V];
		count++;
		dist[V]= 0;
		//ÿ����¼һ���ڵ㣬�ѱ߲���
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(Graph, E);
		for (W = 0; W < Graph->Nv; W++) {
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY)//���Wδ����¼����V���ڽӵ�
				if (Graph->G[V][W] < dist[W]) {
					dist[W] = Graph->G[V][W];
					parent[W] = V;
				}
		}
	}
	if (count != Graph->Nv)
		return -1;
	else
		return TotalWeight;
}
