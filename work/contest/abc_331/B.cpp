#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>

using namespace std;

int main()
{
    int N, S, M, L;
    cin >> N >> S >> M >> L;

    // 卵の数がNを超えるまでの最小コストを格納する配列
    vector<int> dp(N + 12, INT_MAX); // N + 12まで考慮（12個パックのため）
    dp[0] = 0;                       // 0個の卵のコストは0円

    // 各卵の数に対して、最小コストを計算
    for (int i = 0; i < N; ++i)
    {
        if (dp[i] != INT_MAX)
        {
            if (i + 6 <= N + 11)
                dp[i + 6] = min(dp[i + 6], dp[i] + S);
            if (i + 8 <= N + 11)
                dp[i + 8] = min(dp[i + 8], dp[i] + M);
            if (i + 12 <= N + 11)
                dp[i + 12] = min(dp[i + 12], dp[i] + L);
        }
    }

    // N個以上の卵を購入するための最小コストを見つける
    int result = *min_element(dp.begin() + N, dp.end());

    cout << result << endl;

    return 0;
}
