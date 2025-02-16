#include<stdio.h>
int _2(int n) {
    int a = 1;
    for (int i = 0; i < n; i++) {
        a *= 2;
    }
    return a;
}
int max(int a, int b) {
    if (a > b) return a;
    else return b;
}
int min_total(int n, int* a) {
    if (n == 1) return *a;
    if (n == 2) return max(*a, *(a + 1));
    if (n == 3) return max(max(max(*a, *(a + 1)), *(a + 2)), *a + *(a + 1) + *(a + 2) - max(max(*a, *(a + 1)), *(a + 2)));
}

int sum1(int n, int _01, int* a) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int num = _01 % 2;
        _01 /= 2;
        s += num * (*(a + i));
    }
    return s;
}
int sum0(int n, int _01, int* a) {
    int s = 0;
    for (int i = 0; i < n; i++) {
        int num = _01 % 2;
        _01 /= 2;
        s += (!num) * (*(a + i));
    }
    return s;
}

int min_total2(int n, int* a) {
    int _01 = 0;
    int min = 99999;
    for (_01 = 0; _01 < (_2(n) - 1); _01++) {
        int temp = max(sum1(n, _01, a), sum0(n, _01, a));
        if (temp < min) min = temp;
    }
    return min;
}
int main() {
    int a, b, c, d;
    scanf("%d %d %d %d", &a, &b, &c, &d);
    int arr[100];
    for (int i = 0; i < a; i++) {
        scanf("%d", &arr[i]);
    }
    if (a < 4) a = min_total(a, arr);
    else a = min_total2(a, arr);

    for (int i = 0; i < b; i++) {
        scanf("%d", &arr[i]);
    }
    if (b < 4) b = min_total(b, arr);
    else b = min_total2(b, arr);

    for (int i = 0; i < c; i++) {
        scanf("%d", &arr[i]);
    }
    if (c < 4) c = min_total(c, arr);
    else c = min_total2(c, arr);

    for (int i = 0; i < d; i++) {
        scanf("%d", &arr[i]);
    }
    if (d < 4) d = min_total(d, arr);
    else d = min_total2(d, arr);

    printf("%d", a + b + c + d);
    return 0;
}