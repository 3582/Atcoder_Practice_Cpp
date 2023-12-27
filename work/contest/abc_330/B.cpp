#include <iostream>
#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N, L, R;
    cin >> N >> L >> R;
    for (int i = 1; i <= N; i++)
    {
        int A = 0;
        cin >> A;
        cout << clamp(A, L, R) << " \n"[i == N];
    }

    return 0;
}