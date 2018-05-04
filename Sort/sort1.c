void BubbleSort(ElementType A[], int N)
{
	int P, i;
	bool flag;

	for(P = N-1, P >= 0, P--){
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