#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> S_vec(n);
    for (int i = 0; i < n; ++i)
        cin >> S_vec.at(i);
    int q;
    cin >> q;
    vector<int> T_vec(q);
    for (int i = 0; i < q; ++i)
        cin >> T_vec.at(i);

    int cnt = 0;
    for (int i = 0; i < q; ++i)
    {
        // lower_boundは、探索したいkey以上のイテレータを返す
        // lower_bound(始点、終端、検索する値)
        if (*lower_bound(S_vec.begin(), S_vec.end(), T_vec.at(i)))
            cnt++;
    }
    cout << cnt << endl;
}