#include <iostream>
using namespace std;
int main()
{
    int ans = 0;
    int N, X;
    cin >> N >> X;
    int S;
    for (int i = 0; i < N; i++)
    {
        cin >> S;
        if (S <= X)
        {
            ans += S;
        }
    }
    cout << ans << endl;
    return 0;
}