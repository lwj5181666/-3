#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main() {
    int n;
    int *c;
    int m, p1, s1, s2;

    // 读取战场数量
    scanf("%d", &n);

    // 动态分配数组内存
    c = (int *)malloc(n * sizeof(int));
    if (c == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // 读取每个战场的士兵数量
    for (int i = 0; i < n; i++) {
        scanf("%d", &c[i]);
    }

    // 读取 m, p1, s1, s2
    scanf("%d %d %d %d", &m, &p1, &s1, &s2);

    // 更新 p1 战场的士兵数量
    c[p1 - 1] += s1;

    // 计算初始士气
    long long bngg_morale = 0;
    long long hmgg_morale = 0;
    for (int i = 0; i < n; i++) {
        int distance = abs(i + 1 - m);
        if (i + 1 < m) {
            bngg_morale += (long long)c[i] * distance;
        } else if (i + 1 > m) {
            hmgg_morale += (long long)c[i] * distance;
        }
    }

    // 初始化最小士气差距和对应的战场编号
    long long min_diff = 1e18;
    int best_p2 = 1;

    // 枚举所有可能的 p2
    for (int p2 = 1; p2 <= n; p2++) {
        long long new_bngg_morale = bngg_morale;
        long long new_hmgg_morale = hmgg_morale;
        int distance = abs(p2 - m);

        if (p2 < m) {
            new_bngg_morale += (long long)s2 * distance;
        } else if (p2 > m) {
            new_hmgg_morale += (long long)s2 * distance;
        }

        // 计算新的士气差距
        long long diff = llabs(new_bngg_morale - new_hmgg_morale);

        // 如果新的士气差距更小，更新最小士气差距和对应的战场编号
        if (diff < min_diff) {
            min_diff = diff;
            best_p2 = p2;
        }
    }

    // 输出结果
    printf("%d\n", best_p2);

    // 释放动态分配的内存
    free(c);

    return 0;
}