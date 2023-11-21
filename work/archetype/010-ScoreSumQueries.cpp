#include <iostream>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

int main()
{
    // N 人の生徒
    int N;
    std::cin >> N;

    // 1 組生徒の点数の累積和
    // c1[0],c2[0]
    std::vector<int> c1 = {0};
    // 2 組生徒の点数の累積和
    std::vector<int> c2 = {0};

    // 7
    // 1 72
    // 2 78
    // 2 94
    // 1 23
    // 2 89
    // 1 40
    // 1 75
    // 1
    // 2 6
    // 累積和を構築
    for (int i = 0; i < N; ++i)
    {
        // C 組, P 点
        int C, P;
        std::cin >> C >> P;

        if (C == 1) // 1 組なら
        {
            // [0,72,72,72,72+23,95,95+40,135+75]
            c1.push_back(c1.back() + P);
            c2.push_back(c2.back());
        }
        else // 2 組なら
        {
            // [0,0,78,78+94,172,172+89,261,261]
            c1.push_back(c1.back());
            c2.push_back(c2.back() + P);
        }
    }

    // 1
    // 2 6
    // Q 個の質問
    int Q;
    std::cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        // L ～ R 番
        int L, R;
        std::cin >> L >> R;

        // [0,72,72,72,72+23,95,95+40,135+75]
        // [0,0,78,78+94,172,172+89,261,261]
        // 1 組の L ～ R 番の合計
        // [6]:135 - [1]:72 = 63
        const int a1 = (c1[R] - c1[L - 1]);

        // 2 組の L ～ R 番の合計
        // [6]:261 - [1]:0 = 261
        const int a2 = (c2[R] - c2[L - 1]);

        // 解答を出力
        std::cout << a1 << ' ' << a2 << '\n';
    }
}