#include <iostream>
//#include "CTree.h"
#include"CGraph.h"
using namespace std;

int main() {
	MGraph<char> Graph;
	Graph.Kruskal();
	return 0;
}


//int main() {
//	Tree<int> T;
//	int x;
//	while (cin >> x)
//		T.Insert(x);
//	T.Delete(5);
//	T.PreOrder1();
//	cout << T.Depth() << endl;
//	return 0;
//}