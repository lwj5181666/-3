#include<stdio.h>
#include<string.h>
#define max 1001

void cmp(int ls,int rs,int lt,int rt,char *a,char *b)
{
    char temp1[max];
    strncpy(temp1,a+ls-1,rs-ls+1);
    temp1[rs - ls + 1] = '\0';
    char temp2[max];
    strncpy(temp2,b+lt-1,rt-lt+1);
    temp2[rt - lt + 1] = '\0';
    if(strcmp(temp1,temp2)==0){
        printf("ovo\n");
    }else if(strcmp(temp1,temp2)>0){
        printf("erfusuer\n");
    }else {
        printf("yifusuyi\n");
    }

}

int main()
{
    char a[max],b[max];
    int n;
    scanf("%s",a);
    scanf("%s",b);
    scanf("%d",&n);
    int arr[n][4];
    for(int i=0;i<n;i++){
        for(int j=0;j<4;j++){
            scanf("%d",&arr[i][j]);
        }
    }
    for(int i=0;i<n;i++){
        cmp(arr[i][0],arr[i][1],arr[i][2],arr[i][3],a,b);
    }


    return 0;
}