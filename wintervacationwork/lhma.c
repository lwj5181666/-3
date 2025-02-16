#include <stdio.h>

#define MAX_LEN 10000

int main() {
    int n;
    int compressed[MAX_LEN];
    int index = 0;

    // 读取压缩序列的第一个数 N
    scanf("%d", &n);

    int total = n * n;  // 矩阵元素的总数
    int sum = 0;  // 已读取的压缩数字的总和

    // 读取剩余的压缩序列
    while (sum < total) {
        scanf("%d", &compressed[index]);
        sum += compressed[index];
        index++;
    }

    int current_num = 0;  // 当前要填充的数字，0 或 1
    int count_index = 0;  // 压缩序列中当前数字的索引

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (compressed[count_index] == 0) {
                // 当前压缩数字用完，切换到下一个压缩数字
                count_index++;
                current_num = 1 - current_num;  // 切换 0 和 1
            }
            printf("%d", current_num);
            compressed[count_index]--;
        }
        printf("\n");
    }

    return 0;
}
