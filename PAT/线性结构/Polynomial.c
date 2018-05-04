#include <stdio.h>
#include <stdlib.h>


typedef struct PNode* PtrToPNode;
typedef PtrToPNode Polynomial;
struct PNode
{
    int cof;
    int exp;
    struct PNode* Next;
};

Polynomial ReadPoly();
Polynomial Add(Polynomial P1,Polynomial P2);
Polynomial Mul(Polynomial P1,Polynomial P2);
void Print(Polynomial P);

int main(){
    Polynomial P1,P2,P_Add,P_Mul;
    P1 = ReadPoly();
    P2 = ReadPoly();
    P_Add = Add(P1,P2);
    P_Mul = Mul(P1,P2); 
    Print(P_Mul);
    printf("\n");
    Print(P_Add);
    // Polynomial P_test;
    // P_test = ReadPoly();
    // Print(P_test);

    return 0;
}

Polynomial ReadPoly()
{
    int number,cof,exp;
    Polynomial P = (Polynomial)malloc(sizeof(struct PNode));
    P->Next = NULL;
    Polynomial Q = P;
    Polynomial R;
    scanf("%d",&number);
    for(int i = 0;i<number;i++){
        scanf("%d",&cof);
        scanf("%d",&exp);
        R = (Polynomial)malloc(sizeof(struct PNode));
        R->cof = cof;
        R->exp = exp;
        R->Next = NULL;
        Q->Next = R;
        Q = Q->Next;
    }
    return P;
    
    
}

Polynomial Add(Polynomial P1,Polynomial P2)
{
    Polynomial R1,R2;
    R1 = P1;
    R2 = P2;
    Polynomial P = (Polynomial)malloc(sizeof(struct PNode));
    Polynomial Q,Tmp;
    P->Next = NULL;
    Q = P;

    while(R1->Next && R2->Next){
        Tmp = (Polynomial)malloc(sizeof(struct PNode));
        Tmp->Next = NULL;
        if(R1->Next->exp == R2->Next->exp){
            Tmp->exp = R1->Next->exp;
            Tmp->cof = R1->Next->cof + R2->Next->cof; 
            R1 = R1->Next;
            R2 = R2->Next;
        }
        else if(R1->Next->exp > R2->Next->exp){
            Tmp->exp = R1->Next->exp;
            Tmp->cof = R1->Next->cof;
            R1 = R1->Next;
        }
        else{
            Tmp->exp = R2->Next->exp;
            Tmp->cof = R2->Next->cof;
            R2 = R2->Next;
        }
        if(Tmp->cof){
            Q->Next = Tmp;
            Q = Q->Next;
        }
    }
    while(R1->Next){
        Tmp = (Polynomial)malloc(sizeof(struct PNode));
        Tmp->Next = NULL;
        Tmp->exp = R1->Next->exp;
        Tmp->cof = R1->Next->cof;
        R1 = R1->Next;
        Q->Next = Tmp;
        Q = Q->Next;
    }
    while(R2->Next){
        Tmp = (Polynomial)malloc(sizeof(struct PNode));
        Tmp->Next = NULL;
        Tmp->exp = R2->Next->exp;
        Tmp->cof = R2->Next->cof;
        R2 = R2->Next;
        Q->Next = Tmp;
        Q = Q->Next;
    }
    return P;


}

Polynomial Mul(Polynomial P1,Polynomial P2)
{
    int c,e;
    Polynomial P,Q,Tmp,R1,R2;
    P = (Polynomial)malloc(sizeof(struct PNode));
    P->Next = NULL;
    Q = P;
    R1 = P1;
    R2 = P2;
    if(!R2 || !R1){
        return P;
    }
    while(R2->Next){
        Tmp = (Polynomial)malloc(sizeof(struct PNode));
        Tmp->exp = R1->Next->exp + R2->Next->exp;
        Tmp->cof = R1->Next->cof * R2->Next->cof;
        Tmp->Next = NULL;
        Q->Next = Tmp;
        Q = Q->Next;
        R2 = R2->Next;
    }
    R1 = R1->Next;
    while(R1->Next){
        Q = P;
        R2 = P2;
        while(R2->Next){
            c = R1->Next->cof * R2->Next->cof;
            e = R1->Next->exp + R2->Next->exp;
            while(Q->Next && Q->Next->exp > e){
                Q = Q->Next;
            }
            if(Q->Next && Q->Next->exp == e){
                if(Q->Next->cof + c){
                    Q->Next->cof += c;
                }
                else{
                    Tmp = Q->Next;
                    Q->Next = Tmp->Next;
                    free(Tmp);
                }
            }
            else{
                Tmp = (Polynomial)malloc(sizeof(struct PNode));
                Tmp->cof = c;
                Tmp->exp = e;
                Tmp->Next = Q->Next;
                Q->Next = Tmp;
                Q = Q->Next;
            }
            R2 = R2->Next;
        }
        R1 = R1->Next;
    }
    return P;
}

void Print(Polynomial P)
{
    if(P->Next==NULL){
        printf("%d %d",0,0);
    }
    while(P->Next){
        P = P->Next;
        if(P->Next)
            printf("%d %d ",P->cof,P->exp);
        else
            printf("%d %d",P->cof,P->exp);    
    }
}