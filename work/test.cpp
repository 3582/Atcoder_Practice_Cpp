#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

// 方向:上下左右
const int dx[4] = {-1, 1, 0, 0};
const int dy[4] = {0, 0, -1, 1};

int main()
{
  int N, M;
  cin >> N >> M;
  vector<vector<int>> height(N, vector<int>(M));
  vector<vector<bool>> visited(N, vector<bool>(M, false));
  for (int i = 0; i < N; ++i)
  {
    for (int j = 0; j < M; ++j)
    {
      // 1桁の整数
      scanf("%1d", &height[i][j]);
    }
  }

  // 優先度付きキュー:壁の高さとその位置を保持
  // (1, (0, 0)) :水位が1で、位置が(0, 0)
  priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<>> pq;

  // 境界のブロックを優先度付きキューに追加し、訪問済みとマークする
  // {3, {0, 0}}, {3, {0, 3}} （最初の行の左端と右端）
  // {3, {1, 0}}, {4, {1, 3}} （2行目の左端と右端）
  // {3, {2, 0}}, {3, {2, 3}} （3行目の左端と右端）
  // {3, {3, 0}}, {3, {3, 3}} （最後の行の左端と右端）
  for (int i = 0; i < N; ++i)
  {
    pq.push({height[i][0], {i, 0}});
    pq.push({height[i][M - 1], {i, M - 1}});
    visited[i][0] = visited[i][M - 1] = true;
  }
  // {3, {0, 1}}, {4, {0, 2}} （最初の行の上端）
  // {5, {3, 1}}, {2, {3, 2}} （最後の行の下端）
  for (int j = 1; j < M - 1; ++j)
  {
    pq.push({height[0][j], {0, j}});
    pq.push({height[N - 1][j], {N - 1, j}});
    visited[0][j] = visited[N - 1][j] = true;
  }

  int result = 0;
  while (!pq.empty())
  {
    // 最も低い高さ取得後、除く
    // 高さ:位置x,y、pair<int, pair<int, int>>
    auto [h, pos] = pq.top();
    pq.pop();
    int x = pos.first, y = pos.second;

    // 上下左右
    for (int i = 0; i < 4; ++i)
    {
      int nx = x + dx[i], ny = y + dy[i];

      // 探索位置が範囲内かつ未訪問であるか確認
      if (nx >= 0 && nx < N && ny >= 0 && ny < M && !visited[nx][ny])
      {
        visited[nx][ny] = true;
        // 現在の壁の高さと隣接ブロックの高さの差分 = 水の量
        result += max(0, h - height[nx][ny]);
        // 隣接ブロックを次の処理のためにキューに追加。高さは現在の壁か隣接ブロックの高さの大きい方
        pq.push({max(h, height[nx][ny]), {nx, ny}});
      }
    }
  }

  cout << result << endl;

  return 0;
}
