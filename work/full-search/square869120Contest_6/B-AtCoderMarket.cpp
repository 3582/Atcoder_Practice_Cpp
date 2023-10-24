#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

long long N, A[100], B[100], minx = (1LL << 60);
long long solve(int p1, int p2)
{
    long long V1 = 0;
    for (int i = 1; i <= N; i++)
    {
        // 入り口p1-Aのマスの絶対値(入り口からAのマスにかかる秒数)
        V1 += abs(p1 - A[i]);
        // A-Bのマスの絶対値
        V1 += abs(A[i] - B[i]);
        // B-出口のマスの絶対値
        V1 += abs(B[i] - p2);
    }
    // 結果の秒数
    return V1;
}

int main()
{
    cin >> N;
    for (int i = 1; i <= N; i++)
        cin >> A[i] >> B[i];

    vector<long long> E;
    for (int i = 1; i <= N; i++)
        E.push_back(A[i]);
    for (int i = 1; i <= N; i++)
        E.push_back(B[i]);

    for (long long v1 : E)
    {
        for (long long v2 : E)
        {
            minx = min(minx, solve(v1, v2));
        }
    }
    cout << minx << endl;
    return 0;
}