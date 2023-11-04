#include <iostream>
using namespace std;
int main()
{
    unsigned long long B;
    cin >> B;
    for (int i = 1; i <= B; i++)
    {
        unsigned long long result = 1;
        for (int j = 0; j < i; j++)
            result *= i;

        if (result == B)
        {
            cout << i << endl;
            return 0;
        }
        else if (result > B)
        {
            break;
        }
    }

    cout << -1 << endl;
    return 0;
}