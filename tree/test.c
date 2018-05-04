#include <stdio.h>

int main(int argc, char const *argv[])
{
    char c;
    int a,b;
    do{
        scanf("%c",&c);
        if(c == 'J'){
            scanf("%d %d",&a,&b);
            getchar();
            printf("%d\n", a+b );
        }
        else if(c == 'C'){
            scanf("%d %d",&a,&b);
            getchar();
            printf("%d\n", a*b );
        }
        else{
            printf("haha!\n");
            break;
        }
    }while(c != 'S');
    return 0;
}