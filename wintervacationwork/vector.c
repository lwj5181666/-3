#include <stdio.h>

#define MAX_N 1005
#define MAX_M 1005

int vectors[MAX_N][MAX_M];
int n, m;

// 检查向量 v2 是否在所有维度上都比向量 v1 大
int is_greater(int v1[], int v2[]) {
    for (int i = 0; i < m; i++) {
        if (v2[i] <= v1[i]) {
            return 0;
        }
    }
    return 1;
}

int main() {
    // 读取向量个数 n 和维数 m
    scanf("%d %d", &n, &m);

    // 读取所有向量
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            scanf("%d", &vectors[i][j]);
        }
    }

    // 为每个向量寻找所有维度都比它大的向量
    for (int i = 0; i < n; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (is_greater(vectors[i], vectors[j])) {
                // 找到符合条件的向量，输出其编号
                printf("%d\n", j + 1);
                found = 1;
                break;
            }
        }
        if (!found) {
            // 没有找到符合条件的向量，输出 0
            printf("0\n");
        }
    }

    return 0;
}