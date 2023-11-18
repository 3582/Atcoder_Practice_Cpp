#include <iostream>
using namespace std;
int main()
{
    int N;
    cin >> N;
    int max = 1;
    int ans = 1;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        if (max < A)
        {
            ans = max;
            max = A;
        }
        else if (max != A && ans < A)
        {
            ans = A;
        }
    }

    cout << ans << endl;
    return 0;
}