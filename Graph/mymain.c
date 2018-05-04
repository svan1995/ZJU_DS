#include <stdio.h>
#include "../test2.h"

// int max2(int a,int b);

int main(int argc, char const *argv[])
{
    int a,b;
    scanf("%d %d",&a,&b);
    printf("%d\n", max2(a,b));
    return 0;
}