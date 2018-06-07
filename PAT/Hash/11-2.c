#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXTABLESIZE 100000

typedef int ElementType;
typedef int Index;
typedef Index Position;

typedef struct HashEntry Cell;
struct HashEntry
{
	ElementType Data;
	int Info;
};

typedef struct TblNode* HashTable;
struct TblNode
{
	int TableSize;
	Cell* Cells;
};

int NextPrime(int N)
{
	int i, p = (N%2) ? N+2:N+1;
	if(N == 1)
		return 2;
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

int IsPrime(int N)
{
	int flag = 1;
	if(N == 1)
		flag = 0;
	if(N == 2)
		flag = 1;
	for(int i = 2; i <= N/2; i++ ){
		if(N % i == 0){
			flag = 0;
			break;
		}
	}
	return flag;
}

Position Hash(ElementType Key, int P)
{
	return Key%P;
}

HashTable CreateTable(int TableSize)
{
	HashTable H;
	int i;
	H = (HashTable)malloc(sizeof(struct TblNode));
	if(IsPrime(TableSize))
		H->TableSize = TableSize;
	else
		H->TableSize = NextPrime(TableSize);
	H->Cells = (Cell*)malloc(sizeof(Cell) * H->TableSize);
	for(i = 0; i < H->TableSize; i++)
		H->Cells[i].Info = 0;
	return H;
}

Position Find(HashTable H, ElementType Key)
{
	Position CurrentPos, NewPos;
	int CNum = 1;

	NewPos = CurrentPos = Hash(Key,H->TableSize);

	while(H->Cells[NewPos].Info != 0 && H->Cells[NewPos].Data != Key){
		NewPos = CurrentPos + CNum*CNum;
		CNum++;
		if(NewPos >= H->TableSize)
			NewPos %= H->TableSize;
		if(CNum >= H->TableSize){
			NewPos = -1;
			break;
		}
	}
	return NewPos;
}

void Insert(HashTable H, ElementType Key)
{
	Position Pos = Find(H,Key);
	if(Pos == -1)
		printf("-");
	else{
		if(H->Cells[Pos].Info == 0){
			H->Cells[Pos].Data = Key;
			H->Cells[Pos].Info = 1;
		}
		printf("%d",Pos);
	}
}

int main(int argc, char const *argv[])
{
	int M,N;
	int k;
	scanf("%d %d",&M,&N);
	HashTable H;
	H = CreateTable(M);
	for(int i = 0; i < N; i++){
		scanf("%d",&k);
		if(i > 0)
			printf(" ");
		Insert(H,k);
	}
	return 0;
}
