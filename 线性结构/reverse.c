#include <stdio.h>
#define MAX_SIZE 100004

typedef struct _Node
{
    int addr;
    int data;
    int nextaddr;
    struct _Node *next;
}LNode;

void printList(LNode *a);
LNode *listReverse(LNode *head,int k);


int main(int argc, char const *argv[])
{
    int firstAddr;
    int n = 0;
    int k = 0;
    int num = 0;
    int data[MAX_SIZE];
    int next[MAX_SIZE];
    int tmp;

    scanf("%d %d %d",&firstAddr,&n,&k);
    LNode a[n+1];
    a[0].nextaddr = firstAddr;
    int i;
    for(i=0;i<n;i++){
        scanf("%d",&tmp);
        scanf("%d %d",&data[tmp],&next[tmp]);
    }

    i = 1;
    while(1){
        if(a[i-1].nextaddr == -1){
           a[i-1].next = NULL;
           num = i-1;
           break;
        }
        a[i].addr = a[i-1].nextaddr;
        a[i].data = data[a[i].addr];
        a[i].nextaddr = next[a[i].addr];
        a[i-1].next = a + i;
        i++;
    }

    LNode *head = a;
    LNode *rp = NULL;
    if(k <= num){
        for(i = 0;i<(num/k);i++){
            rp = listReverse(head,k);
            head->next = rp;
            head->nextaddr = rp->addr;
            int j = 0;
            while(j<k){
                head = head->next;
                j++;
            }
        }
    }

    printList(a);
    return 0;
}

LNode* listReverse(LNode *head,int k)
{
    LNode *new = head->next, *old = new->next;
    LNode *tmp = NULL;
    int count = 1;
    for(;count<k;count++){
        tmp = old->next;
        old->next = new;
        old->nextaddr = new->addr;
        new = old;
        old = tmp;
    }
    head->next->next = old;
    if(old)
        head->next->nextaddr = old->addr;
    else
        head->next->nextaddr = -1;
    return new;
}

void printList(LNode *a)
{
    LNode *p = a;
    while(p->next){
        p = p->next;
        if(p->nextaddr != -1)
            printf("%.5d %d %.5d\n",p->addr,p->data,p->nextaddr);
        else
            printf("%.5d %d %d\n",p->addr,p->data,p->nextaddr);
    }
}