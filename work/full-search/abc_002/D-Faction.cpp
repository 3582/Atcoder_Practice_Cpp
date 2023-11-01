#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;
    // g++ -o D-Faction D-Faction.cpp -std=c++14
    vector<vector<int>> graph(12, vector<int>(12));

    for (int i = 0; i < m; i++)
    {
        // 「関係が存在する」二次元配列にフラグ（1）を立てる
        // 1 2
        int x, y;
        cin >> x >> y;
        // 配列は0スタートだから毎回デクリメント
        x--;
        y--;
        // 議員番号1番と2番の関係が成立する
        // [0][1] = 1
        // [1][0] = 1
        graph[x][y] = 1;
        graph[y][x] = 1;
    }

    int ans = 1;
    // 議員数の可能な派閥全パターン
    for (int mask = 0; mask < (1 << n); mask++)
    {
        vector<int> as;
        for (int i = 0; i < n; i++)
        {
            // 議員数(桁)繰り返す
            // 繰り返しているパターンの議員番号を格納
            // ※デクリメントしているため0始まり
            // 1 & (011 >> 0) → as[0],,,as[0,1]
            if (1 & (mask >> i))
                as.push_back(i);
        }

        bool ok = true;
        // 　
        for (auto i : as)
        {
            for (auto j : as)
            {
                if (i == j)
                    continue;
                // 入力の派閥のパターン互いに知り合いか確認
                // graph[0][1]
                // graph[1][0]
                if (graph[i][j] != 1)
                    ok = false;
            }
        }

        // 成立する人数を更新
        if (ok)
            ans = max(ans, (int)as.size());
    }
    cout << ans << endl;
}