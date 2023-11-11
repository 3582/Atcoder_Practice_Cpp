#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

void dfs(const Graph &graph, vector<bool> &seen, vector<int> &counter, int u)
{
    // [0] [1]
    // [1] [0,2,3]
    // [2] [1]
    // [3] [1]
    // 道の情報,探索済[boolean],操作[100,10,1],始点
    seen.at(u) = true;
    // v:1,u:0
    // 0を探索済とする
    // 頂点1:10 + 100 = 110

    // v:0,u:1
    // 1を探索済とする
    // seen=true

    // v:2,u:1
    // 1を探索済とする
    // 頂点2:1 + 110 = 111

    // v:1,u:2
    // 2を探索済とする
    // seen=true

    // v:3,u:1
    // 1を探索済とする
    // 頂点3:0 + 110 = 110

    // v:1,u:3
    // seen=true

    // [100,110,111,110]
    for (int v : graph.at(u))
    {
        if (seen.at(v))
            continue;
        counter.at(v) += counter.at(u);
        dfs(graph, seen, counter, v);
    }
}

int main()
{
    int N, Q;
    cin >> N >> Q;
    Graph graph(N);
    int a, b;
    // 道の情報受け取り
    // [0] [1]
    // [1] [0,2,3]
    // [2] [1]
    // [3] [1]
    for (int i = 0; i < N - 1; ++i)
    {
        cin >> a >> b;
        --a;
        --b;
        graph.at(a).push_back(b);
        graph.at(b).push_back(a);
    }
    vector<int> counter(N, 0);
    int p, x;
    // 1 10
    // 0 100
    // 2 1
    // [100,10,1]
    for (int j = 0; j < Q; ++j)
    {
        cin >> p >> x;
        --p;
        // 頂点
        counter.at(p) += x;
    }
    vector<bool> seen(N, false);
    dfs(graph, seen, counter, 0);
    cout << counter.at(0);
    for (int i = 1; i < N; ++i)
        cout << " " << counter.at(i);
    cout << endl;
}
