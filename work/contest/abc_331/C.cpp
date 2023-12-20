#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;

int main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    vector<int> b(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> a[i];
        b[i] = a[i];
    }
    // 昇順
    sort(b.begin(), b.end());
    vector<ll> s(n + 1);
    // 累積和
    s[0] = 0;
    for (int i = 0; i < n; ++i)
    {
        s[i + 1] = s[i] + b[i];
    }

    for (int i = 0; i < n; ++i)
    {
        // 二部探索
        auto it = upper_bound(b.begin(), b.end(), a[i]);
        // 累積和の
        // it - b.begin() : この式はイテレータ it とベクター b の開始イテレータb.begin() の間の距離を計算します。
        // この距離は、b 内の a[i] より大きい最初の要素のインデックスに相当します。
        cout << s[n] - s[it - b.begin()] << " \n"[i == n - 1];
    }

    return 0;
}