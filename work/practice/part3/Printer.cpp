#include <iostream>
using namespace std;

long long N, K;
long long A[100009];
bool check(long long x)
{
    long long sum = 0;
    for (long long i = 1; i <= N; i++)
        sum += x / A[i];
    if (sum >= K)
        return true;
    return false;
}
int main()
{
    cin >> N >> K;
    for (long long i = 1; i <= N; i++)
        cin >> A[i];
    long long left = 1;
    long long right = 1000000000;

    while (left < right)
    {
        long long mid = (left + right) / 2;
        bool ans = check(mid);
        if (ans == false)
            left = mid + 1;
        if (ans == true)
            right = mid;
    }
    cout << left << endl;
    return 0;
}