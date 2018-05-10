#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void IsInsertion(int* V, int* W, int N);
void IsMerge(int* V, int* W, int N);
void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd);
void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length);
int IsEqual(int* V, int* W, int N);
void PrintNext(int*V, int N);
void Swap(int* a, int* b);


int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	int A[N],B[N],C[N];

	for(int i = 0; i < N; i++)
		scanf("%d", &A[i]);
	for(int i = 0; i < N; i++){
		B[i] = A[i];
		scanf("%d", &C[i]);
	}

	IsInsertion(A,C,N);
	IsMerge(B,C,N);

	return 0;
}

void Swap(int* a, int* b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}

void IsInsertion(int* V, int* W, int N)
{
	int P, i;
	ElementType Tmp;
	int flag = 0;

	for(P = 1; P < N; P++){
		Tmp = V[P];
		for (i = P; i > 0 && V[i-1] > Tmp; i--)
			V[i] = V[i-1];
		V[i] = Tmp;

		if(flag == 1){
			printf("Insertion Sort\n");
			PrintNext(V,N);
			break;
		}

		if(IsEqual(V,W,N))
			flag = 1;
	}
}

void IsMerge(int* V, int* W, int N)
{
	int length;
	ElementType* TmpA = (ElementType*)malloc(sizeof(ElementType) * N);

	length = 1;
	int flag1, flag2;
	flag2 = flag1 = 0;
	if(TmpA != NULL){
		while(length < N){
			Merge_pass(V, TmpA, N, length);
			if(flag2 == 1){
				printf("Merge Sort\n");
				PrintNext(TmpA,N);
				break;
			}
			if(IsEqual(TmpA, W, N))
				flag1 = 1;

			length *= 2;

			Merge_pass(TmpA, V, N, length);
			if(flag1 == 1){
				printf("Merge Sort\n");
				PrintNext(V,N);
				break;
			}
			if(IsEqual(V, W, N))
				flag2 = 1;

			length *= 2;
		}
		free(TmpA);
	}
	else
		printf("空间不足");
}

void Merge(ElementType A[], ElementType TmpA[], int L, int R, int RightEnd)
{
	int LeftEnd, NumElements, Tmp;
	// int i;

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
}

void Merge_pass(ElementType A[], ElementType TmpA[], int N, int length)
{
	int i, j;
	for(i = 0; i <= N - 2*length; i += 2*length)
		Merge(A, TmpA, i, i+length, i+length*2-1);
	if(i + length < N)
		Merge(A, TmpA, i, i+length, N-1);
	else
		for(j = i; j < N; j++)
			TmpA[j] = A[j];
}


int IsEqual(int* V, int* W, int N)
{
	int i, flag;
	flag = 1;
	i = 0;
	while(i < N){
		if(V[i] != W[i]){
			flag = 0;
			break;
		}
		i++;
	}
	return flag;
}

void PrintNext(int*V, int N)
{
	for(int i = 0; i < N; i++){
		if(i < N-1)
			printf("%d ", V[i]);
		else
			printf("%d", V[i]);
	}
}

