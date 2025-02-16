#include<stdio.h>
int main()
{
    int n,x;
    scanf("%d %d",&n,&x);
    int cnt=0;
    for(int i=1;i<=n;i++){
        int k=i;
        do{
            
            int temp=k%10;
            if(temp==x){
                cnt++;
            }
            k/=10;

        }while(k!=0);
    }

    printf("%d",cnt);

    return 0;
}