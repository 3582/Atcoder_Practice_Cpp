#include <iostream>
#include <vector>
#include <queue>
using namespace std;
using Graph = vector<vector<int>>;

int main()
{
    int n;
    cin >> n;
    Graph graph(n);
    for (int i = 0; i < n; ++i)
    {
        int u, k;
        cin >> u >> k;
        --u;
        for (int j = 0; j < k; ++j)
        {
            int v;
            cin >> v;
            --v;
            graph.at(u).push_back(v);
        }
    }

    // dist[v] はスタート頂点から頂点vまで何ステップで到達できるかを表す
    // 全頂点を「未訪問」:-1に初期化
    vector<int> dist(n, -1);
    // 発見済みだが未訪問な頂点を格納するキュー
    queue<int> que;
    // 初期条件 (頂点 0 を初期ノードとする)
    dist.at(0) = 0;
    // 0を訪問予定
    que.push(0);
    // BFS
    while (!que.empty())
    {
        // キューから先頭頂点を取り出す
        int u = que.front();
        que.pop();
        // v から辿れる頂点をすべて調べる
        for (int v : graph.at(u))
        {
            // すでに発見済みの頂点は探索しない
            if (dist.at(v) != -1)
                continue;
            // 新たな未発見の頂点v について距離情報を更新してキューに追加する
            dist.at(v) = dist.at(u) + 1;
            que.push(v);
        }
    }
    // 結果出力 (各頂点の頂点 0 からの距離を見る)
    for (int u = 0; u < n; ++u)
        cout << u + 1 << " " << dist.at(u) << endl;
}
