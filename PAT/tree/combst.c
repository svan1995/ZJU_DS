#include <stdio.h>

int B[1005];
int j = 0;
void CreateBST(int root,int N,int* A);

int main(int argc, char const *argv[])
{
    int i,j,N,tmp;
    scanf("%d",&N);
    int A[N];
    for(i = 0;i < N;i++){
        scanf("%d",&A[i]);
    }
    for(i = 0;i<N;i++){
        for(j = i+1;j<N;j++){
            if(A[i] > A[j]){
                tmp = A[j];
                A[j] = A[i];
                A[i] = tmp;
            }
        }
    }
    // for(i = 0;i<N;i++)
    //     printf("%d\n",A[i]);
    CreateBST(1,N,A);
    printf("%d",B[1]);
    for(i = 2;i<=N;i++)
        printf(" %d",B[i]);

    return 0;
}

void CreateBST(int root,int N,int *A)
{
    if(root <= N){
        CreateBST(2*root,N,A);
        B[root] = A[j++];
        CreateBST(2*root+1,N,A);
    }
}