#include <iostream>
using namespace std;

int GCD(int a, int b)
{
    while (a >= 1 && b >= 1)
    {
        if (a >= b)
        {
            a = a % b;
        }
        else
        {
            b = b % a;
        }
    }
    if (a == 0)
        return b;
    return a;
}
int main()
{
    int A, B;
    cin >> A >> B;
    cout << GCD(A, B) << endl;
    return 0;
}