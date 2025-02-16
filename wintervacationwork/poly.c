#include<stdio.h>

int isprime(int n)
{
    if(n==2||n==3||n==5){
        return 1;
    }
    if(n==4){
        return 0;
    }
    int k=n;
    int ret=1;
    for(int i=2;i<k/2;i++){
        if(n%i==0){
            ret=0;
        }
    }
    return ret;
}

int main()
{
    int p;
    scanf("%d",&p);
    int sum=0;
    int cnt=0;
    for(int i=2;i<=p;i++){
        if(isprime(i)==1){
            sum+=i;
            if(sum>p){
                break;
            }
            if(sum<=p){
                cnt++;
                printf("%d\n",i);
            }
        }
    }
    printf("%d\n",cnt);


    return 0;
}