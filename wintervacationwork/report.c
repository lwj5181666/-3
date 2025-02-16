#include <stdio.h>
#include <stdlib.h>

// 比较函数，用于 qsort 进行降序排序
int compare(const void *a, const void *b) {
    return (*(int *)b - *(int *)a);
}

int main() {
    int N, B;
    // 读取书的数量 N 和身高 B
    scanf("%d %d", &N, &B);

    // 动态分配数组来存储每本书的厚度
    int *heights = (int *)malloc(N * sizeof(int));
    if (heights == NULL) {
        // 内存分配失败，输出错误信息并退出程序
        fprintf(stderr, "Memory allocation failed\n");
        return 1;
    }

    // 读取每本书的厚度
    for (int i = 0; i < N; i++) {
        scanf("%d", &heights[i]);
    }

    // 使用 qsort 对书的厚度数组进行降序排序
    qsort(heights, N, sizeof(int), compare);

    int count = 0;
    int total_height = 0;

    // 依次选取书，直到厚度总和不低于身高
    for (int i = 0; i < N; i++) {
        total_height += heights[i];
        count++;
        if (total_height >= B) {
            break;
        }
    }

    // 输出最少使用的书的数量
    printf("%d\n", count);

    // 释放动态分配的内存
    free(heights);

    return 0;
}