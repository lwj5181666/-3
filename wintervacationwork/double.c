#include<stdio.h>
int main()
{
    int x;
    int count=0;
    scanf("%d",&x);
    for(count=0;x!=1;count++){
        x/=2;

    }
    count++;
    printf("%d",count);

    return 0;
}