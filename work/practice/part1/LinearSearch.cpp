#include <iostream>
using namespace std;
int main()
{
    int N, X;
    cin >> N >> X;
    for (int i = 0; i < N; i++)
    {
        int A;
        cin >> A;
        // 計算量O(N)
        if (A == X)
        {
            cout << "Yes" << endl;
            return 0;
        }
    }
    cout << "No" << endl;
    return 0;
}