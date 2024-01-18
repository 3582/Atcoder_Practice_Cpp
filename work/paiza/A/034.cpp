// TODO
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int calculateHeight(int i, vector<vector<int>> &arr_cin, vector<vector<int>> &index)
{
    int tmp_h = arr_cin[i][0];
    for (int j = 0; j < index[i].size(); j++)
    {
        tmp_h += calculateHeight(index[i][j], arr_cin, index);
    }
    return tmp_h;
}

int main()
{
    int N;
    cin >> N;
    vector<vector<int>> arr_cin(N, vector<int>(3));
    vector<vector<int>> index(N, vector<int>());

    for (int i = 0; i < N; i++)
    {
        cin >> arr_cin[i][0] >> arr_cin[i][1] >> arr_cin[i][2];
    }

    for (int i = 0; i < N; i++)
    {
        int arr_pre[2] = {arr_cin[i][1], arr_cin[i][2]};
        for (int j = 0; j < N; j++)
        {
            if (i == j)
                continue;
            bool ok = false;
            if (arr_cin[j][1] <= arr_pre[0] && arr_cin[j][2] <= arr_pre[1])
                ok = true;
            if (arr_cin[j][2] <= arr_pre[0] && arr_cin[j][1] <= arr_pre[1])
                ok = true;
            if (ok)
                index[i].push_back(j);
        }
    }
    int ans_h = 0;
    for (int i = 0; i < N; i++)
    {
        ans_h = max(ans_h, calculateHeight(i, arr_cin, index));
    }

    cout << ans_h << endl;
    // 0 [2 4 5]
    // 1 [1 7 7]
    // 2 [4 5 5]
    // 3 [5 1 6]
    //
    // 0 []
    // 1 [0 2 3]
    // 2 [0]
    // 3 []

    return 0;
}