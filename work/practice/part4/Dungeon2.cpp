#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int N, A[100000], B[100000], dp[100000];
vector<int> Answer;

int main()
{
    cin >> N;
    for (int i = 2; i <= N; i++)
        cin >> A[i];
    for (int i = 3; i <= N; i++)
        cin >> B[i];

    // 動的計画、最短時間
    dp[1] = 0;
    dp[2] = A[2];
    for (int i = 3; i <= N; i++)
    {
        dp[i] = min(dp[i - 1] + A[i], dp[i - 2] + B[i]);
    }

    // ゴール地点から進む
    int Place = N;
    while (true)
    {
        // ゴール地点からの移動経路
        Answer.push_back(Place);
        if (Place == 1)
            break;

        // 手前の地点の最短時間+方法Aの時間が最短時間かどうか
        if (dp[Place - 1] + A[Place] == dp[Place])
        {
            Place -= 1;
        }
        else
        {
            Place -= 2
        }
    }

    reverse(Answer.begin(), Answer.end());
    cout << Answer.size() << endl;
    for (int i = 0; i < Answer.size(); i++)
    {
        if (i >= 1)
            cout << " ";
        cout << Answer[i];
    }

    cout << endl;
    return 0;
}