#include<iostream>
#include<algorithm>
using namespace std;
int main() {
    int x, Q;
    scanf("%d %d", &x, &Q);
    int* bbb=new int[x]; 
    int ii,jj,c;
    char indexx;
    for (int i=0;i<x; i++) {
                scanf("%d",&ii);
                scanf("%c",&indexx);
                scanf("%c",&indexx);
                
                scanf("%d",&jj);
                if (indexx=='-') jj=-jj;
                scanf("%c",&indexx);
                scanf("%d",&c);
                bbb[i] = (c-jj) / ii;
            }

    sort(bbb, bbb + x);
    int an[200000];
    int j=0;
    an[j++]=bbb[0];
    for (int i=1; i<x; i++) {
        if (bbb[i] > bbb[i-1]) an[j++] = bbb[i];
    }
    while (Q--) {
        int p, q;
        scanf("%d %d", &p, &q);
        int left=lower_bound(an,an+j,p)-an;
        int right=upper_bound(an,an+j,q)-an;
        printf("%d\n",right-left);
    }

    delete[] bbb;
    return 0;
}