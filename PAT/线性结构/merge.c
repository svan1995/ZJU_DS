List Merge(List L1,List L2)
{
    List L = (List)malloc(sizeof(struct Node));
    List P,Q;
    L->Next = NULL;
    P = L;
    while(L1->Next&&L2->Next){
        if(L1->Next->Data<L2->Next->Data){
            Q = L1->Next;
            L1->Next = Q->Next;
            
        }
        else{
            Q = L2->Next;
            L2->Next = Q->Next;
            
        }
        Q->Next = NULL;
        P->Next = Q;
        P = P->Next;
    }
    while(L1->Next){
        Q = L1->Next;
        P->Next = Q;
        L1->Next = NULL;
    }
    while(L2->Next){
        Q = L2->Next;
        P->Next = Q;
        L2->Next = NULL;
    }
    return L;
}