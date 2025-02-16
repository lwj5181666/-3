#include<stdio.h>
int main()
{
    int a,b,c;
    scanf("%d %d %d",&a,&b,&c);
    if(a>=b){
        int temp1=a;
        a=b;
        b=temp1;
    }
    if(b>=c){
        int temp2=b;
        b=c;
        c=temp2;
        if(a>=b){
            int temp3=a;
            a=b;
            b=temp3;
        }
    }
    printf("%d %d %d",a,b,c);


    return 0;
}