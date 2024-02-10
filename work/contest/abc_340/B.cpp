#include <iostream>
#include <vector>

using namespace std;
int main()
{
    int Q;
    cin >> Q;
    vector<vector<int>> v(Q, vector<int>(2));
    vector<int> ans;
    for (int i = 0; i < Q; i++)
    {
        cin >> v[i][0] >> v[i][1];
    }

    for (int i = 0; i < Q; i++)
    {
        if (v[i][0] == 1)
        {
            ans.push_back(v[i][1]);
        }
        if (v[i][0] == 2)
        {
            cout << ans[ans.size() - v[i][1]] << endl;
        }
    }

    return 0;
}