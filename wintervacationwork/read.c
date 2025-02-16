#include<stdio.h>
int main()
{
    int m,n;
    scanf("%d %d",&m,&n);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int b[m];
    for(int i=0;i<m;i++){
        b[i]=-1;
    }
    int k=0;
    int l=0;
    for(int i=0;i<n;i++){
        int ret=1;
        int temp=a[i];
        for(int j=0;j<m;j++){
            if(temp==b[j]){
                ret=0;
            }
        }
        if(ret==1){
            b[l]=temp;
            l++;
            l%=m;
            k++;
        }
    }
    printf("%d",k);

    return 0;

}