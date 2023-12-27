#include <iostream>

using namespace std;
int main()
{
    int N, L, ans;
    cin >> N >> L;
    for (int i = 1; i <= N; i++)
    {
        int A = 0;
        cin >> A;
        if (A >= L)
        {
            ans++;
        }
    }
    cout << ans << endl;

    return 0;
}