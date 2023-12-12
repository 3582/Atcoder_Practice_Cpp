#include <iostream>
using namespace std;
int main()
{
    int D, N, S[100000], L[100000], R[100000], ans[100000];
    // D日間、N人
    // i番目の人間がL日からR日まで
    cin >> D >> N;
    for (int i = 1; i <= N; i++)
    {
        cin >> L[i] >> R[i];
    }
    // 前日比
    S[0] = 0;
    for (int i = 1; i <= N; i++)
    {
        S[L[i]] += 1;
        S[R[i] + 1] -= 1;
    }

    ans[0] = 0;
    for (int i = 1; i <= D; i++)
    {
        ans[i] = ans[i - 1] + S[i];
    }

    for (int i = 1; i <= D; i++)
    {
        cout << ans[i] << endl;
    }

    return 0;
}