#include <iostream>
#include <queue>
using namespace std;

int main()
{
    // 壁、空きマスの迷路
    char grid[50][50];
    // スタート地点からの距離マス
    int dist[50][50];
    int R, C;
    cin >> R >> C;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            // dist[0[-1,-1],1[-1,-1]],迷路のマスを「未訪問」:-1に初期化
            dist[i][j] = -1;
    }
    int sy, sx, gy, gx;
    cin >> sy >> sx >> gy >> gx;
    --sy;
    --sx;
    --gy;
    --gx;
    for (int i = 0; i < R; ++i)
    {
        for (int j = 0; j < C; ++j)
            cin >> grid[i][j];
    }

    // 未訪問のマスを格納するキュー
    queue<pair<int, int>> que;
    // 初期条件、スタート地点=スタート地点からの距離:0
    dist[sy][sx] = 0;
    // 訪問予定マス
    que.push({sy, sx});

    // 移動方向である上下左右(4)方向
    int dy[4] = {1, 0, -1, 0};
    int dx[4] = {0, 1, 0, -1};
    // BFS
    while (!que.empty())
    {
        // キューから先頭要素を取り出す(訪問予定→現在地)
        auto pr = que.front();
        que.pop();
        // 現在地
        int y = pr.first;
        int x = pr.second;
        // スタート地点から現在地の距離
        int dist_yx = dist[y][x];

        // マス移動の上下左右(4)方向、訪問可能か調べる
        for (int i = 0; i < 4; ++i)
        {
            // 現在地からの移動予定地点
            int y2 = y + dy[i];
            int x2 = x + dx[i];
            // 迷路の範囲内かつ壁のマスでなく、未訪問の場合
            if (y2 < 0 || R <= y2 || x2 < 0 || C <= x2)
                continue;
            if (grid[y2][x2] == '#')
                continue;
            if (dist[y2][x2] != -1)
                continue;
            // 訪問可能なため、スタート地点から現在地の距離+1を格納する
            dist[y2][x2] = dist_yx + 1;
            // 訪問可能なマスを訪問予定へ格納
            que.push({y2, x2});
        }
    }
    cout << dist[gy][gx] << endl;
}
