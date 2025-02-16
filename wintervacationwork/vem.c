#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于 qsort 降序排序
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int n, m, k;
    // 读取售货机的层数 n、每层货槽数 m 和商品种类数 k
    scanf("%d %d %d", &n, &m, &k);

    // 动态分配数组存储每种商品允许的最大摔落距离
    int *heights = (int *)malloc(k * sizeof(int));
    if (heights == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }
    // 读取每种商品允许的最大摔落距离
    for (int i = 0; i < k; i++) {
        scanf("%d", &heights[i]);
    }

    // 动态分配数组存储每层的可用货槽数量
    int *available_slots = (int *)malloc(n * sizeof(int));
    if (available_slots == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        free(heights);
        return 1;
    }
    // 初始化每层的可用货槽数量
    for (int i = 0; i < n; i++) {
        available_slots[i] = m;
    }

    // 对商品允许的最大摔落距离进行降序排序
    qsort(heights, k, sizeof(int), compare);

    int placed = 1;
    // 尝试摆放商品
    for (int i = 0; i < k; i++) {
        int placed_current = 0;
        // 从最低允许的层开始尝试放置商品
        for (int j = (heights[i] - 1 < n - 1)? heights[i] - 1 : n - 1; j >= 0; j--) {
            if (available_slots[j] > 0) {
                // 如果该层有可用货槽，则放置商品
                available_slots[j]--;
                placed_current = 1;
                break;
            }
        }
        if (!placed_current) {
            // 如果无法放置当前商品，则不存在合法摆放方式
            placed = 0;
            break;
        }
    }

    if (placed) {
        printf("Yes\n");
    } else {
        printf("No\n");
    }

    // 释放动态分配的内存
    free(heights);
    free(available_slots);

    return 0;
}