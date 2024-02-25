#include <iostream>
using namespace std;

int main()
{
    int N;
    cin >> N;
    long long result = 0;

    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;
        result += num;
        if (result < 0)
        {
            result = 0;
        }
    }
    cout << result << endl;

    return 0;
}