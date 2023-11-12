#include <iostream>
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
    vector<int> dist(n, -1);
    queue<int> que;
    dist.at(0) = 0;
    que.push(0);
    while (!que.empty())
    {
        int u = que.front();
        que.pop();
        for (int v : graph.at(u))
        {
            if (dist.at(v) != -1)
                continue;
            dist.at(v) = dist.at(u) + 1;
            que.push(v);
        }
    }
    for (int u = 0; u < n; ++u)
        cout << u + 1 << " " << dist.at(u) << endl;
}
