#include <iostream>
#include <iomanip>
#include "Sort.h"



int main() {
	int A[10] = { 5,4,1,2,3,6,8,7,9,0 };
	Quick_Sort(A, 10);
	for (int i = 0; i < 10; i++)
		std::cout << A[i] << std::endl;
}


//int main() {
//	int A[9] = { 7,4,5,3,8,6,9,1,2 };
//    Table_Sort(A, 9);
//	for (int i = 0; i < 9; i++)
//		cout << A[i] << endl;
//	return 0;
//}
