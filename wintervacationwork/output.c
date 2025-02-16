#include <stdio.h>


void convertToPowerOfTwo(int n) {
    if (n == 0) {
        printf("0");
        return;
    }
    if (n == 1) {
        printf("2(0)");
        return;
    }
    if (n == 2) {
        printf("2");
        return;
    }

    int power = 0;
    int temp = n;

    while (temp > 1) {
        temp /= 2;
        power++;
    }

    if (power == 1) {
        printf("2");
    } else {
        printf("2(");
        convertToPowerOfTwo(power);
        printf(")");
    }

    n -= (1 << power);
    if (n > 0) {
        printf("+");
        convertToPowerOfTwo(n);
    }
}

int main() {
    int n;
    
    scanf("%d", &n);
    
    convertToPowerOfTwo(n);
    printf("\n");
    return 0;
}