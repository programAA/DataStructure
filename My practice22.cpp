#include <iostream>
#include "Graph.h"
using namespace std;
//  要求程序首先输入一个整数N(N < 100)表示后面数据行数。
//	接着读入N行数据。
//	每行数据长度不等，是用空格分开的若干个（不大于100个）正整数（不大于100000）
//	每个整数代表一个ID号。
//	要求程序输出1行，含两个整数m n，用空格分隔。
//	其中，m表示断号ID，n表示重号ID

//int main() {
//	int N[10] = { 0 };
//	for (int i = 0; i <10; i++) {
//		cout << N[i] << endl;
//	}
//	return 0;
//}

//最小生成树Prim算法
//小树慢慢长大
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
	int parent[MaxVertexNum];//下标处保存下标节点的父节点
	Vertex V, W;
	WeightType TotalWeight = 0;
	int count = 0;
	for (V = 0; V < Graph->Nv; V++) {
		dist[V] = Graph->G[0][V];
		parent[V] = 0;
	}
	{//处理第一个节点
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
		//每多收录一个节点，把边插入
		E->V1 = parent[V];
		E->V2 = V;
		E->Weight = dist[V];
		InsertEdge(Graph, E);
		for (W = 0; W < Graph->Nv; W++) {
			if (dist[W] != 0 && Graph->G[V][W] < INFINITY)//如果W未被收录且是V的邻接点
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
