#include <stdio.h>

int main(int argc, char const *argv[])
{
	int A[51] = {0,};
	int N;
	int x;

	scanf("%d", &N);
	for(int i = 0; i < N; i++){
		scanf("%d",&x);
		A[x]++;
	}

	for(int i = 0; i < 51; i++){
		if(A[i] != 0)
			printf("%d:%d\n",i,A[i]);
	}


	return 0;
}