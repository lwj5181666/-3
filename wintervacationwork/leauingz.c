#include<stdio.h>
int main()
{
    int n=0;
    scanf("%d",&n);
    if(n*5<(n*3+11)) printf("Local");
    else printf("Luogu");

    return 0;
}