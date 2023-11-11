#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int ans = 0;
    int N;
    cin >> N;
    vector<int> D(N + 1);
    for (int i = 1; i <= N; ++i)
        cin >> D.at(i);

    for (int i = 1; i <= N; i++)
    {
        string month = std::to_string(i);
        for (int j = 1; j <= D.at(i); j++)
        {
            string day = std::to_string(j);
            vector<char> result_vec(day.length() + month.length());
            for (int k = 0; k < month.length(); k++)
            {
                result_vec.at(k) = month[k];
            }
            for (int k = 0; k < day.length(); k++)
            {
                result_vec.at(k + month.length()) = day[k];
            }

            bool res = true;
            for (int k = 1; k < result_vec.size(); ++k)
            {
                if (result_vec.at(k) != result_vec.at(0))
                {
                    res = false;
                }
            }
            if (res)
                ans++;
        }
    }

    cout << ans << endl;
    return 0;
}

// #include <iostream>
// #include <vector>
// #include <set>

// using namespace std;

// int main() {
//     int N;
//     cin >> N;
//     vector<int> D(N);
//     for (auto &&d : D)
//         cin >> d;

//     int ans = 0;
//     for (int m = 1; m <= N; ++m) {
//         string month = to_string(m);
//         for (int d = 1; d <= D[m - 1]; ++d) {
//             string date = month + to_string(d);
// 文字列内の全ての文字列が一種類の場合のみ
//             if (size(set<char>(date.begin(), date.end())) == 1)
//                 ++ans;
//         }
//     }
//     cout << ans << endl;

//     return 0;
// }
