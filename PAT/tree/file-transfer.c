#include <stdio.h>
#define MAXN 10000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];

SetName Find(SetType S, ElementType X)
{
    for(;S[X]>=0;X=S[X]);
    return X;
}

void Union(SetType S, SetName Root1, SetName Root2)
{
    S[Root2] = Root1;
}

void Union_opt(SetType S, SetName Root1, SetName Root2)
{
    if(S[Root2]<S[Root1]){
        S[Root2] += S[Root1];
        S[Root1] = Root2;
    }
    else{
        S[Root1] += S[Root2];
        S[Root2] = Root1;
    }
}


void Initialization(SetType S,int n);
void Input_connection(SetType S);
void Check_connection(SetType S);
void Check_network(SetType S,int n);

int main()
{
    SetType S;
    int n;
    char in;
    scanf("%d\n",&n);
    Initialization(S,n);
    do{
        scanf("%c",&in);
        switch(in){
            case 'I':
                Input_connection(S);
                break;
            case 'C':
                Check_connection(S);
                break;
            case 'S':
                Check_network(S,n);
                break;
        }
    }while(in != 'S');
    return 0;
}

void Initialization(SetType S,int n)
{
    for(int i = 0; i < n; i++)
        S[i] = -1;
}

void Input_connection(SetType S)
{
    int a,b;
    SetName Root1,Root2;
    scanf("%d %d",&a,&b);
    getchar();
    Root1 = Find(S,a-1);
    Root2 = Find(S,b-1);
    if(Root2 != Root1)
        Union_opt(S,Root1,Root2);
}


void Check_connection(SetType S)
{
    int a,b;
    SetName Root1,Root2;
    scanf("%d %d",&a,&b);
    getchar();
    Root1 = Find(S,a-1);
    Root2 = Find(S,b-1);
    if(Root2 == Root1)
        printf("yes\n");
    else
        printf("no\n");    
}

void Check_network(SetType S,int n)
{
    int i,count = 0;
    for(i=0;i<n;i++){
        if(S[i]<0)
            count++;
    }
    if(count == 1){
        printf("The network is connected.\n");
    }
    else{
        printf("There are %d components.\n", count);
    }

}