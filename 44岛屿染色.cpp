#include <iostream>
#include <vector>
using namespace std;

const int N = 1005; // 定义一个足够大的常量N
int n;
// mp 存储地图，'.' 表示海洋，'#' 表示陆地
vector<string> mp(N);
// col 存储每个像素的颜色/岛屿编号，0 表示未访问
vector<vector<int>> col(N, vector<int>(N, 0)); 

// 方向数组，用于方便地访问上下左右四个邻居
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

// 深度优先搜索函数，用于染色
// x, y: 当前要染色的像素坐标
// c: 要染的颜色编号
void dfs(int x, int y, int c) {
    // 1. 给当前像素染色
    col[x][y] = c;

    // 2. 遍历四个方向
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i]; // 新的 x 坐标
        int ny = y + dy[i]; // 新的 y 坐标

        // 3. 检查新坐标是否合法（在地图范围内）
        if (nx < 1 || nx > n || ny < 1 || ny > n) {
            continue; // 越界了，跳过
        }

        // 4. 检查新坐标是否是陆地，并且是否已经被染色
        if (mp[nx][ny] == '#' && col[nx][ny] == 0) {
            // 如果是陆地且没被染过，就递归地给它染色
            dfs(nx, ny, c);
        }
    }
}

int main() {
    // 加速输入输出
    ios::sync_with_stdio(0), cin.tie(0), cout.tie(0);

    // 读取输入
    cin >> n;
    for (int i = 1; i <= n; ++i) {
        cin >> mp[i]; // 注意：这里 mp[i] 是一个字符串，从第 1 个字符开始存储
        mp[i] = " " + mp[i]; // 为了让下标从 1 开始，方便处理边界，我们在前面加一个空格
    }

    int color = 0; // 颜色编号，从 0 开始

    // 遍历整个地图
    for (int i = 1; i <= n; ++i) {
        for (int j = 1; j <= n; ++j) {
            // 如果当前像素是陆地，并且还没被染色
            if (mp[i][j] == '#' && col[i][j] == 0) {
                color++; // 发现一个新岛屿，颜色编号加一
                dfs(i, j, color); // 从这个点开始，用新的颜色进行 DFS 染色
            }
        }
    }

    // color 现在就是岛屿的总数
    cout << color << endl;

    return 0;
}

