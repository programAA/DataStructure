#pragma once
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
		if (flag == 0)//û�н��н�����˵���Ѿ�����
			break;
	}
}

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

template <typename T>
void Shell_Sort(T A[], int N) {
	int si, D, i, j;
	T temp;
	int Sedgewick[] = { 929,505,209,109,41,19,5,1,0 };//Sedgewick��������
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

template <typename T>
T Median(T A[], int L, int R) {//ʹA[L]<A[Mid]<A[R],������A[Mid],A[R-1]
	int Mid = (L + R) / 2;
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
	if (R - L > 0) {//�г���һ��Ԫ��ʱ��ִ��
		T Pivot = Median(A, L, R);//ʹ����������Ԫ������
		int low = L;
		int high = R - 1;
		if (R - L > 2) {//�г�������Ԫ��ʱ��ִ��
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
void Quick_Sort(T A[], int N) {//ͳһ�ӿ�
	QSort(A, 0, N - 1);
}

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
	for (int i = 0; i < Num; i++, RE--)
		A[RE] = TmpA[RE];
}
template <typename T>
void MSort(T A[], T TmpA[], int L, int RE) {
	if (L < RE) {
		int Mid = (L + RE) / 2;
		MSort(A, TmpA, L, Mid);//�ݹ�ʹ�������
		MSort(A, TmpA, Mid + 1, RE);//�ݹ�ʹ�ұ�����
		Merge1(A, TmpA, L, Mid + 1, RE);//�ϲ���������
	}
}
template <typename T>
void Merge_Sort1(T A[], int N) {
	T *TmpA = new T[N];
	MSort(A, TmpA, 0, N - 1);
	delete[]TmpA;
}
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
	//һ�˹鲢��Length��Ԫ�ص������а���Ϊ2*Length�Ķ�����
	int i, j;
	for (i = 0; i <= N - 2 * Length; i += 2 * Length)
		Merge2(A, TmpA, i, i + Length, i + 2 * Length - 1);
	if (i + Length < N)//ʣ�ಿ�ֻ��г���Length��Ԫ��
		Merge2(A, TmpA, i, i + Length, N - 1);
	else//ʣ�ಿ�ֲ���Length��Ԫ��
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

