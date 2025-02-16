#include <stdio.h>

#define MAX_N 1000
#define MAX_M 1000

// 定义结构体表示位移和点的坐标
typedef struct {
    int dx;
    int dy;
} Displacement;

typedef struct {
    int x;
    int y;
} Point;

int main() {
    int n, m;
    // 读取位移次数 n 和点的个数 m
    scanf("%d %d", &n, &m);

    // 存储每次位移的信息
    Displacement displacements[MAX_N];
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &displacements[i].dx, &displacements[i].dy);
    }

    // 存储每个点的初始坐标
    Point points[MAX_M];
    for (int i = 0; i < m; i++) {
        scanf("%d %d", &points[i].x, &points[i].y);
    }

    // 对每个点进行 n 次位移操作
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            points[i].x += displacements[j].dx;
            points[i].y += displacements[j].dy;
        }
    }

    // 输出每个点经过位移后的坐标
    for (int i = 0; i < m; i++) {
        printf("%d %d\n", points[i].x, points[i].y);
    }

    return 0;
}