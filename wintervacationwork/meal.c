#include <stdio.h>
#include <stdlib.h>

#define MAX_N 1005

// 计算最早开始时间
void calculate_earliest_start(int n, int p[], int t[], int earliest_start[]) {
    for (int i = 0; i < n; i++) {
        if (p[i] == 0) {
            // 无依赖的菜品最早从时刻 1 开始
            earliest_start[i] = 1;
        } else {
            // 有依赖的菜品最早开始时间为依赖菜品完成时间
            earliest_start[i] = earliest_start[p[i] - 1] + t[p[i] - 1];
        }
    }
}

// 计算最晚开始时间
int calculate_latest_start(int t, int n, int p[], int t_durations[], int earliest_start[], int latest_start[]) {
    int max_finish_time = 0;
    for (int i = 0; i < n; i++) {
        int finish_time = earliest_start[i] + t_durations[i] - 1;
        if (finish_time > max_finish_time) {
            max_finish_time = finish_time;
        }
    }

    if (max_finish_time > t) {
        // 无法在 t 时间内完成所有菜
        return 0;
    }

    // 先假设所有菜品都在 t 时刻完成
    for (int i = 0; i < n; i++) {
        latest_start[i] = t - t_durations[i] + 1;
    }

    // 从后往前调整最晚开始时间
    for (int i = n - 1; i >= 0; i--) {
        if (p[i] != 0) {
            int dep_index = p[i] - 1;
            if (latest_start[i] - t_durations[dep_index] < latest_start[dep_index]) {
                latest_start[dep_index] = latest_start[i] - t_durations[dep_index];
            }
        }
    }

    return 1;
}

int main() {
    int t, n;
    int p[MAX_N];
    int t_durations[MAX_N];
    int earliest_start[MAX_N];
    int latest_start[MAX_N];

    // 读取 t 和 n
    scanf("%d %d", &t, &n);

    // 读取每个菜品的依赖信息
    for (int i = 0; i < n; i++) {
        scanf("%d", &p[i]);
    }

    // 读取每个菜品的制作时间
    for (int i = 0; i < n; i++) {
        scanf("%d", &t_durations[i]);
    }

    // 计算最早开始时间
    calculate_earliest_start(n, p, t_durations, earliest_start);

    // 输出最早开始时间
    for (int i = 0; i < n; i++) {
        printf("%d", earliest_start[i]);
        if (i < n - 1) {
            printf(" ");
        }
    }
    printf("\n");

    // 计算最晚开始时间
    int can_finish = calculate_latest_start(t, n, p, t_durations, earliest_start, latest_start);

    if (can_finish) {
        // 可以在 t 时间内完成所有菜，输出最晚开始时间
        for (int i = 0; i < n; i++) {
            printf("%d", latest_start[i]);
            if (i < n - 1) {
                printf(" ");
            }
        }
        printf("\n");
    }

    return 0;
}