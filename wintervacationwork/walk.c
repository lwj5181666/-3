#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXM 105
#define INF 0x3f3f3f3f

// 定义方向数组，用于上下左右移动
const int dx[] = {1, -1, 0, 0};
const int dy[] = {0, 0, 1, -1};

// 定义状态结构体，存储当前位置、花费、是否能使用魔法和当前颜色
typedef struct {
    int x, y;
    int cost;
    int canUseMagic;
    int color;
} State;

// 判断坐标是否在棋盘内
int isValid(int x, int y, int m) {
    return x >= 1 && x <= m && y >= 1 && y <= m;
}

// 广度优先搜索函数
int bfs(int m, int board[MAXM][MAXM]) {
    // 定义队列
    State queue[MAXM * MAXM * 2 * 2];
    int front = 0, rear = 0;
    // 定义距离数组，存储到达每个状态的最小花费
    int dist[MAXM][MAXM][2][2];
    memset(dist, INF, sizeof(dist));

    int startColor = board[1][1];
    // 初始状态入队
    queue[rear++] = (State){1, 1, 0, 1, startColor};
    dist[1][1][1][startColor] = 0;

    while (front < rear) {
        State cur = queue[front++];
        int x = cur.x, y = cur.y;
        int cost = cur.cost;
        int canUseMagic = cur.canUseMagic;
        int color = cur.color;

        // 到达右下角，返回最小花费
        if (x == m && y == m) {
            return cost;
        }

        // 尝试四个方向移动
        for (int i = 0; i < 4; i++) {
            int nx = x + dx[i], ny = y + dy[i];
            if (!isValid(nx, ny, m)) continue;

            if (board[nx][ny] != -1) { // 有颜色的格子
                int newCost = cost;
                if (board[nx][ny] != color) {
                    newCost++;
                }
                if (newCost < dist[nx][ny][1][board[nx][ny]]) {
                    dist[nx][ny][1][board[nx][ny]] = newCost;
                    queue[rear++] = (State){nx, ny, newCost, 1, board[nx][ny]};
                }
            } else if (canUseMagic) { // 无色格子且可以使用魔法
                for (int newColor = 0; newColor < 2; newColor++) {
                    int newCost = cost + 2;
                    if (newColor != color) {
                        newCost++;
                    }
                    if (newCost < dist[nx][ny][0][newColor]) {
                        dist[nx][ny][0][newColor] = newCost;
                        queue[rear++] = (State){nx, ny, newCost, 0, newColor};
                    }
                }
            }
        }
    }
    return -1;
}

int main() {
    int m, n;
    int board[MAXM][MAXM];
    // 初始化棋盘，-1 表示无色
    memset(board, -1, sizeof(board));

    scanf("%d %d", &m, &n);
    for (int i = 0; i < n; i++) {
        int x, y, c;
        scanf("%d %d %d", &x, &y, &c);
        board[x][y] = c;
    }

    int result = bfs(m, board);
    printf("%d\n", result);
    return 0;
}