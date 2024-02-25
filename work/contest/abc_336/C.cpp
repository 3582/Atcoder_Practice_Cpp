#include <iostream>

using namespace std;

bool isGoodNumber(long long n)
{
    while (n > 0)
    {
        long long digit = n % 10;
        if (digit % 2 != 0)
            return false;
        n /= 10;
    }
    return true;
}

long long findNthGoodNumber(long long N)
{
    long long count = 0;
    for (long long i = 0;; i += 2)
    {
        if (isGoodNumber(i))
        {
            ++count;
            if (count == N)
                return i;
        }
    }
}

int main()
{
    long long N;
    cin >> N;

    long long result = findNthGoodNumber(N);
    cout << result << endl;

    return 0;
}
