#include <stdio.h>
#include <stdlib.h>

typedef int ElementType;

void IsInsertion(int* V, int* W, int N);
void IsHeap(int* V, int* W, int N);
void PercDown(ElementType A[], int p, int N);
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
	IsHeap(B,C,N);

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

void IsHeap(int* V, int* W, int N)
{
	int i;
	int flag = 0;
	for(i = N/2 - 1; i >= 0; i--)
		PercDown(V, i, N);

	for(i = N-1; i > 0; i--){
		Swap(&V[0], &V[i]);
		PercDown(V, 0, i);

		if(flag == 1){
			printf("Heap Sort\n");
			PrintNext(V,N);
			break;
		}
		if(IsEqual(V,W,N))
			flag = 1;
		
	}

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