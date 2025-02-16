#include <stdio.h>
#include <string.h>
#include <stddef.h>

#define MATRIX_SIZE 8
#define MAX_MATRICES 1000

// 比较两个 8x8 字符矩阵是否相同
int compareMatrices(char matrix1[MATRIX_SIZE][MATRIX_SIZE + 1], char matrix2[MATRIX_SIZE][MATRIX_SIZE + 1]) {
    for (int i = 0; i < MATRIX_SIZE; i++) {
        if (strcmp(matrix1[i], matrix2[i]) != 0) {
            return 0;
        }
    }
    return 1;
}

int main() {
    int n;
    // 读取矩阵的数量
    scanf("%d", &n);

    // 存储所有的矩阵
    char matrices[MAX_MATRICES][MATRIX_SIZE][MATRIX_SIZE + 1];

    // 读取每个矩阵
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < MATRIX_SIZE; j++) {
            scanf("%s", matrices[i][j]);
        }

        // 统计当前矩阵在之前出现的次数
        int count = 0;
        for (int k = 0; k < i; k++) {
            if (compareMatrices(matrices[i], matrices[k])) {
                count++;
            }
        }
        // 输出当前矩阵是第几次出现
        printf("%d\n", count + 1);
    }

    return 0;
}