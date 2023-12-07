#include <iostream>
using namespace std;
int main()
{
    int N, K, ans;
    cin >> N >> K;
    for (int i = 1; i <= N; i++)
    {
        for (int j = 1; j <= N; j++)
        {
            int z = K - i - j;
            if (z <= N && z >= 1)
            {
                ans += 1;
            }
        }
    }

    cout << ans << endl;
    return 0;
}