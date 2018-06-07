#include <stdio.h>
#include <stdlib.h>


int getLength(char* pre, char* mid, int len);
int max(int a, int b);
int main(int argc, char const *argv[])
{
	int N;
	scanf("%d",&N);
	char pre[N], mid[N];

	for(int i = 0; i < N; i++)
		scanf("%c",&pre[i]);
	for(int i = 0; i < N; i++)
		scanf("%c",&mid[i]);
	int H;
	H = getLength(pre,mid,N);
	printf("%d\n", H);
	return 0;
}

int getLength(char* pre, char* mid, int len){
	if(len <= 0)
		return 0;
	if(len == 1)
		return 1;
	int left_len = 0; 
	int right_len = 0;
	int i = 0;
	while(mid[i] != pre[0] ){
		i++;
		left_len++;
	}
	right_len = len - left_len -1;
	return max(getLength(pre+1,mid,left_len),getLength(pre +1 +left_len, mid+1+left_len, right_len)) + 1;
}

int max(int a, int b){
	return a>b ? a:b; 
}