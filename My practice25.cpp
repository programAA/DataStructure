#include <iostream>
#include <iomanip>
#include "Sort.h"
#include "CGraph.h"



int main() {
	int A[10];
	LGraph<int> Graph;
	Graph.TopSort(A);
	for (int i = 0; i < 10; i++) {
		std::cout << A[i] << std::endl;
	}
}


//int main() {
//	int A[9] = { 7,4,5,3,8,6,9,1,2 };
//    Table_Sort(A, 9);
//	for (int i = 0; i < 9; i++)
//		cout << A[i] << endl;
//	return 0;
//}
