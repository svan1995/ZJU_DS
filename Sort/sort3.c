#define MaxDigit 4
#define Radix 10

typedef struct Node* PtrToNode;
struct Node
{
	int Key;
	PtrToNode next;
};

struct HeadNode
{
	PtrToNode head, tail;
};
typedef struct HeadNode Bucket[Radix];

int GetDigit(int X, int D)
{
	int d, i;

	for (int i = 0; i <= D; i++)
	{
		d = X % Radix;
		X /= Radix;
	}
	return d;
}

void LSDRadixSort(ElementType A[], int N)
{
	int D, Di, i;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	for(i = 0; i < Radix; i++)
		B[i].head = B[i].tail = NULL;

	for(i = 0; i < N; i++){
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->Key = A[i];
		tmp->next = List;
		List = tmp;
	}
	for(D = 1; D <= MaxDigit; D++){
		p = List;
		while(p){
			Di = GetDigit(p->Key, D);
			tmp = p;
			p = p->next;
			tmp->next = NULL;
			if(B[Di].head == NULL)
				B[Di].head = B[Di].tail = tmp;
			else{
				B[Di].tail->next = tmp;
				B[Di].tail = tmp;
			}
		}

		List = NULL;
		for(Di = Radix-1; Di >= 0; Di--){
			if(B[Di].head){
				B[Di].tail = List;
				List = B[Di].head;
				B[Di].head = B[Di].tail = NULL;
			}
		}
	}

	for(i = 0; i < N; i++){
		tmp = List;
		List = List->next;
		A[i] = tmp->Key;
		free(tmp);
	}
}