#include <iostream>
#include "CSort.h"
using namespace std;

int main() {
	char A[10] = { 'a','c','i','f','h','j','e','b','d','g' };
	Merge_Sort1(A, 10);
	for (int i = 0; i < 10; i++)
		cout << A[i] << endl;
	return 0;
}


//int main() {
//	int A[9] = { 7,4,5,3,8,6,9,1,2 };
//    Table_Sort(A, 9);
//	for (int i = 0; i < 9; i++)
//		cout << A[i] << endl;
//	return 0;
//}
