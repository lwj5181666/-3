#include <stdio.h>
int main() {
    int a = 0;
    scanf("%d", &a);
    
    if (a % 2 == 0 && a > 4 && a <= 12) {
        printf("1");
    } else {
        printf("0");
    }
    printf(" ");
   
    if (a % 2 == 0 || (a > 4 && a <= 12)) {
        printf("1");
    } else {
        printf("0");
    }
    printf(" ");

    if ((a % 2 == 0 && (a <= 4 || a > 12)) || (a % 2 != 0 && a > 4 && a <= 12)) {
        printf("1");
    } else {
        printf("0");
    }
    printf(" ");

    if (a % 2 != 0 && (a <= 4 || a > 12)) {
        printf("1");
    } else {
        printf("0");
    }
    return 0;
}