#pragma once
#include <cstdio>
#include <cstdlib>
typedef int ElemType;
void Swap(ElemType &a, ElemType &b)
{
	if (&a != &b) {
		ElemType temp;
		temp = a;
		a = b;
		b = temp;
	}
}
void Swap(ElemType *a, ElemType *b)
{
	if (a != b) {
		ElemType temp;
		temp = *a;
		*a = *b;
		*b = temp;
	}
}
//ð������
void Bubble_sort(ElemType A[], int N)
{
	int i, j, flag;
	for (i = N - 1; i>0; i--)
	{
		flag = 0;
		for (j = 0; j < i&&A[j]>A[j + 1]; j++) {
			Swap(A[j], A[j + 1]);
			flag = 1;
		}
		if (flag == 0)
			break;
	}
}
//��������
void Insert_sort(ElemType A[], int N)
{
	int i, j;
	ElemType temp;
	for (i = 1; i < N; i++)//ÿ��ѭ����������ȡһ����
	{
		temp = A[i];
		for (j = i; j > 0 && A[j - 1] > temp; j--)
			A[j] = A[j - 1];
		A[j] = temp;//������ʵ�λ��
	}
}
//ϣ������
void Shell_sort(ElemType A[], int N)
{
	int si, D, i, j;
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };//Sedgewick��������
	ElemType temp;
	for (si = 0; Sedgewick[si] >= N; si++) {}//������ʼֵ���ܴ���N
	for (D = Sedgewick[si]; D > 0; D = Sedgewick[++si]) {
		for (i = D; i < N; i++) {
			temp = A[i];
			for (j = i; j >= D && A[j - D] > temp; j -= D)
				A[j] = A[j - D];
			A[j] = temp;
		}
	}
}
//ѡ������
int FindMin(ElemType Data[], int i, int j)
{
	int t = i;
	for (; i < j&&Data[t]>Data[i + 1]; i++)
		t = i;
	return t;
}
void Select_Sort(ElemType A[], int N)
{
	int MinPosition;
	for (int i = 0; i < N - 1; i++) {
		MinPosition = FindMin(A, i, N - 1);//FindMin������������Data���±�i��N-1��Сֵ���±�
		Swap(A[i], A[MinPosition]);//������ǰ�±�Ϊi��ֵ����Сֵ
	}
}
void Select_sort(ElemType A[], int N)
{
	int i, j, t;
	for (i = 0; i < N - 1; i++) {
		t = i;//t������¼��С�����±�
		for (j = i + 1; j < N&&A[t]>A[j]; j++)
			t = j;
		Swap(A[i], A[t]);
	}
}
//������
void Percdown(ElemType A[], int s, int N)
{   //һ��ִ�к�ʹ��sΪ���ڵ�����������
	ElemType temp = A[s];
	int child = s * 2 + 1;
	while (child < N) {//child < N˵����ǰ���ڵ���ڶ��ӽڵ�
		if (child + 1 < N && A[child] < A[child + 1])
			child++;//child��ʾ���ӽڵ���ֵ�ϴ��һ��
		if (A[child] > A[s]) {
			A[s] = A[child];
			s = child;
			child = s * 2 + 1;
		}
		else break;
	}
	A[s] = temp;
}
void Heap_sort(ElemType A[], int N)
{
	int i;
	for (i = N / 2 - 1; i >= 0; i--)//��������
		Percdown(A, i, N);
	for (i = N - 1; i > 0; i--) {
		Swap(A[i], A[0]);
		Percdown(A, 0, i);
	}
}
//�鲢����
void Merge(ElemType A[], ElemType TmpA[], int L, int R, int RE)
{
	int i;
	int LE = R - 1;
	int ElemNum = RE - L + 1;
	int Tmp = L;//�������е���ʼ��
	while (L <= LE && R <= RE) {
		if (A[L] <= A[R]) TmpA[Tmp++] = A[L++];
		else TmpA[Tmp++] = A[R++];
	}
	while (L <= LE)
		TmpA[Tmp++] = A[L++];
	while (R <= RE)
		TmpA[Tmp++] = A[R++];
	for (i = 0; i < ElemNum; i++, RE--)//����������ݵ���A��
		A[RE] = TmpA[RE];
}
void Msort(ElemType A[], ElemType TmpA[], int L, int RE)
{
	if (L < RE) {
		int Center;
		Center = (L + RE) / 2;
		Msort(A, TmpA, L, Center);//�ݹ������
		Msort(A, TmpA, Center + 1, RE);//�ݹ����ұ�
		Merge(A, TmpA, L, Center + 1, RE);//�ϲ�������������
	}
}
void Merge_Sort(ElemType A[], int N)
{
	ElemType *TmpA = (ElemType *)malloc(N * sizeof(ElemType));
	if (TmpA != NULL) {
		Msort(A, TmpA, 0, N - 1);
		free(TmpA);
	}
	else printf("�ռ䲻��");
}
void Merge1(ElemType A[], ElemType TmpA[], int L, int R, int RE)
{//�ϲ�����ʹ�����������д���TmpA��
	int LE = R - 1;
	int ElemNum = RE - L + 1;
	int Tmp = L;//�������е���ʼ��
	while (L <= LE && R <= RE) {
		if (A[L] <= A[R]) TmpA[Tmp++] = A[L++];
		else TmpA[Tmp++] = A[R++];
	}
	while (L <= LE)
		TmpA[Tmp++] = A[L++];
	while (R <= RE)
		TmpA[Tmp++] = A[R++];
}
void Merge_pass(ElemType A[], ElemType TmpA[], int N, int length)
{//һ�˹鲢ʹ��length��Ԫ�ص������а�������
	int i, j;
	for (i = 0; i <= N - 2 * length; i += 2 * length)
		Merge1(A, TmpA, i, i + length, i + 2 * length - 1);
	if (i + length < N)
		Merge1(A, TmpA, i, i + length, N - 1);
	else
		for (j = i; j < N; j++)
			TmpA[j] = A[j];
}
void Merge_sort(ElemType A[], int N)
{
	int length = 1;
	ElemType *TmpA = (ElemType *)malloc(N * sizeof(ElemType));
	if (TmpA != NULL) {
		while (length < N) {
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else printf("�ռ䲻��");
}
//��������
ElemType Median3(ElemType A[], int L, int R)
{
	int Center = (L + R) / 2;
	if (A[L] > A[Center])
		Swap(A[L], A[Center]);
	if (A[Center] > A[R])
		Swap(A[Center], A[R]);
	if (A[L] > A[Center])
		Swap(A[L], A[Center]);
	Swap(A[Center], A[R - 1]);//����ȡ��Ԫ�浽�ұ�
	return A[R - 1];
}
void Quicksort(ElemType A[], int L, int R)
{
	int pivot, low, high;
	int Cutoff = 1000;//���ݶ���Cutoffʱ�ÿ������򣬷�����ѡ������
	if (Cutoff <= R - L) {
		pivot = Median3(A, L, R);
		low = L;
		high = R - 1;
		while (1) {
			while (A[++low] < pivot) {}
			while (A[--high] > pivot) {}
			if (low < high)
				Swap(A[low], A[high]);
			else break;
		}
		Swap(A[low], A[R - 1]);
		Quicksort(A, L, low - 1);
		Quicksort(A, low + 1, R);
	}
	else
		Insert_sort(A + L, R - L + 1);
}
void Quick_sort(ElemType A[], int N)//ͳһ�ӿ�
{
	Quicksort(A, 0, N - 1);
}
//������
void table_sort(ElemType A[], int N) {
	int *table = (int *)malloc(sizeof(int)*N);
	int i, j, temp;
	for (i = 0; i < N; ++i)
		table[i] = i;
	for (i = 1; i < N; ++i) {
		temp = table[i];
		for (j = i; j > 0 && A[table[j - 1]] > A[temp];j--)
			table[j] = table[j - 1];
		table[j] = temp;
	}
	for (i = 0; i < N; ++i) 
		printf("%d ", A[table[i]]);
}
//��������,Ͱ����
//��λ����
const int Radix = 10;
const int MaxDigit = 3;
typedef struct node *PtrToNode;
struct node {
	ElemType data;
	PtrToNode next;
};
typedef struct headnode {
	PtrToNode head, tail;
}Bucket[Radix];
int GetDigit(int x, int d) {
	int val;
	while (d--) {
		val = x % Radix;
		x = x / Radix;
	}
	return val;
}
void bucket_sort(ElemType A[],int N) {
	int i, D, d;
	Bucket B;
	PtrToNode tmp, p, list = NULL;
	for (i = 0; i < Radix; i++)
		B[i].head = B[i].tail = NULL;
	for (i = 0; i < N; ++i) {//��A[]�е�Ԫ�ص���list
		tmp = (PtrToNode)malloc(sizeof(struct node));
		tmp->data = A[i];
		tmp->next = list;
		list = tmp;
	}
	for (D = 1; D <= MaxDigit; D++) {
		p = list;
		while (p) {//��list��Ԫ�ط������Ͱ��
			d = GetDigit(p->data, D);//tmpָ���Ԫ�طŵ��ĸ�Ͱ
			tmp = p;
			p = p->next;
			tmp->next = NULL;
			if (B[d].head == NULL)
				B[d].head = B[d].tail = tmp;
			else {
				B[d].tail->next = tmp;
				B[d].tail = tmp;
			}
		}
		list = NULL;
		for (i = Radix - 1; i >= 0; i--) {//�Ӻ���ǰ�ռ�Ͱ��Ԫ��
			if (B[i].head != NULL) {
				B[i].tail->next = list;
				list = B[i].head;
				B[i].head = B[i].tail = NULL;//���Ͱ
			}
		}
	}
	for (i = 0; i < N; ++i) {
		tmp = list;
		list = list->next;
		A[i] = tmp->data;
		free(tmp);
	}
}