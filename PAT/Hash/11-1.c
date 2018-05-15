#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define MAXTABLESIZE 200000
#define KEYLENGTH 11

typedef char ElementType[KEYLENGTH + 1];
typedef int Index;

typedef struct LNode* PtrToLNode;
struct LNode
{
	ElementType Data;
	PtrToLNode Next;
	int Count;
};
typedef PtrToLNode Position;
typedef PtrToLNode List;

typedef struct TblNode* HashTable;
struct TblNode
{
	int TableSize;
	List Heads;
};

int Hash(int Key, int P)
{
	return Key % P;
}

int NextPrime(int N)
{
	int i, p = (N%2) ? N+2:N+1;
	while(p <= MAXTABLESIZE){
		for(i = (int)sqrt(p); i > 2; i--)
			if(!(p%i))
				break;
		if(i == 2)
			break;
		else
			p += 2;
	}
	return p;
}

HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;

	H = (HashTable)malloc(sizeof(struct TblNode));
	H->TableSize = NextPrime(TableSize);

	H->Heads = (List)malloc(sizeof(struct LNode) * H->TableSize);
	for(i = 0; i < H->TableSize; i++){
		H->Heads[i].Data[0] = 0;
		H->Heads[i].Next = NULL;
		H->Heads[i].Count = 0;
	}
	return H;
}

Position Find(HashTable H, ElementType Key)
{
	Position P;
	Index Pos;

	Pos = Hash(atoi(Key + 6), H->TableSize);
	P = H->Heads[Pos].Next;
	while(P && strcmp(P->Data,Key))
		P = P->Next;
	return P;
}

void Insert(HashTable H, ElementType Key)
{
	Position P, NewCell;
	Index Pos;

	P = Find(H, Key);
	if(!P){
		NewCell = (Position)malloc(sizeof(struct LNode));
		strcpy(NewCell->Data, Key);
		NewCell->Count = 1;
		Pos = Hash(atoi(Key + 6), H->TableSize);
		NewCell->Next = H->Heads[Pos].Next;
		H->Heads[Pos].Next = NewCell;	
	}
	else
		P->Count++;
}

void DestoryTable(HashTable H)
{
	int i;
	Position P, Tmp;

	for (i = 0; i < H->TableSize; ++i)
	{
		P = H->Heads[i].Next;
		while(P){
			Tmp = P->Next;
			free(P);
			P = Tmp;
		}
	}
	free(H->Heads);
	free(H);
}


void ScanAndOutput(HashTable H);

int main(int argc, char const *argv[])
{
	int N;
	HashTable H;
	ElementType Key;


	scanf("%d", &N);
	H = CreateTable(2*N);

	for(int i = 0; i < N; i++){
		scanf("%s", Key);
		Insert(H, Key);
		scanf("%s", Key);
		Insert(H,Key);
	}

	ScanAndOutput(H);
	DestoryTable(H);

	return 0;
}

void ScanAndOutput(HashTable H)
{
	int i, MaxCnt, PCnt;
	List Ptr;
	ElementType MinPhone;

	MaxCnt = PCnt =0;
	MinPhone[0] = 0;
	for(i = 0; i < H->TableSize; i++){
		Ptr = H->Heads[i].Next;
		while(Ptr){
			if(Ptr->Count > MaxCnt){
				MaxCnt = Ptr->Count;
				strcpy(MinPhone,Ptr->Data);
				PCnt = 1;
			}
			else if(Ptr->Count == MaxCnt){
				PCnt++;
				if(strcmp(MinPhone,Ptr->Data) > 0)
					strcpy(MinPhone,Ptr->Data);
			}
			Ptr = Ptr->Next;
		}
	}
	printf("%s %d",MinPhone,MaxCnt);
	if(PCnt > 1)
		printf(" %d", PCnt);
	printf("\n");
}