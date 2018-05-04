#include <stdio.h>


void print(int *a)
{
    for(int i =0;i<3;i++)
        printf("%d\t",a[i]);
}

int main()
{
    int a[3][3];
    for(int i =0;i<3;i++){
        for(int j = 0;j<3;j++){
            a[i][j] = j + 3*i;
        }
    }
    // printf("%d,%d\n",a[1][1],a[2][0]);

    print(a[1]);
    // printf("%d", *(a[1]+1));
}

