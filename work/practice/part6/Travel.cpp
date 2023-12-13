#include <iostream>
using namespace std;

int N, K;

int main()
{
    cin >> N >> K;
    int a = N * 2 - 2;
    if (a <= K && K % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    else
    {
        cout << "No" << endl;
    }
    return 0;
}