#pragma once
//交换
template <typename T>
void Swap(T *a, T *b) {
	if (a != b) {
		T temp = *a;
		*a = *b;
		*b = temp;
	}
}
template <typename T>
void Swap(T &a, T &b) {
	if (&a != &b) {
		T temp = a;
		a = b;
		b = temp;
	}
}


//冒泡排序(稳定)
template <typename T>
void Bubble_Sort(T A[], int N) {
	int i, j, flag;
	for (i = N - 1; i > 0; i--) {
		flag = 0;
		for (j = 0; j < i; j++) {
			if (A[j] > A[j + 1]) {
				Swap(A[j], A[j + 1]);
				flag = 1;
			}
		}
		if (flag == 0)//没有进行交换，说明已经有序
			break;
	}
}


//选择排序(不稳定)
template <typename T>
void Select_Sort(T A[], int N) {
	int i, j, t;
	for (i = 0; i < N - 1; i++) {
		t = i;
		for (j = i + 1; j < N; j++) {
			if (A[t] > A[j])
				t = j;
		}
		Swap(A[i], A[t]);
	}
}


//插入排序(稳定)
template <typename T>
void Insert_Sort(T A[], int N) {
	int i, j;
	T temp;
	for (i = 1; i < N; i++) {
		temp = A[i];
		for (j = i; j >= 1 && A[j - 1] > temp; j--)
			A[j] = A[j - 1];
		A[j] = temp;
	}
}


//希尔排序(不稳定)
template <typename T>
void Shell_Sort(T A[], int N) {
	int si, D, i, j;
	T temp;
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };//Sedgewick增量序列
	for (si = 0; Sedgewick[si] >= N; si++) {}//增量初始值不能大于N
	for (D = Sedgewick[si]; D > 0; D = Sedgewick[++si]) {
		for (i = D; i < N; i++) {
			temp = A[i];
			for (j = i; j >= D && A[j - D] > temp; j -= D)
				A[j] = A[j - D];
			A[j] = temp;
		}
	}
}


//堆排序(不稳定)
template <typename T>
void PerDown(T A[], int s, int N) {
	T temp = A[s];
	int child = 2 * s + 1;
	while (child < N) {
		if (child + 1 < N && A[child] < A[child + 1])
			child++;
		if (A[child] > temp) {
			A[s] = A[child];
			s = child;
			child = 2 * s + 1;
		}
		else
			break;
	}
	A[s] = temp;
}
template <typename T>
void Heap_Sort(T A[], int N) {
	int i, j;
	for (i = N / 2 - 1; i >= 0; i--)
		PerDown(A, i, N);
	for (j = N - 1; j > 0; j--) {
		Swap(A[j], A[0]);
		PerDown(A, 0, j);
	}
}


//快速排序(不稳定)
template <typename T>
void QSort1(T A[], int begin, int end) {
	int left = begin + 1;
	int right = end;
	while (1) {
		while (A[left] < A[begin]) left++;
		while (A[right] > A[begin]) right--;
		if (left < right)
			Swap(A[left], A[right]);
		else break;
	}
	Swap(A[begin], A[right]);
	if (begin < right - 1)//当前区间超过一个元素时执行
		QSort1(A, begin, right - 1);
	if (right + 1 < end)//当前区间超过一个元素时执行
		QSort1(A, right + 1, end);
}
template <typename T>
void Quick_Sort1(T A[], int N) {
	QSort1(A, 0, N - 1);
}

template <typename T>
T Median(T A[], int L, int R) {//使A[L]<A[Mid]<A[R],并交换A[Mid],A[R-1]
	int Mid = L + (R - L) / 2;//防止L+R过大溢出
	if (A[L] > A[Mid])
		Swap(A[L], A[Mid]);
	if (A[L] > A[R])
		Swap(A[L], A[R]);
	if (A[Mid] > A[R])
		Swap(A[Mid], A[R]);
	Swap(A[Mid], A[R - 1]);
	return A[R - 1];
}
template <typename T>
void QSort(T A[], int L, int R) {
	if (R - L > 0) {//有超过一个元素时才执行
		T Pivot = Median(A, L, R);//使两个或三个元素有序
		int low = L;
		int high = R - 1;
		if (R - L > 2) {//有超过三个元素时才执行
			while (1) {
				while (A[++low] < Pivot);
				while (A[--high] > Pivot);
				if (low < high)
					Swap(A[low], A[high]);
				else
					break;
			}
			Swap(A[low], A[R - 1]);
			QSort(A, L, low - 1);
			QSort(A, low + 1, R);
		}
	}
}
template <typename T>
void Quick_Sort(T A[], int N) {//统一接口
	QSort(A, 0, N - 1);
}


