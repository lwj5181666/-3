#include <stdio.h>
#include <stdlib.h>
#include <stddef.h>  // 包含 stddef.h 以定义 size_t

#define MAX_N 100005

int a[MAX_N];

// 比较函数，用于 qsort
int cmp(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}

// 二分查找第一个大于等于 x 的元素的索引
int lower_bound(int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] < x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// 二分查找第一个大于 x 的元素的索引
int upper_bound(int n, int x) {
    int left = 0, right = n;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (a[mid] <= x) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return left;
}

// 处理类型 1 的查询：查询数列中有多少个数刚好等于 x
int queryType1(int n, int x) {
    int left = lower_bound(n, x);
    int right = upper_bound(n, x);
    return right - left;
}

// 处理类型 2 的查询：查询数列中有多少个数大于等于 x 并且小于等于 y
int queryType2(int n, int x, int y) {
    int left = lower_bound(n, x);
    int right = upper_bound(n, y);
    // 修正：若 x > y，直接返回 0
    if (x > y) return 0;
    return right - left;
}

// 处理类型 3 的查询：查询数列中有多少个数大于等于 x 并且小于 y
int queryType3(int n, int x, int y) {
    int left = lower_bound(n, x);
    int right = lower_bound(n, y);
    // 修正：若 x >= y，直接返回 0
    if (x >= y) return 0;
    return right - left;
}

// 处理类型 4 的查询：查询数列中有多少个数大于 x 并且小于等于 y
int queryType4(int n, int x, int y) {
    int left = upper_bound(n, x);
    int right = upper_bound(n, y);
    // 修正：若 x >= y，直接返回 0
    if (x >= y) return 0;
    return right - left;
}

// 处理类型 5 的查询：查询数列中有多少个数大于 x 并且小于 y
int queryType5(int n, int x, int y) {
    int left = upper_bound(n, x);
    int right = lower_bound(n, y);
    // 修正：若 x >= y，直接返回 0
    if (x >= y) return 0;
    return right - left;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    // 读取数列
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    // 对数列进行排序
    qsort(a, n, sizeof(int), cmp);

    // 处理每次查询
    for (int i = 0; i < m; i++) {
        int p, x, y;
        scanf("%d", &p);
        if (p == 1) {
            scanf("%d", &x);
            printf("%d\n", queryType1(n, x));
        } else {
            scanf("%d %d", &x, &y);
            if (p == 2) {
                printf("%d\n", queryType2(n, x, y));
            } else if (p == 3) {
                printf("%d\n", queryType3(n, x, y));
            } else if (p == 4) {
                printf("%d\n", queryType4(n, x, y));
            } else if (p == 5) {
                printf("%d\n", queryType5(n, x, y));
            }
        }
    }

    return 0;
}