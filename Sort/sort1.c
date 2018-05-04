void BubbleSort(ElementType A[], int N)
{
	int P, i;
	bool flag;

	for(P = N-1; P >= 0; P--){
		flag = false;
		for(i = 0；i < P; i++){
			if(A[i] > A[i+1]){
				swap(&A[i], &A[i+1]);
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
		Tmp = A[p];
		for (int i = P; i > 0 && A[i-1] > Tmp; i--)
			A[i] = A[i-1];
		A[i] = Tmp;
	}
}