//归并排序(稳定)
//递归实现
template <typename T>
void Merge1(T A[], T TmpA[], int L, int R, int RE) {
	int LE = R - 1;
	int Tmp = L;
	int Num = RE - L + 1;
	while (L <= LE && R <= RE) {
		if (A[L] <= A[R])  TmpA[Tmp++] = A[L++];
		else               TmpA[Tmp++] = A[R++];
	}
	while (L <= LE)   TmpA[Tmp++] = A[L++];
	while (R <= RE)  TmpA[Tmp++] = A[R++];
	for (int i = 0; i < Num; i++)
		A[RE] = TmpA[RE--];
}
template <typename T>
void MSort(T A[], T TmpA[], int L, int RE) {
	if (L < RE) {
		int Mid = (L + RE) / 2;
		MSort(A, TmpA, L, Mid);//递归使左边有序
		MSort(A, TmpA, Mid + 1, RE);//递归使右边有序
		Merge1(A, TmpA, L, Mid + 1, RE);//合并两段有序
	}
}
template <typename T>
void Merge_Sort1(T A[], int N) {
	T *TmpA = new T[N];
	MSort(A, TmpA, 0, N - 1);
	delete[]TmpA;
}
//非递归实现
template <typename T>
void Merge2(T A[], T TmpA[], int L, int R, int RE) {
	int LE = R - 1;
	int Tmp = L;
	while (L <= LE && R <= RE) {
		if (A[L] <= A[R])  TmpA[Tmp++] = A[L++];
		else               TmpA[Tmp++] = A[R++];
	}
	while (L <= LE)   TmpA[Tmp++] = A[L++];
	while (R <= RE)  TmpA[Tmp++] = A[R++];
}
template <typename T>
void Merge_pass(T A[], T TmpA[], int N, int Length) {
	//一趟归并含Length个元素的子序列按长为2*Length的段有序
	int i, j;
	for (i = 0; i <= N - 2 * Length; i += 2 * Length)
		Merge2(A, TmpA, i, i + Length, i + 2 * Length - 1);
	if (i + Length < N)//剩余部分还有超过Length个元素
		Merge2(A, TmpA, i, i + Length, N - 1);
	else//剩余部分不足Length个元素
		for (j = i; j < N; j++)
			TmpA[j] = A[j];
}
template <typename T>
void Merge_Sort2(T A[], int N) {
	int Length = 1;
	T *TmpA = new T[N];
	while (Length < N) {
		Merge_pass(A, TmpA, N, Length);
		Length *= 2;
		Merge_pass(TmpA, A, N, Length);
		Length *= 2;
	}
	delete[]TmpA;
}


//表排序
template <typename T>
void Table_Sort(T A[], int N) {
	int i, j, temp;
	int *table = new int[N];
	for (i = 0; i < N; i++)
		table[i] = i;
	for (i = 1; i < N; i++) {
		temp = table[i];
		for (j = i; j >= 1 && A[table[j - 1]] > A[temp]; j--)
			table[j] = table[j - 1];
		table[j] = temp;
	}
	T *B = new T[N];
	for (i = 0; i < N; i++)
		B[i] = A[table[i]];
	for (i = 0; i < N; i++)
		A[i] = B[i];
	delete[]table;
	delete[]B;
}


//基数排序,桶排序
//次位排序
const int Radix = 10;
const int MaxDigit = 3;
template <typename T>
struct Node {
	T Data;
	Node<T> *Next;
	Node<T>(T data, Node<T> *next) {
		Data = data;
		Next = next;
	}
};
template <typename T>
struct Bucket {
	Node<T> *Head;
	Node<T> *Tail;
};
int GetDigit(int x, int d) {
	int val;
	while (d--) {
		val = x % Radix;
		x = x / Radix;
	}
	return val;
}
template <typename T>
void Bucket_Sort(T A[], int N) {
	int i, D, d;
	Bucket<T> B[Radix];
	Node<T> *Tp, *list = NULL;
	for (i = 0; i < Radix; i++)//初始化Radix个空桶
		B[i].Head = B[i].Tail = NULL;
	for (i = 0; i < N; ++i) {//把A[]中的元素导入list
		Tp = new Node<T>(A[i], list);
		list = Tp;
	}
	for (D = 1; D <= MaxDigit; D++) {
		while (list != NULL) {//把list中元素放入各个桶中
			d = GetDigit(list->Data, D);//P指向的元素放到哪个桶
			Tp = list;
			list = list->Next;
			Tp->Next = NULL;
			if (B[d].Head == NULL)
				B[d].Head = B[d].Tail = Tp;
			else {
				B[d].Tail->Next = Tp;
				B[d].Tail = Tp;
			}
		}
		for (i = Radix - 1; i >= 0; i--) {//从后往前收集桶中元素
			if (B[i].Head != NULL) {
				B[i].Tail->Next = list;
				list = B[i].Head;
				B[i].Head = B[i].Tail = NULL;//清空桶
			}
		}
	}
	for (i = 0; i < N; i++) {
		Tp = list;
		list = list->Next;
		A[i] = Tp->Data;
		delete Tp;
	}
}