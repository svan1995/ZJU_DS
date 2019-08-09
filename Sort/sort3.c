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
	printf("hello\n");

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



void MSD(ElementType A[], int L, int R, int D)
{
	int Di, i, j;
	Bucket B;
	PtrToNode tmp, p, List = NULL;

	if(D == 0)
		return;

	for(i = 0; i < Radix, i++ )
		B[i].head = B[i].tail = NULL;
	for(i = L; i <= R, i++ ){
		tmp = (PtrToNode)malloc(sizeof(struct Node));
		tmp->Key = A[i];
		tmp->next = NULL;
		List = tmp;
	}

	p = List;
	while(p){
		Di = GetDigit(p->Key, D);
		tmp = p;
		p = p->next;
		if(B[Di].head == NULL)
			B[Di].tail = tmp;
		tmp->next = B[Di].head;
		B[Di].head = tmp;
	}

	i = j = L;
	for(Di = 0; Di < Radix; Di++){
		if(B[Di].head){
			p = B[Di].head;
			while(p){
				tmp = p;
				p = p->next;
				A[j++] = tmp->Key;
				free(tmp);
			}
			MSD(A,i,j-1,D-1);
			i = j;
		}
	}
	
}

void MSDRadixSort(ElementType A[], int N)
{
	MSD(A, 0, N-1, MaxDigit);
}

