#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n, x[10], y[10];
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i] >> y[i];
    }

    // 可変長配列
    vector<int> indices(n);
    // indices = [0,1,,,,n-1]
    iota(indices.begin(), indices.end(), 0);
    // 総距離
    double cnt = 0, total_distance = 0;
    do
    {
        double tmp_distance = 0;
        // 街の数
        for (int i = 0; i < n - 1; i++)
        {
            // 現在地→移動地点
            int now = indices[i], next = indices[i + 1];
            // 距離の式
            // square root 平方根
            // pow べき乗
            tmp_distance += sqrt(pow(x[next] - x[now], 2) + pow(y[next] - y[now], 2));
        }
        // パターン数加算
        cnt++;
        // 総距離加算
        total_distance += tmp_distance;
        // [1, 2, 3]配列、next_permutation()関数を5回呼び出す場合、
        // indices = [1, 2, 3] → [1, 3, 2] → [2, 1, 3] → [2, 3, 1] → [3, 1, 2] → [3, 2, 1]
    } while (next_permutation(indices.begin(), indices.end()));

    printf("%.10f\n", total_distance / cnt);

    return 0;
}