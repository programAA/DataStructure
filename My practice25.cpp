#include <iostream>
//#include "CStack.h"
//#include "CQueue.h"

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
//2.1  �ϲ�����������������ָ���������ͷ����ָ��
struct LNode* Merge(struct LNode** L1, struct LNode** L2) {
	if (*L1 == NULL && *L2 == NULL)
		return NULL;
	struct LNode *L = (struct LNode *)malloc(sizeof(struct LNode));
	struct LNode *P1, *P2;//P1ָ���������β�ڵ�,P2ָ��Ԫ���ظ�ʱҪɾ���Ľڵ�
	P1 = L;
	while (*L1 != NULL && *L2 != NULL) {
		if ((*L1)->Data < (*L2)->Data) {//*L1��ͷ������������
			P1->Next = *L1;
			P1 = *L1;
			*L1 = (*L1)->Next;
		}
		else if ((*L1)->Data > (*L2)->Data) {//*L2��ͷ������������
			P1->Next = *L2;
			P1 = *L2;
			*L2 = (*L2)->Next;
		}
		else {//*L1��*L2����ͬ�ڵ�,ɾ��*L2�е��ظ��ڵ�
			P2 = *L2;
			*L2 = (*L2)->Next;
			free(P2);
		}
	}
	if (*L1 != NULL) {
		P1->Next = *L1;
		*L1 = NULL;
	}
	if (*L2 != NULL) {
		P1->Next = *L2;
		*L2 = NULL;
	}
	P2 = L;//ɾ�������ͷ���
	L = L->Next;
	free(P2);
	return L;
}
//2.6  ����ָ��������ֵ���Ľ���ָ��
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

//2.7  ��ת����ָ�뷽����ɲ�����ԭ����ͷָ�뼴���������ͷָ��
void Reverse(struct LNode** L) {
	if (*L == NULL)
		return;
	struct LNode *P1, *P2, *P3;//P2ָ��Ҫ�ı��㣬P1ָ��P2��ǰ����P3ָ��P2�ĺ��
	P1 = NULL;
	P2 = *L;//�ȸı�����β�ڵ�
	P3 = P2->Next;
	while (P3 != NULL) {
		P2->Next = P1;
		P1 = P2;
		P2 = P3;
		P3 = P3->Next;
	}
	P2->Next = P1;
	*L = P2;
}


typedef int SElemType;
struct SNode {
	SElemType data;
	struct SNode *next;
};
typedef struct SNode* Stack;
Stack InitStack() {
	return NULL;
}
void Push(Stack &S, SElemType x) {
	Stack newP = (Stack)malloc(sizeof(struct SNode));
	if (newP == NULL) {
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	newP->data = x;
	newP->next = S;
	S = newP;
}
SElemType Pop(Stack &S) {
	if (S == NULL) {
		cout << "ջ�գ��޷�ɾ��" << endl;
		exit(1);
	}
	SElemType temp = S->data;
	Stack P = S;
	S = S->next;
	free(P);
	return temp;
}
bool IsEmpty(Stack S) {
	return S == NULL ? true : false;
}

//3.3
void Chapter3_3(int n) {
	struct SNode *S = InitStack();
	int x;
	int count = 0;
	for (int i = 0; i < n; i++) {
		printf("����������:\n");
		scanf("%d", &x);
		if (x != -1) {
			Push(S, x);
			printf("��ջ���\n");
		}
		else {
			if (IsEmpty(S)) {
				printf("ջ�գ���Ԫ�ؿɳ�ջ��\n");
				printf("��������������!\n");
			}
			else {
				printf("%d\n", Pop(S));
				printf("��ջ��ɣ�");
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
	if ((*L)->Next == *L)//ֻ��һ��ͷ���Ŀ�����
		return;
	*L = (*L)->Next;//ָ��ͷ���
	P = (*L)->Next;//ָ��ͷ�������Ԫ��
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
		printf("��̬�ڴ治��,�����˳�\n");
		exit(1);
	}
	NewP->Data = x;
	NewP->Next = (*L)->Next;//��ӽڵ��ָ����ָ��ͷ���
	(*L)->Next = NewP;//ԭ��β�ڵ��ָ����ָ������ӽӵ�
	*L = NewP;//*Lָ���β�ڵ�
}
ElemType DeQueue(struct LNode **L) {
	struct LNode *P1, *P2;
	ElemType temp;
	if ((*L)->Next == *L) {
		printf("����Ϊ�գ��޷�����\n");
		exit(1);
	}
	P1 = (*L)->Next;//ָ��ͷ���
	P2 = P1->Next;//ָ��Ҫ���ӵĽ��
	P1->Next = P2->Next;
	temp = P2->Data;
	free(P2);
	if (P1->Next == P1)//������һ���ڵ�����Ϊ�գ���*Lָ��ͷ���
		*L = P1;
	return temp;
}

int main() {
	struct LNode *L1 = NULL;
	struct LNode *L2 = NULL;
	struct LNode *L;
	for (int i = 1; i < 10; i++) {
		InsertLast(&L1, i);
		InsertLast(&L2, i);
	}
	L = Merge(&L1, &L2);
	Traverse(L);
	Reverse(&L);
	Traverse(L);
	return 0;
}