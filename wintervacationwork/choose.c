#include <stdio.h>
#include <stdbool.h>

// 判断一个数是否为质数
bool isPrime(int num) {
    if (num < 2) return false;
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) return false;
    }
    return true;
}

// 递归函数，用于生成组合并计算和是否为质数
void combination(int arr[], int n, int k, int start, int index, int currentSum, int *count) {
    // 当组合长度达到 k 时
    if (index == k) {
        if (isPrime(currentSum)) {
            (*count)++;
        }
        return;
    }

    // 从 start 开始遍历数组，尝试将元素加入组合
    for (int i = start; i < n; i++) {
        // 递归调用，继续构建组合并更新当前和
        combination(arr, n, k, i + 1, index + 1, currentSum + arr[i], count);
    }
}

int main() {
    int n, k;
    scanf("%d %d", &n, &k);
    int arr[n];
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    int count = 0;
    // 调用递归函数生成组合并计算满足条件的组合数
    combination(arr, n, k, 0, 0, 0, &count);

    printf("%d\n", count);
    return 0;
}