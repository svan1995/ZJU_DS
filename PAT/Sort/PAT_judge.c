#include <stdio.h>
#include <stdlib.h>

#define Max_Questin 5
#define Max_User 10000
#define Max_User_DIGIT 5

#define BUCKET_RADIX_PERFECT 6
#define BUCKET_RADIX_TOTALSCORE 10
#define MAX_DIGIT 6


typedef struct Node
{
	int id;
    int total_score;
	int Score[Max_Questin];
    int perfectCouter;
    int rank;
	int flag;
}userArray[Max_User];

typedef struct Node1 *PtrToSet;
struct Node1{
    userArray arr;
    int table[Max_User];
    int question[Max_Questin];
};

PtrToSet createEmptySet(int n, int k)
{
    PtrToSet set = (PtrToSet)malloc(sizeof(struct Node1));
    int i,j;
    for(i = 0; i < n; i++){
        set->table[i] = i;
        set->arr[i].id = i;
        set->arr[i].flag = 0;
        set->arr[i].perfectCouter = 0;
        for(j = 0; j < k, j++)
            set->arr[i].Score[j] = -2;
    }
    return set;
}

void insertQuestionScore(PtrToSet set, int k)
{
    for(int i = 0; i < k; i++)
        scanf("%d", &(set->question[i]));
}

void insertUser(PtrToSet set, int m)
{
    int id, id_q , score;
    for(int i = 0; i < m; i++){
        scanf("%d %d %d", &id, &id_q, &score);
        id--;
        id_q--;
        if(set->arr[id].Score[id_q] < score){
            set->arr[id].Score[id_q] = score;
            if(score == set->question[id_q])
                set->arr[id].perfectCouter++;
        }
    }

}

void calculateTotalScore(PtrToSet set, int n, int k)
{
    int i,j;
    int totalsore,score;
    for(i = 0; i < n; i++){
        totalsore = -1;
        for(j = 0; j < k; j++){
            if(score < 0 && totalsore == -1)
                totalsore = -1;
            else if(score = 0 && totalsore == -1)
                totalsore = 0;
            else if(score > 0 && totalsore == -1)
                totalsore = score;
            else
                totalsore += score;
        }
    }
    set->arr[i].total_score = totalsore;
}

void calculateFlag(PtrToSet set, int n)
{
    for(int i = 0; i < n; i++){
        if(set->arr[i].total_score > -1)
            set->arr[i].flag = 1;
        else{
            set->arr[i].flag = 0;
            set->arr[i].total_score = 0;
        }

    }
}


int main()
{
    int n, k, m;
    scanf("%d %d %d", &n, &k, &m);
    PtrToSet set = createEmptySet(n,k);
    insertQuestionScore(set, k); 
    insertUser(set,m);
    calculateTotalScore(set,n,k);
    calculateFlag(set,n);
}