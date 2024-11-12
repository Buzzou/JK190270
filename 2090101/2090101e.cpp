//
// Created by Ruohao L. on 12/11/2024.
//
/*BFS 是一种层次遍历的搜索算法，可以在无权图中找到最短路径。
在 BFS 中，搜索会一层层扩展，每次都将当前层的所有邻居加入队列。这样，最先到达出口的路径就是最短路径。*/
#include "2090101e.h"
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

// 方向向量，表示上、下、左、右四个方向
const int dx[] = {-1, 1, 0, 0}; //类比2060301c的directions
const int dy[] = {0, 0, -1, 1};

// 定义位置结构体
struct Position
{
    int x, y, steps;
};

int Getting_out_of_maze()
{
    int n, m;
    cin >> n >> m;

    vector<string> maze(n); // 存储迷宫
    Position start, target;

    // 读取迷宫并找到起点和终点的位置
    for (int i = 0; i < n; ++i)
    {
        cin >> maze[i];
        for (int j = 0; j < m; ++j)
        {
            if (maze[i][j] == 'S')
            {
                start = {i, j, 0}; // 起点
            }
            else if (maze[i][j] == 'T')
            {
                target = {i, j, 0}; // 终点
            }
        }
    }

    // 创建一个访问标记数组，防止重复访问
    vector<vector<bool> > visited(n, vector<bool>(m, false));
    queue<Position> q;
    q.push(start);
    visited[start.x][start.y] = true;

    // BFS 开始
    while (!q.empty())
    {
        Position curr = q.front(); //访问队列 q 的第一个元素
        q.pop();

        // 检查是否到达终点
        if (curr.x == target.x && curr.y == target.y)
        {
            cout << curr.steps << endl;
            return 0;
        }

        // 扩展四个方向
        for (int i = 0; i < 4; ++i)
        {
            int nx = curr.x + dx[i];
            int ny = curr.y + dy[i];

            // 检查边界和访问条件
            if (nx >= 0 && nx < n && ny >= 0 && ny < m && !visited[nx][ny] && maze[nx][ny] != '#')
            {
                visited[nx][ny] = true;
                q.push({nx, ny, curr.steps + 1});
            }
        }
    }

    // 如果无法到达终点
    cout << "-1" << endl;
    return 0;
}
