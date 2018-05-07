void BubbleSort(ElementType A[], int N)
{
	int P, i;
	bool flag;

	for(P = N-1; P >= 0; P--){
		flag = false;
		for(i = 0；i < P; i++){
			if(A[i] > A[i+1]){
				Swap(&A[i], &A[i+1]);
				flag = true;
			}
		}
		if(flag == false)
			break;
	}
}

void InsertionSort(ElementType A[], int N)
{
	int P, i;
	ElementType Tmp;

	for(P = 1; P < N; P++){
		Tmp = A[P];
		for (i = P; i > 0 && A[i-1] > Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
	}
}

void ShellSort(ElementType A[], int N)
{
	int Si, D, P, i;
	ElementType Tmp;
	int Sedgewick[] = {2161,929, 505, 209, 109, 41, 19, 5, 1, 0};

	for(Si = 0; Sedgewick[Si] >= N; Si++)
		;
	for(D = Sedgewick[Si]; D > 0; D = Sedgewick[++Si])
		for(P = D; P < N; P++){
			Tmp = A[P];
			for(i = P; i >= D && A[i-D] > Tmp; i- = D)
				A[i] = A[i-D];
			A[i] = Tmp;
		}
}

void SimpleSelectionSort(ElementType A[], int N)
{
	int i, j, min;

	for(i = 0; i < N-1; i++){
		min = i;
		for(j = i+1; j < N; j++)
			if(A[j] < A[min])
				min = j;
		Swap(&A[i], &A[min]);
	}
}

void PercDown(ElementType A[], int p, int N)
{
	int Parent, Child;
	ElementType X;

	X = A[p];
	for(Parent = p; (Parent * 2 +1) < N; Parent = Child){
		Child = Parent * 2 + 1;
		if((Child != N-1) && (A[Child] < A[Child+1]))
			Child++;
		if(X >= A[Child])
			break;
		else
			A[Parent] = A[Child];
	}
	A[Parent] = X;
}

void HeapSort(ElementType A[], int N)
{
	int i;
	for(i = N/2 - 1; i >= 0; i--)
		PercDown(A, i, N);
	for(i = N-1; i > 0; i--){
		Swap(&A[0], &A[i]);
		PercDown(A, 0, i);
	}
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, NumElements, Tmp;
	int i;

	LeftEnd = R-1;
	Tmp = L;
	NumElements = RightEnd - L + 1;

	while(L <= LeftEnd && R <= RightEnd){
		if(A[L] <= A[R])
			TmpA[Tmp++] = A[L++];
		else
			TmpA[Tmp++] = A[R++];
	}

	while(L <= LeftEnd)
		TmpA[Tmp++] = A[L++];
	while(R <= RightEnd)
		TmpA[Tmp++] = A[R++];

// ***对于非递归归并排序，不需要***
	// for (int i = 0; i < NumElements; i++,RightEnd--)
	// 	A[RightEnd] = TmpA[RightEnd];
}

void Msort(ElementType A[], ElementType TmpA[], int L, int RightEnd)
{
	int Center;

	if(L < RightEnd){
		Center = (L + RightEnd) / 2;
		Msort(A, TmpA, L, Center);
		Msort(A, TmpA, Center + 1, RightEnd);
		Merge(A, TmpA, L, Center + 1, RightEnd);
	}
}

void MergeSort(ElementType A[], int N)
{
	ElementType* TmpA;
	TmpA = (ElementType*)malloc(sizeof(ElementType) * N);

	if(TmpA != NULL){
		Msort(A, TmpA, 0, N-1);
		free(TmpA);
	}
	else printf("空间不足\n");
}

void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i, j;
	for(i = 0; i <= N - 2*length, i += 2*length)
		Merge(A, TmpA, i, i+length, i+length*2-1);
	if(i + length < N)
		Merge(A, TmpA, i, i+length, N-1)
	else
		for(j = i; j < N; j++)
			TmpA[j] = A[j];
}

void Merge_Sort(ElementType A[], int N)
{
	int length;
	ElementType* TmpA = (ElementType*)malloc(sizeof(ElementType) * N);

	length = 1;
	if(TmpA != NULL){
		while(length < N){
			Merge_pass(A, TmpA, N, length);
			length *= 2;
			Merge_pass(TmpA, A, N, length);
			length *= 2;
		}
		free(TmpA);
	}
	else
		printf("空间不足");
}