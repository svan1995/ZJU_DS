#include <stdio.h>
#define MaxTree 10
#define ElementType int
#define Tree int
#define Null -1

struct TreeNode
{
    ElementType Data;
    Tree Left;
    Tree Right;
}T1[MaxTree];

Tree BulidTree(struct TreeNode* T);
void PrintLeaves(Tree head);

int main(int argc, char const *argv[])
{
    Tree R1;
    R1 = BulidTree(T1);
    // printf("%d",T1[3].Data);
    PrintLeaves(R1);
    return 0;
}

Tree BulidTree(struct TreeNode T[])
{
    int i,N,Root;
    char cl,cr;
    scanf("%d",&N);
    int check[N];
    Root = Null;
    if(N){
        for(i=0;i<N;i++)
            check[i] = 0;
            // T[i].Data = 3;
        for(i=0;i<N;i++){
            T[i].Data = i;
            scanf("\n%c %c",&cl,&cr);
            if(cl != '-'){
                T[i].Left = cl - '0';
                check[T[i].Left] = 1;
            }
            else
                T[i].Left = Null;
            if(cr != '-'){
                T[i].Right = cr - '0';
                check[T[i].Right] = 1;
            }
            else
                T[i].Right = Null;        
        }
        for(i=0;i<N;i++){
            if(!check[i])
                break;
        }
        Root = i;
    }
    return Root;
}

void PrintLeaves(Tree head)
{
    int queue[MaxTree];
    int front = 0,rear =0;
    int flag = 0;
    int i;
    queue[rear++] = head;
    while(rear - front){
        i = queue[front++];
        if((T1[i].Left == Null) &&(T1[i].Right == Null)){
            if(flag){
                printf(" ");

            }
            printf("%d",T1[i].Data);
            flag++;
        }
        if(T1[i].Left != Null)
            queue[rear++] = T1[i].Left;
        if(T1[i].Right != Null)
            queue[rear++] = T1[i].Right;
    }
}