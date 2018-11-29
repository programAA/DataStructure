#include <iostream>
using namespace std;

typedef int ElemType;
struct LNode {
	ElemType Data;
	struct LNode*  Next;
};

void InsertLast(struct LNode **L, int x) {
	struct LNode * P = (struct LNode *)malloc(sizeof(struct LNode));
	if (P == NULL) {
		exit(1);
	}
	P->Data = x;
	P->Next = NULL;
	if (*L == NULL)
		*L = P;
	else {
		struct LNode *P1 = *L;
		while (P1->Next) {
			P1 = P1->Next;
		}
		P1->Next = P;
	}
}
void Traverse(struct LNode *L) {
	while (L != NULL) {
		cout << L->Data << endl;
		L = L->Next;
	}
}
//2.1  合并两个有序链表，返回指向新链表的头结点的指针
struct LNode* Merge(struct LNode** L1, struct LNode** L2) {
	struct LNode  *L, *P1, *P2;//L保存新链表的头结点
	if (*L1 == NULL && *L2 == NULL)//*L1和*L2都为空
		return NULL;
	else if (*L1 == NULL && *L2 != NULL) {//*L1为空，*L2非空
		L = *L2;
		*L2 = (*L2)->Next;
	}
	else if (*L2 == NULL && *L1 != NULL) {//*L2非空，*L1为空
		L = *L1;
		*L1 = (*L1)->Next;
	}
	else {//*L1和*L2都非空
		if ((*L1)->Data < (*L2)->Data) {
			L = *L1;
			*L1 = (*L1)->Next;
		}
		else if ((*L1)->Data > (*L2)->Data) {
			L = *L2;
			*L2 = (*L2)->Next;
		}
		else {//*L1和*L2表头元素相同，删去*L2中表头
			L = *L1;
			*L1 = (*L1)->Next;
			P2 = *L2;//P2指向要释放的空间
			*L2 = (*L2)->Next;
			free(P2);
		}
	}
	P1 = L;//P1指向新链表的尾节点
	while (*L1 != NULL && *L2 != NULL) {
		if ((*L1)->Data < (*L2)->Data) {//*L1的头结点加入新链表
			P1->Next = *L1;
			P1 = *L1;
			*L1 = (*L1)->Next;
		}
		else if ((*L1)->Data > (*L2)->Data) {//*L2的头结点加入新链表
			P1->Next = *L2;
			P1 = *L2;
			*L2 = (*L2)->Next;
		}
		else {//*L1和*L2有相同节点,删除*L2中的重复节点
			P2 = *L2;
			*L2 = (*L2)->Next;
			free(P2);
		}
	}
	while (*L1 != NULL) {//将*L1中剩余节点加入新链表
		P1->Next = *L1;
		P1 = *L1;
		*L1 = (*L1)->Next;
	}
	while (*L2 != NULL) {//将*L2中剩余节点加入新链表
		P1->Next = *L2;
		P1 = *L2;
		*L2 = (*L2)->Next;
	}
	return L;
}
//2.6  返回指向链表中值最大的结点的指针
struct LNode* FindMax(struct LNode* L) {
	ElemType max;
	struct LNode* maxNode;
	if (L != NULL) {
		max = L->Data;
		maxNode = L;
	}
	else
		return NULL;
	while (L->Next != NULL) {
		L = L->Next;
		if (L->Data > max) {
			max = L->Data;
			maxNode = L;
		}
	}
	return maxNode;
}

//2.7  逆转链表指针方向，完成操作后原链表头结点即是新链表的头结点
void Reverse(struct LNode** L) {
	struct LNode *Head = *L;//Head保存链表头
	struct LNode *P1, *P2;//P2指向要改变结点，P1指向改变后P2要指向的结点，即P2的前驱节点
	while ((*L)->Next != NULL) {//循环结束后L指向链表尾，即翻转后的链表头
		*L = (*L)->Next;
	}
	P2 = *L;//先改变链表尾节点
	P1 = Head;
	while (P2 != Head) {//翻转操作未进行到表头
		if (P1->Next == P2) {//进行翻转
			P2->Next = P1;
			P2 = P1;
			P1 = Head;
		}
		else
			P1 = P1->Next;
	}
	Head->Next = NULL;
}


typedef int SElemType;
struct SNode {
	SElemType data;
	struct SNode *next;
};
typedef struct SNode* LStack;
void Push(LStack &S, SElemType x) {
	LStack newP = (LStack)malloc(sizeof(struct SNode));
	if (newP == NULL) {
		cout << "动态内存不足" << endl;
		exit(1);
	}
	newP->data = x;
	newP->next = S;
	S = newP;
}
SElemType Pop(LStack &S) {
	if (S == NULL) {
		cout << "栈空，无法删除" << endl;
		exit(1);
	}
	SElemType temp = S->data;
	LStack P = S;
	S = S->next;
	free(P);
	return temp;
}
bool IsEmpty(LStack S) {
	return S == NULL ? true : false;
}

//3.3
void Chapter3_3() {
	struct SNode *S = NULL;
	int x;
	while (1) {
		printf("请输入数据:\n");
		scanf("%d", &x);
		if (x != -1) {
			Push(S, x);
			printf("入栈完成\n");
		}
		else {
			if (IsEmpty(S)) {
				printf("栈空，无元素可出栈！\n");
				printf("请重新输入数据!\n");
			}
			else {
				printf("%d\n", Pop(S));
				printf("出栈完成！");
			}
		}
	}
}


//3.5
bool Chapter3_5(char a[]) {
	int count = 0;
	int n = strlen(a);
	for (int i = 0; i < n; i++) {
		if (a[i] == 'I')
			count++;
		else 
			count--;
		if (count < 0)
			return false;
	}
	return true;
}


//3.6
void MakeNULL(struct LNode **L) {
	struct LNode *P;
	if ((*L)->Next == *L)//只有一个头结点的空链表
		return;
	*L = (*L)->Next;//指向头结点
	P = (*L)->Next;//指向头结点后面的元素
	while ((*L)->Next != *L) {
		(*L)->Next = P->Next;
		free(P);
		P = (*L)->Next;
	}
}
bool IsEmpty(struct LNode *L) {
	return L->Next == L ? true : false;
}
void EnQueue(struct LNode **L, ElemType x) {
	struct LNode* NewP = (struct LNode*)malloc(sizeof(struct LNode));
	if (NewP == NULL) {
		printf("动态内存不足,程序退出\n");
		exit(1);
	}
	NewP->Data = x;
	NewP->Next = (*L)->Next;//入队节点的指针域指向头结点
	(*L)->Next = NewP;//原队尾节点的指针域指向新入队接点
	*L = NewP;//*L指向队尾节点
}
ElemType DeQueue(struct LNode **L) {
	struct LNode *P1, *P2;
	ElemType temp;
	if ((*L)->Next == *L) {
		printf("队列为空，无法出队\n");
		exit(1);
	}
	P1 = (*L)->Next;//指向头结点
	P2 = P1->Next;//指向要出队的结点
	P1->Next = P2->Next;
	temp = P2->Data;
	free(P2);
	if (P1->Next == P1)//若出队一个节点后队列为空，令*L指向头结点
		*L = P1;
	return temp;
}


int main() {
	Chapter3_3();
	return 0;
}