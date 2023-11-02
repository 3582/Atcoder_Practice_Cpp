#include <iostream>
#include <bits/stdc++.h>
#include <algorithm>
#include <cstdlib>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> P_vec(n);
    for (int i = 0; i < n; ++i)
        cin >> P_vec.at(i);
    vector<int> Q_vec(n);
    for (int i = 0; i < n; ++i)
        cin >> Q_vec.at(i);

    vector<int> indices(n);
    // indices = [1,2,,,,n]
    iota(indices.begin(), indices.end() + 1, 1);
    int a = 0;
    int b = 0;
    int count = 1;
    do
    {
        // 配列一致確認
        if (
            P_vec.size() == indices.size() &&
            std::equal(P_vec.cbegin(), P_vec.cend(), indices.cbegin()))
        {
            a = count;
        }
        if (
            Q_vec.size() == indices.size() &&
            std::equal(Q_vec.cbegin(), Q_vec.cend(), indices.cbegin()))
        {
            b = count;
        }
        // 配列内の順番
        count++;
    } while (next_permutation(indices.begin(), indices.end()));

    // 絶対値
    cout << std::abs(a - b) << endl;

    return 0;
}