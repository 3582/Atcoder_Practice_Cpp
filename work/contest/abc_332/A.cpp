#include <iostream>
using namespace std;

int main()
{
    int N, S, K;
    int P[109], Q[109];
    cin >> N >> S >> K;
    for (int i = 1; i <= N; i++)
        cin >> P[i] >> Q[i];

    int ans = 0;
    for (int i = 1; i <= N; i++)
        ans += P[i] * Q[i];
    if (ans < S)
        ans += K;

    cout << ans << endl;
    return 0;
}