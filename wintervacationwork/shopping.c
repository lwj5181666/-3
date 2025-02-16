#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int ee[m];
    for(int i=0;i<m;i++){
        scanf("%d",&ee[i]);
    }
    int num[n],er[n];
    for(int i=0;i<n;i++){
        scanf("%d %d",&num[i],&er[i]);
    }
    for(int i=0;i<n;i++){
        int tempnum=1;
        for(int j=0;j<num[i];j++){
            tempnum*=10;
        }
        int min=1000000;
        int ret=0;
        for(int j=0;j<m;j++){
            if(er[i]==(ee[j]%tempnum)&&ee[j]<min){
                ret=1;
                min=ee[j];
            }
        }
    if(ret==1){
        printf("%d\n",min);
    }else printf("-1\n");

        
    }

    return 0;
}