#include <stdio.h>

// 计算忽略指数小于 k 的质数后，剩下数的乘积
long long calculate(long long a, int k) {
    long long result = 1;
    for (long long prime = 2; prime * prime <= a; prime++) {
        int exponent = 0;
        while (a % prime == 0) {
            a /= prime;
            exponent++;
        }
        if (exponent >= k) {
            long long temp = 1;
            for (int i = 0; i < exponent; i++) {
                temp *= prime;
            }
            result *= temp;
        }
    }
    if (a > 1 && 1 >= k) {
        result *= a;
    }
    return result;
}

int main() {
    int q;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        long long a;
        int k;
        scanf("%lld %d", &a, &k);
        long long ans = calculate(a, k);
        printf("%lld\n", ans);
    }
    return 0;
}