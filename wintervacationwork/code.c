
#include <stdio.h>

#define MAX_N 1000

int main() {
    int n, m;
    int a[MAX_N];
    int b[MAX_N];
    int c[MAX_N + 1];

    // 读取 n 和 m
    scanf("%d %d", &n, &m);

    // 读取数组 a
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 计算 c 数组
    c[0] = 1;
    for (int i = 1; i <= n; i++) {
        c[i] = c[i - 1] * a[i - 1];
    }

    // 还原数组 b
    for (int i = n - 1; i >= 0; i--) {
        b[i] = m / c[i];
        m %= c[i];
    }

    // 输出数组 b
    for (int i = 0; i < n; i++) {
        printf("%d", b[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    return 0;
}