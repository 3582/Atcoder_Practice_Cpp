#include <iostream>
#include <cmath>
using namespace std;

int N, X[159], Y[159];
// 訪れる順番
int P[159];
// visited[i]=trueの時、都市iを訪問した
bool visited[159];

double GetDistance(int p, int q)
{
    // √(Xi-Xj)^2+(Yi-Yj)^2
    return sqrt((X[p] - X[q]) * (X[p] - X[q]) + (Y[p] - Y[q]) * (Y[p] - Y[q]));
}

void PlayGreedy()
{
    // 配列の初期化
    int CurrentPlace = 1;
    for (int i = 1; i <= N; i++)
        visited[i] = false;
    P[1] = 1;
    visited[1] = true;

    // 貪欲法
    for (int i = 2; i <= N; i++)
    {
        // 距離の最小
        double MinDist = 10000.0;
        // 次はどの都市に移動するか
        int Min_ID = -1;
        // 距離が最小となる都市を探す
        for (int j = 1; j <= N; j++)
        {
            if (visited[j] == true)
                continue;
            double NewDist = GetDistance(CurrentPlace, j);
            if (MinDist > NewDist)
            {
                MinDist = NewDist;
                Min_ID = j;
            }
        }
        // 現在位置の更新
        visited[Min_ID] = true;
        P[i] = Min_ID;
        CurrentPlace = Min_ID;
    }
    // 最後
    P[N + 1] = 1;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> X[i] >> Y[i];
    }
    PlayGreedy();
    for (int i = 1; i <= N + 1; i++)
    {
        cout << P[i] << endl;
    }

    return 0;
}