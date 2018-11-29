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
//2.1  �ϲ�����������������ָ���������ͷ����ָ��
struct LNode* Merge(struct LNode** L1, struct LNode** L2) {
	struct LNode  *L, *P1, *P2;//L�����������ͷ���
	if (*L1 == NULL && *L2 == NULL)//*L1��*L2��Ϊ��
		return NULL;
	else if (*L1 == NULL && *L2 != NULL) {//*L1Ϊ�գ�*L2�ǿ�
		L = *L2;
		*L2 = (*L2)->Next;
	}
	else if (*L2 == NULL && *L1 != NULL) {//*L2�ǿգ�*L1Ϊ��
		L = *L1;
		*L1 = (*L1)->Next;
	}
	else {//*L1��*L2���ǿ�
		if ((*L1)->Data < (*L2)->Data) {
			L = *L1;
			*L1 = (*L1)->Next;
		}
		else if ((*L1)->Data > (*L2)->Data) {
			L = *L2;
			*L2 = (*L2)->Next;
		}
		else {//*L1��*L2��ͷԪ����ͬ��ɾȥ*L2�б�ͷ
			L = *L1;
			*L1 = (*L1)->Next;
			P2 = *L2;//P2ָ��Ҫ�ͷŵĿռ�
			*L2 = (*L2)->Next;
			free(P2);
		}
	}
	P1 = L;//P1ָ���������β�ڵ�
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
	while (*L1 != NULL) {//��*L1��ʣ��ڵ����������
		P1->Next = *L1;
		P1 = *L1;
		*L1 = (*L1)->Next;
	}
	while (*L2 != NULL) {//��*L2��ʣ��ڵ����������
		P1->Next = *L2;
		P1 = *L2;
		*L2 = (*L2)->Next;
	}
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

//2.7  ��ת����ָ�뷽����ɲ�����ԭ����ͷ��㼴���������ͷ���
void Reverse(struct LNode** L) {
	struct LNode *Head = *L;//Head��������ͷ
	struct LNode *P1, *P2;//P2ָ��Ҫ�ı��㣬P1ָ��ı��P2Ҫָ��Ľ�㣬��P2��ǰ���ڵ�
	while ((*L)->Next != NULL) {//ѭ��������Lָ������β������ת�������ͷ
		*L = (*L)->Next;
	}
	P2 = *L;//�ȸı�����β�ڵ�
	P1 = Head;
	while (P2 != Head) {//��ת����δ���е���ͷ
		if (P1->Next == P2) {//���з�ת
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
		cout << "��̬�ڴ治��" << endl;
		exit(1);
	}
	newP->data = x;
	newP->next = S;
	S = newP;
}
SElemType Pop(LStack &S) {
	if (S == NULL) {
		cout << "ջ�գ��޷�ɾ��" << endl;
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
	Chapter3_3();
	return 0;
}