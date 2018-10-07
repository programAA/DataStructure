#include <iostream>
#include <iomanip>
#include "List.h"

using namespace std;

int main() {
	List L = InitList();
	DestroyList(L);
	cout << L<< endl;
	return 0;
}
