#include <iostream>
#include "LinkList.h"

int main() {
	LinkList L = InitLinkList();
	Insert(1, 1, L);
	cout << L->Data << endl;
	return 0;
}