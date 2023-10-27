#include <iostream>
using namespace std;
int main()
{
    // N 個の スイッチと、M 個の電球
    int n, m, k[11], s[11][11], p[11], result = 0;
    cin >> n >> m;
    for (int i = 1; i <= m; i++)
    {
        // k[i], k[1]=1番目の電球につながっているスイッチの数
        cin >> k[i];

        for (int j = 1; j <= k[i]; j++)
        {
            // s[i][j] = i番目の電球で使用するスイッチの番号
            cin >> s[i][j];
        }
    }
    for (int i = 1; i <= m; i++)
    {
        // 0 or 1
        cin >> p[i];
    }

    // 各電球のスイッチの状態は要素数nの部分集合となっている。
    // スイッチを選択している状態の全パターン数、(1<<n)は2^n
    for (int msk = 0; msk < (1 << n); msk++)
    {
        int lightCount = 0;
        // 電球の数(電球の番号)、i=何番目の電球
        for (int i = 1; i <= m; i++)
        {
            int on = 0;
            // k[1]=1番目の電球につながっているスイッチの数
            for (int j = 1; j <= k[i]; j++)
            {
                // msk=調査中のスイッチを選択している状態、ex:01
                // s[1][1]=1番目の電球で使用するj番のスイッチ:1 - 1(シフト位置調整)
                // ex:1 << 1 - 1 = 01, 1 << 2 -1 = 10
                // アンド演算
                // msk = 00(off,off),01(off,on),10,11 & 01(一番目のスイッチがON),10,11
                if (msk & (1 << (s[i][j] - 1)))
                    on++;
            }
            // i番目の電球のスイッチがonである数が偶数か奇数か = 点灯p[i]:0or1
            if (on % 2 == p[i])
            {
                lightCount++;
            }
        }
        // ONになっている電球の数が全ての電球と等しい
        if (lightCount == m)
            result++;
    }

    cout << result << endl;
    return 0;
}