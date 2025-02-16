#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_N 5000

// 存储每个任务的前置任务
int preTasks[MAX_N + 1][MAX_N];
// 存储每个任务的前置任务数量
int preTaskCount[MAX_N + 1];
// 标记任务是否已经被访问过
bool visited[MAX_N + 1];
// 完成任务的数量
int count = 0;

// 深度优先搜索函数
void dfs(int task) {
    if (visited[task]) return;
    visited[task] = true;
    count++;
    for (int i = 0; i < preTaskCount[task]; i++) {
        dfs(preTasks[task][i]);
    }
}

int main() {
    int N;
    scanf("%d", &N);

    // 初始化访问标记数组
    for (int i = 1; i <= N; i++) {
        visited[i] = false;
        preTaskCount[i] = 0;
    }

    // 读取每个任务的前置任务信息
    for (int i = 1; i <= N; i++) {
        scanf("%d", &preTaskCount[i]);
        for (int j = 0; j < preTaskCount[i]; j++) {
            scanf("%d", &preTasks[i][j]);
        }
    }

    // 从 1 号任务开始进行深度优先搜索
    dfs(1);

    // 输出结果
    printf("%d\n", count);

    return 0;
}