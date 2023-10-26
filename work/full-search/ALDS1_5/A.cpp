#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> A_vec(n);
    for (int i = 0; i < n; ++i)
        cin >> A_vec.at(i);

    bool feasible[40001] = {};
    for (int i = 0; i < (1 << n); ++i)
    {
        bitset<20> bit(i);
        int sum = 0;
        for (int j = 0; j < n; ++j)
        {
            if (bit.test(j))
                sum += A_vec.at(j);
        }
        feasible[sum] = true;
    }

    int q;
    cin >> q;
    int m;
    for (int i = 0; i < q; ++i)
    {
        cin >> m;
        if (feasible[m])
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }
}