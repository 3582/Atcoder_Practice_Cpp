#include <iostream>
#include <cmath>
#include <vector>
using namespace std;

int main()
{
    // 長さ N の整数列, ちょうど K 回の操作
    int N, K;
    cin >> N >> K;

    // 整数列 A
    vector<int> A(N);
    for (auto &a : A)
    {
        cin >> a;
    }

    // 整数列 B
    vector<int> B(N);
    for (auto &b : B)
    {
        cin >> b;
    }

    // 整数列 A を B に一致させるために必要な操作回数
    int count = 0;
    for (int i = 0; i < N; ++i)
    {
        count += abs(A[i] - B[i]);
    }

    if (K - count > 0 && (K - count) % 2 == 0)
    {
        cout << "Yes" << endl;
    }
    cout << "No" << endl;

    return 0;
}