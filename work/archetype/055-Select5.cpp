#include <iostream>
using namespace std;

int main()
{
    long long N, P, Q;
    long long A[109];
    cin >> N >> P >> Q;
    int count = 0;
    for (int i = 0; i < N; i++)
        cin >> A[i];

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < i; ++j)
        {
            for (int k = 0; k < j; ++k)
            {
                for (int l = 0; l < k; ++l)
                {
                    for (int m = 0; m < l; ++m)
                    {
                        if (1LL * A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P == Q)
                        {
                            ++count;
                        }
                    }
                }
            }
        }
    }
    cout << count << endl;
    return 0;
}