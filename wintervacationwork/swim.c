#include<stdio.h>
int Sum(double dis);
int main()
{
    double dis=0;
    scanf("%lf",&dis);
    printf("%d",Sum(dis));

    return 0;
}

int Sum(double dis)
{
   
    double ret=2;
    double step=2;
    if(dis<=2) return 1;
    int n=1;
    for(n=1;ret<dis;n++){
        step*=0.98;
        ret+=step;
    }
    return n;
}