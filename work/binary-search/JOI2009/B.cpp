#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    // 環状線の全長:8
    // 店舗の個数:3
    // 注文の個数:2
    long long d, n, m;
    cin >> d >> n >> m;
    // 店舗の個数+1[0,0,0,0]
    vector<long long> dn_vec(n + 1, 0);
    for (int i = 1; i < n; ++i)
        // 本店以外の店舗の位置:3,1
        // [0,3,1,0]
        cin >> dn_vec[i];
    // [0,3,1,8]
    dn_vec[n] = d;
    // [0,1,3,8]
    sort(dn_vec.begin(), dn_vec.end());

    long long res = 0;
    for (int i = 0; i < m; ++i)
    {
        // 宅配先の場所:4,6
        long long k;
        cin >> k;
        // lower_bound(始点、終端、検索する値)
        // lower_boundは、探索したいkey以上の一番左側のイテレータを返す
        // lower_boundのイテレータから先頭のイテレータを引くと、keyより小さい要素の個数を求めることができる
        // →keyがどの要素とどの要素との間にあるのかを把握=it

        // [0,1,3,8] 4,3番目のイテレータ 6,3番目のイテレータ - 先頭のイテレータ
        int it = lower_bound(dn_vec.begin(), dn_vec.end(), k) - dn_vec.begin();

        // dn_vec[it]※0から数えてるためkeyの位置の次
        // 8-4=|4|,8-6=|2|
        long long tmp = abs(dn_vec[it] - k);

        if (it > 0)
            // dn_vec[it]※0から数えてるためkeyの位置の手前
            // →keyの位置の前後から数えた際の最短距離
            // min(4, dn_vec[2]:3 - 4 = |-1|)
            // min(2, dn_vec[2]:3 - 6 = |-3|)
            tmp = min(tmp, abs(dn_vec[it - 1] - k));
        // 1+2
        res += tmp;
    }
    cout << res << endl;
}