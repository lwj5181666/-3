#include<stdio.h>
int main()
{
    int n,k;
    scanf("%d %d",&n,&k);
    int a[n];
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1-i;j++){
            if(a[j]>a[j+1]){
                int temp=a[j];
                a[j]=a[j+1];
                a[j+1]=temp;
            }
        }
    }
    int min=a[0];
    int t=1;
    
    for(int i=0;i<n;i++){
        if(a[i]>min){
            min=a[i];
            t++;
        }
        if(t==k){
            break;
        }
    }
    if(t<k) printf("NO RESULT");
    else printf("%d",min);

    return 0;
}