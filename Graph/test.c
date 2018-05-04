#include <stdio.h>


void Zero(int *a){
    a[0] = 3;
}

int main(int argc, char const *argv[])
{
    int a[2];
    a[0] = 1;
    a[1] = 2;
    Zero(a);
    printf("%d\n", a[0]);
}