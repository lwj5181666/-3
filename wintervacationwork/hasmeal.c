#include<stdio.h>
int main(void)
{
    int a,b;
    scanf("%d %d",&a,&b);
    int c=a*10+b;
    int ret=c/19;
    printf("%d",ret);

    return 0;
}