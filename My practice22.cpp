#include <iostream>
#include <iomanip>
#define MaxVertexNum 10000
using namespace std;

//��ʵ����������ֱ������һ��dfs��ѡһ��u�������������Զ�ĵ�v��
//�ڶ���dfs�ӵ�v�����������������Զ�ĵ�w����ô�������ֱ������v��w��Ҳ�������е��·����

typedef struct AdjVNode{
	int AdjV;
	int Weight;
	struct AdjVNode *Next;
}*PtrToAdjVNode;

typedef struct node {
	PtrToAdjVNode FirstEdge;
}AdjList[MaxVertexNum];

struct GNode {
	int Nv, Ne;
	AdjList G;
};
typedef struct GNode *LGraph;

struct ENode {
	int V1, V2;
	int Weight;
};
typedef struct ENode *Edge;

int Visited[MaxVertexNum] = { 0 };
int max = -1;
int P;
void DFS(LGraph Graph, int S, int Sum) {
	PtrToAdjVNode W;
	if (Sum > max) {
		max = Sum;
		P = S;
	}
	for (W = Graph->G[S].FirstEdge; W; W = W->Next) {//��S��ÿ���ڽӵ�
		if (Visited[W->AdjV] == 0) {//���û�з��ʹ�������֮
			Visited[W->AdjV] = 1;
			DFS(Graph, W->AdjV, Sum + W->Weight);
		}
	}
}

void InsertEdge(LGraph Graph, Edge E)
{
	PtrToAdjVNode NewNode1 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode1->AdjV = E->V2;
	NewNode1->Weight = E->Weight;
	NewNode1->Next = Graph->G[E->V1].FirstEdge;
	Graph->G[E->V1].FirstEdge = NewNode1;
	PtrToAdjVNode NewNode2 = (PtrToAdjVNode)malloc(sizeof(struct AdjVNode));
	NewNode2->AdjV = E->V1;
	NewNode2->Weight = E->Weight;
	NewNode2->Next = Graph->G[E->V2].FirstEdge;
	Graph->G[E->V2].FirstEdge = NewNode2;
}


int main() {
	Edge E = (Edge)malloc(sizeof(struct ENode));
	LGraph Graph = (LGraph)malloc(sizeof(struct GNode));
	cin >> Graph->Nv;
	Graph->Ne = Graph->Nv - 1;
	for (int i = 1; i <= Graph->Nv; i++)
		Graph->G[i].FirstEdge = NULL;
	for (int i = 1; i < Graph->Nv; i++) {
		cin >> E->V1 >> E->V2 >> E->Weight;
		InsertEdge(Graph, E);
	}
	DFS(Graph, 1, 0);
	cout << left << setw(5) << max << left << setw(5) << P << endl;
	DFS(Graph, P, 0);
	cout << left << setw(5) << max << left << setw(5) << P << endl;
	cout << max * (max + 1) / 2 + max * 10 << endl;
	return 0;
}