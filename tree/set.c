#define MAXN 1000
typedef int ElementType;
typedef int SetName;
typedef ElementType SetType[MAXN];

SetName Find(SetType S, ElementType X)
{
    for(;S[X]>0;X=S[X]);
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