#include <iostream>
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> G;
vector<int> ans;

void dfs(int crr, int pre)
{
    // DFS(今いる町,前にいた町)
    ans.push_back(crr);
    // nxt=今いる町から行ける町
    for (int nxt : G[crr])
        // もしnxtが前にいた町と違うなら、更に先へ探索する
        if (nxt != pre)
        {
            dfs(nxt, crr);
            ans.push_back(crr);
        }
}

int main()
{
    int N;
    cin >> N;
    G.resize(N + 1);
    // 道の情報受け取り
    // G[2]=[1,4]ならば2と1,4がつながっている
    for (int i = 0; i < N - 1; i++)
    {
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    // 小さい順に回るからソート
    for (int i = 1; i <= N; i++)
        sort(G[i].begin(), G[i].end());

    dfs(1, -1);
    for (int i = 0; i < ans.size(); i++)
    {
        if (i > 0)
            cout << ' ';
        cout << ans[i];
    }
}